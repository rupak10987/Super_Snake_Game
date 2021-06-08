#pragma once
#include"SDL.h"
#include"string.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"iostream"
#include"time.h"
#include"SDL_mixer.h"
#include"Math.h"
using namespace std;
#include"SDL_image.h"
class GAME
{
public:
	int priority;
	int currentskin = 2;
	void set_priority(int s_skin);
	int setbuydata(int c);
	void setcurrentskindata(int c);
	int skin_in_file;
	int filetokenamount;
	int shopfunction();
	void triplepower();
	void setscorerect(SDL_Rect r);
	void print_score(SDL_Texture* number, int n);
	int ready_score_for_print(int number);
	SDL_Texture* gettext(const char* str);
	void redheadrender();
	void gameover();
	bool pausequit = false;
	void reset();
	int score = 0;
	int menu(int n);
	int collision();
	void destroy();
	bool run;
	void setsnake();
	void upsnake(int cas);
	void upfrog();
	void uppower();
	void uppower2();
	int checkpower();
	int powerdelay();
	int eating();
	SDL_Texture* texload(const char* file);
	void initialize();
	int handle(int filetokenamount);
	void update();
	void output();
	void bejiupdate();
	void bejirender();
	void bomupdate();
	void bomrender();
	int bomcounter = -1;
private:
	SDL_Window* window;
	SDL_Renderer* render;
	struct dir
	{
		int x = 10;
		int y = 10;
	}direction;

	SDL_Rect rect[1000];
	SDL_Rect baby[3];
	SDL_Rect frog;
	SDL_Rect powerrect = { 100,100,10,10 };
	SDL_Rect powerrect2 = { 100,100,10,10 };
	SDL_Rect border[4];
	SDL_Rect textrect = { 12,12,50,12 };
	SDL_Rect num[10];
	SDL_Rect scorepop = { 540,25,24,22 };
	SDL_Rect timer = { 385,20,200,2 };
	SDL_Rect timerbox = { 380,15,205,20 };
	SDL_Rect nitroindicator = { 565,15,20,48 };
	SDL_Rect roundtimer = { 540,10,50,50 };
	SDL_Rect shoprect = { 530,10,50,60 };
	SDL_Rect coinrect = { 15,15,24,24 };
	SDL_Rect rarrow = { 410,260,50,80 };
	SDL_Rect larrow = { 140,260,50,80 };
	SDL_Rect skinpreview = { 200,200,200,200 };
	SDL_Rect gobackrect = { 552,15,35,20 };
	SDL_Rect buyrect = { 250,415,100,50 };
	SDL_Rect use_rect = { 250,160,100,30 };
	struct vec
	{
		float x;
		float y;
	};
	
	struct bejis
	{
		int bejidirection = 5;
		SDL_Rect vision = { 425,150,100,100 };
		SDL_Rect beji = { 450,100,50,50 };
		bool detection = true;
		bool detcount = false;
		int detcounter = 0;
	}beji1;
	struct bom
	{
		SDL_Rect bomrect;
		SDL_Rect blastrad;
		Vector2 bomvec;
		bool alive = true;
		int blast_frame = 0;
	}boms[100];
	SDL_Rect poisonrect = { 0,0,40,40 };
	SDL_Rect poisonmeterrect = { 20,500 + 80,10,0 };
	SDL_Rect poisonmeterborderrect = { 20,500,11,80 };
	int time = 60;
	bool powerround = false;
	bool powerplay = false;
	bool poison = false;
	int poisoncounter = 0;

	int blast_score_popdelay = 0;
};

