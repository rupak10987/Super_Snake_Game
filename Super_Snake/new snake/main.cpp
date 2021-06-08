#include"GAME.h"
#include"SDL.h"
#include"SDL_mixer.h"
#include"iostream"
#include"fstream"
#include"Math.h"
using namespace std;
int filetoken;
int menuoption = 0;//menu 0 for continuing menu, 1 for play, 2 for quit
int savehighscore(GAME game);
int main(int argc, char* argv[])
{
	fstream filehandle;
	srand(time(NULL));
	GAME game;
	game.initialize();
	while (1)
	{
		if (game.pausequit == true)
		{
			savehighscore(game);
			break;
		}
		savehighscore(game);
		filehandle.open("tokens.txt");
		filehandle >> game.filetokenamount;
		filehandle.close();
		SDL_ShowCursor(SDL_ENABLE);
		while (menuoption == 0)
		{
			menuoption = game.menu(0);
		}
		if (menuoption == 2)
		{
			savehighscore(game);
			break;
		}
		SDL_ShowCursor(SDL_DISABLE);
		while (game.run == true && menuoption == 1)
		{
			if (game.handle(filetoken) == 1)
			{
				menuoption = 2;
				savehighscore(game);
				break;
			}
			game.update();
			game.output();
			SDL_Delay(game.powerdelay());
		}
		if (menuoption == 2)
		{
			savehighscore(game);
			break;
		}
		savehighscore(game);
		SDL_Delay(1000);
		game.gameover();
		SDL_Delay(1500);
		menuoption = 0;
		game.reset();
	}
	game.destroy();
	return 0;
}
int savehighscore(GAME game)
{
	ofstream write;
	ifstream read;
	int temmporaryfilescore;
	read.open("highscore.txt");
	read >> temmporaryfilescore;
	read.close();
	read.open("tokens.txt");
	read >> filetoken;
	read.close();
	write.open("tokens.txt");
	filetoken = filetoken + game.score;
	write << filetoken;
	write.close();
	if (game.score > temmporaryfilescore)
	{
		temmporaryfilescore = game.score;
		write.open("highscore.txt");
		write << temmporaryfilescore;
		write.close();
	}
	write.open("current_skin.txt");
	write << game.currentskin;
	write.close();
	return temmporaryfilescore;
}