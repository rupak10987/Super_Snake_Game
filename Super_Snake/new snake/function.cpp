#include"GAME.h"
#include"SDL_mixer.h"
#include"fstream"
#include"Math.h"
using namespace std;

int probability = 0;;
int p = 3;//powerloop
int timetexvar = 8;//timetexvar is for timer of array varible;
int nitrotex = 11;
int dircheck = 0;
bool scorerender = false;//for speed power eating score
bool frogscorerender = false;//for frog eating score
int tripletime = 0;
bool tripleround = false;;
bool triplepowerplay = false;
bool click = false;
Uint32 triplecount = 0;
Uint32 frogscoretime = 0;
const	Uint8* state = SDL_GetKeyboardState(NULL);
Uint32 timenow = 0;
Uint32 powerplaytime = 0;
int shiftleft = 1;
Mix_Chunk* eateffect;
//Mix_Chunk* turneffect;
Mix_Chunk* deadeffect;
Mix_Chunk* selecteffect;
Mix_Chunk* clickeffect;
Mix_Chunk* powerroundeffect;
Mix_Chunk* powerupeffect;
Mix_Chunk* powerfinisheffect;
Mix_Chunk* missileeffect;
//Mix_Music* backgroundmusic;
SDL_Texture* goback;
SDL_Texture* gobackok;
SDL_Texture* highscoretex;
SDL_Texture* triplepowertex;
SDL_Texture* babyhead;
SDL_Texture* babybody;
SDL_Texture* timerr[9];
SDL_Texture* box;
SDL_Texture* powerbody;
SDL_Texture* power;
SDL_Texture* level;
SDL_Texture* numberletter[10];
SDL_Texture* bg;
SDL_Texture* f1;
SDL_Texture* shu;
SDL_Texture* shd;
SDL_Texture* shr;
SDL_Texture* shl;
SDL_Texture* shur;
SDL_Texture* shdr;
SDL_Texture* shlr;
SDL_Texture* shrr;
SDL_Texture* go;
SDL_Texture* s1[10];
SDL_Texture* s_preview[10];
SDL_Texture* tail1;
SDL_Texture* tail2;
SDL_Texture* borup;
SDL_Texture* bordown;
SDL_Texture* borright;
SDL_Texture* borleft;
SDL_Texture* menut;
SDL_Texture* menup;
SDL_Texture* menuq;
SDL_Texture* menupause;
SDL_Texture* menuppause;
SDL_Texture* menuqpause;
SDL_Texture* text;
SDL_Texture* plusthree;
SDL_Texture* minusthree;
SDL_Texture* plusone;
SDL_Texture* nitro[12];
SDL_Texture* shop;
SDL_Texture* shopzoom;
SDL_Texture* token;
SDL_Texture* shopbg;
SDL_Texture* shoprightarrow;
SDL_Texture* shoprightarrowzoom;
SDL_Texture* shopleftarrowzoom;
SDL_Texture* shopleftarrow;
SDL_Texture* traverseskin;
SDL_Texture* skin_in_use;
SDL_Texture* BUYABLE[10];
SDL_Texture* notbuyable;
SDL_Texture* inuse;
SDL_Texture* to_use;
SDL_Texture* lock[10];
SDL_Texture* BUYABLEOK[10];
SDL_Texture* bejitex[2];
SDL_Texture* visiontex[4];
SDL_Texture* bomtex;
SDL_Texture* blast_rad_tex;
SDL_Texture* poison_tex;
SDL_Texture* poison_meter_tex;
SDL_Texture* poison_meter_border_tex;
SDL_Texture* smoke_tex[14];
//pop_up things
SDL_Texture* pop_up_tex[6];
int pop_up_frame = -1;
SDL_Rect pop_up_rect = { 0,0,50,50 };
//
int PLAYOK = 1;
int QUITOK = 0;
int SHOPOK = 0;
int SHOPRIGHTOK = 0;
int SHOPLEFTOK = 0;
int ESCAPESHOP = 0;
int buyok = 0;
int buyingskin = 0;
int traverseok = 0;
int shopcurrentskin;

int c = 3;//c is for dir input case and t is for
void GAME::initialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048);
	eateffect = Mix_LoadWAV("eater.mp3");
	deadeffect = Mix_LoadWAV("fail.mp3");
	//turneffect = Mix_LoadWAV("move.mp3");
	clickeffect = Mix_LoadWAV("clicking.mp3");
	selecteffect = Mix_LoadWAV("select.wav");
	powerroundeffect = Mix_LoadWAV("8sectimer.mp3");
	powerupeffect = Mix_LoadWAV("pup.mp3");
	powerfinisheffect = Mix_LoadWAV("endpower.mp3");
	missileeffect = Mix_LoadWAV("missile.mp3");
	//backgroundmusic = Mix_LoadMUS("bgmusic.mp3");
	//Mix_PlayMusic(backgroundmusic, -1);
	run = false;
	window = SDL_CreateWindow("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, NULL);
	render = SDL_CreateRenderer(window, -1, 0);
	//numbers
	highscoretex = gettext("HIGHEST ");
	text = gettext("Score: ");
	plusthree = gettext("+3");
	minusthree = gettext("-3");
	plusone = gettext("+1");
	numberletter[0] = gettext("0");
	numberletter[1] = gettext("1");
	numberletter[2] = gettext("2");
	numberletter[3] = gettext("3");
	numberletter[4] = gettext("4");
	numberletter[5] = gettext("5");
	numberletter[6] = gettext("6");
	numberletter[7] = gettext("7");
	numberletter[8] = gettext("8");
	numberletter[9] = gettext("9");
	timerr[0] = texload("timer0.png");
	timerr[1] = texload("timer1.png");
	timerr[2] = texload("timer2.png");
	timerr[3] = texload("timer3.png");
	timerr[4] = texload("timer4.png");
	timerr[5] = texload("timer5.png");
	timerr[6] = texload("timer6.png");
	timerr[7] = texload("timer7.png");
	timerr[8] = texload("timer8.png");
	nitro[0] = texload("nitro0.png");
	nitro[1] = texload("nitro1.png");
	nitro[2] = texload("nitro2.png");
	nitro[3] = texload("nitro3.png");
	nitro[4] = texload("nitro4.png");
	nitro[5] = texload("nitro5.png");
	nitro[6] = texload("nitro6.png");
	nitro[7] = texload("nitro7.png");
	nitro[8] = texload("nitro8.png");
	nitro[9] = texload("nitro9.png");
	nitro[10] = texload("nitro10.png");
	nitro[11] = texload("nitro11.png");
	bg = texload("background.png");
	triplepowertex = texload("triple.png");
	babyhead = texload("baby0.png");
	babybody = texload("baby.png");
	powerbody = texload("sbpower.png");
	level = texload("level.png");
	power = texload("power.bmp");
	s1[0] = texload("sb.png");
	s1[1] = texload("sb1.png");
	s1[2] = texload("sb2.png");
	s1[3] = texload("sb3.png");
	s1[4] = texload("sb4.png");
	s1[5] = texload("sb5.png");
	s1[6] = texload("sb6.png");
	s1[7] = texload("sb7.png");
	s_preview[0] = texload("sp.png");
	s_preview[1] = texload("sp1.png");
	s_preview[2] = texload("sp2.png");
	s_preview[3] = texload("sp3.png");
	s_preview[4] = texload("sp4.png");
	s_preview[5] = texload("sp5.png");
	s_preview[6] = texload("sp6.png");
	s_preview[7] = texload("sp7.png");
	f1 = texload("frog.png");
	shu = texload("sbhu.png");
	shur = texload("sbhur.png");
	shd = texload("sbhd.png");
	shdr = texload("sbhdr.png");
	shl = texload("sbhl.png");
	shlr = texload("sbhlr.png");
	shr = texload("sbhr.png");
	shrr = texload("sbhrr.png");
	go = texload("gov.png");
	tail1 = texload("tail1.png");
	tail2 = texload("tail2.png");
	borup = texload("borderup.png");
	bordown = texload("borderdown.png");
	borleft = texload("borderleft.png");
	borright = texload("borderright.png");
	box = texload("box.png");
	menut = texload("menu.png");
	menup = texload("play.png");
	menuq = texload("quit.png");
	menupause = texload("menupause.png");
	menuppause = texload("playpause.png");
	menuqpause = texload("quitpause.png");
	shop = texload("shop.png");
	shopzoom = texload("shopzoom.png");
	shopbg = texload("shopbackground.png");
	shopleftarrow = texload("shopleftarrow.png");
	shopleftarrowzoom = texload("shopleftarrowzoom.png");
	shoprightarrowzoom = texload("shoprightarrowzoom.png");
	shoprightarrow = texload("shoprightarrow.png");
	token = texload("token.png");
	goback = texload("BACK.png");
	gobackok = texload("BACKOK.png");
	traverseskin = texload("traverseskin.png");
	skin_in_use = texload("skin_in_use.png");
	BUYABLE[2] = texload("BUYABLE2.png");
	BUYABLE[3] = texload("BUYABLE3.png");
	BUYABLE[5] = texload("BUYABLE5.png");
	notbuyable = texload("NOTBUYABLE.png");
	inuse = texload("IN_USE.png");
	to_use = texload("TO_USE.png");
	lock[2] = texload("LOCK2.png");
	lock[3] = texload("LOCK3.png");
	lock[5] = texload("LOCK5.png");
	BUYABLEOK[2] = texload("BUYABLEOK2.png");
	BUYABLEOK[3] = texload("BUYABLEOK3.png");
	BUYABLEOK[5] = texload("BUYABLEOK5.png");
	bejitex[0] = texload("beji_down.png");
	bejitex[1] = texload("beji_up.png");
	visiontex[0] = texload("vision_not_detected_down.png");
	visiontex[1] = texload("vision_not_detected_up.png");
	visiontex[2] = texload("vision_detected_down.png");
	visiontex[3] = texload("vision_detected_up.png");
	bomtex = texload("bom.png");
	blast_rad_tex = texload("bomrad.png");
	poison_tex = texload("poison.png");
	poison_meter_tex = texload("poison_meter.png");
	poison_meter_border_tex = texload("poison_meter_border.png");
	smoke_tex[0] = texload("smoke_textures/s0.png");
	smoke_tex[1] = texload("smoke_textures/s1.png");
	smoke_tex[2] = texload("smoke_textures/s2.png");
	smoke_tex[3] = texload("smoke_textures/s3.png");
	smoke_tex[4] = texload("smoke_textures/s4.png");
	smoke_tex[5] = texload("smoke_textures/s5.png");
	smoke_tex[6] = texload("smoke_textures/s6.png");
	smoke_tex[7] = texload("smoke_textures/s7.png");
	smoke_tex[8] = texload("smoke_textures/s8.png");
	smoke_tex[9] = texload("smoke_textures/s9.png");
	pop_up_tex[0] = texload("generate detection/s0.png");
	pop_up_tex[1] = texload("generate detection/s1.png");
	pop_up_tex[2] = texload("generate detection/s2.png");
	pop_up_tex[3] = texload("generate detection/s3.png");
	pop_up_tex[4] = texload("generate detection/s4.png");
	pop_up_tex[5] = texload("generate detection/s5.png");
	probability = rand() % 2;
	//load savefiles
	{
		fstream file;
		file.open("current_skin.txt");;
		file.seekg(0) >> shopcurrentskin;
		currentskin = shopcurrentskin;
		skin_in_file = currentskin;
		file.close();
		file.open("tokens.txt");
		file >> filetokenamount;
		file.close();
		file.open("priority.txt");
		file.seekg(currentskin * 2) >> priority;
		file.close();
	}
	setsnake();
}
void GAME::reset()
{
	nitrotex = 11;
	timetexvar = 8;
	p = 3;
	run = true;
	scorerender = false;
	frogscorerender = false;
	powerround = false;
	powerplay = false;
	frogscoretime = 0;
	cout << endl;
	direction.x = 10;
	direction.y = 10;
	c = 3;
	time = 60;
	score = 0;
	setsnake();
	shiftleft = 1;
	//triplepower resets
	tripletime = 0;
	tripleround = false;
	triplepowerplay = false;
	triplecount = 0;
	beji1.detcounter = 0;
	beji1.detcount = false;
	bomcounter = -1;
	for (int i = 0; i < 100; i++)
	{
		boms[i].alive = true;
	}
	poison = false;
	poisoncounter = 0;
	blast_score_popdelay = 0;
	poisonmeterrect = { 20,500 + 80,10,0 };
	poisonmeterborderrect = { 20,500,11,80 };
	poisonmeterrect.h = 0;
}
int GAME::menu(int n)
{

	int checkmusic;
	int x, y;
	int menuflag = 0;
	SDL_Event event2;
	if (SDL_PollEvent(&event2))
	{
		if (event2.type == SDL_QUIT)
		{
			run = false;
			SDL_Quit();
			menuflag = 2;
		}
		x = event2.motion.x;
		y = event2.motion.y;
		//play
		if (x >= 133 && x <= 446)
		{
			if (y >= 180 && y <= 273)
			{
				checkmusic = PLAYOK;
				PLAYOK = 1;
				if (checkmusic != PLAYOK)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				PLAYOK = 0;
			}
		}
		else
		{
			PLAYOK = 0;
		}
		//quit
		if (x >= 133 && x <= 446)
		{
			if (y >= 296 && y <= 389)
			{
				checkmusic = QUITOK;
				QUITOK = 1;
				if (checkmusic != QUITOK)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				QUITOK = 0;
			}
		}
		else
		{
			QUITOK = 0;
		}
		//SHOP
		if (n == 0)
		{
			if (x >= 530 && x <= 530 + 50)
			{
				if (y >= 15 && y <= 15 + 60)
				{
					checkmusic = SHOPOK;
					SHOPOK = 1;
					if (checkmusic != SHOPOK)
						Mix_PlayChannel(-1, selecteffect, 0);
				}
				else
				{
					SHOPOK = 0;
				}
			}
			else
			{
				SHOPOK = 0;
			}
		}
		if (event2.type == SDL_MOUSEBUTTONDOWN)
		{
			if (PLAYOK)
			{
				if (event2.button.button == SDL_BUTTON_LEFT)
				{
					run = true;
					menuflag = 1;
					Mix_PlayChannel(-1, clickeffect, 0);
				}
				else
				{
					run = false;
					menuflag = 0;
				}
			}
			if (QUITOK)
			{
				if (event2.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, clickeffect, 0);
					SDL_Delay(200);
					menuflag = 2;

				}
				else
					menuflag = 0;
			}
			if (SHOPOK)
			{
				if (event2.button.button == SDL_BUTTON_LEFT)
				{
					int shopquit = 0;
					Mix_PlayChannel(-1, clickeffect, 0);
					while (shopquit != 1)
					{
						shopquit = shopfunction();
						if (shopquit == 2)
						{
							menuflag = 2;
							break;
						}
					}

				}
			}

		}
		if (event2.type == SDL_QUIT)
		{
			Mix_PlayChannel(-1, clickeffect, 0);
			menuflag = 2;
		}
	}
	if (PLAYOK == 1)
	{
		if (n == 0)
		{
			SDL_RenderCopy(render, menup, NULL, NULL);
		}
		else
		{
			SDL_RenderCopy(render, menuppause, NULL, NULL);
		}
	}
	else if (QUITOK == 1)
	{
		if (n == 0)
		{
			SDL_RenderCopy(render, menuq, NULL, NULL);
		}
		else
		{
			SDL_RenderCopy(render, menuqpause, NULL, NULL);
		}
	}
	else
	{
		if (n == 0)
		{
			SDL_RenderCopy(render, menut, NULL, NULL);
		}
		else
		{
			SDL_RenderCopy(render, menupause, NULL, NULL);
		}
	}
	if (n == 0)
	{
		if (SHOPOK == 1)
		{
			shoprect = { 525,10,50 + 10,60 + 10 };
			SDL_RenderCopy(render, shopzoom, NULL, &shoprect);
		}
		if (SHOPOK == 0)
		{
			shoprect = { 530,15,50,60 };
			SDL_RenderCopy(render, shop, NULL, &shoprect);
		}
		SDL_RenderCopy(render, token, NULL, &coinrect);

		//token;
		int tempscore;
		SDL_Rect temporay[10];
		tempscore = score;
		score = filetokenamount;
		for (int i = 0; i < 9; i++)
		{
			temporay[i] = num[i];
		}
		for (int i = 0; i < 9; i++)
		{
			num[i].x = ((i * 24) + 24 + 15);
			num[i].y = 15;
			num[i].w = 24;
			num[i].h = 24;
		}
		ready_score_for_print(score);
		score = tempscore;
		for (int i = 0; i < 9; i++)
		{
			num[i] = temporay[i];
		}
	}

	SDL_RenderPresent(render);
	return menuflag;
}
int getbuydata(int c)
{
	int buydata;
	fstream handle;
	handle.open("skin_document.txt");
	handle.seekg(c * 2) >> buydata;
	handle.close();
	return buydata;

}
int GAME::setbuydata(int c)
{
	filetokenamount -= priority * 100;
	int buydata = 1;;
	fstream handle;
	ofstream write;
	write.open("tokens.txt");
	write << filetokenamount;
	write.close();
	handle.open("skin_document.txt");
	handle.seekp(c * 2) << 1;
	handle.close();
	return buydata;
}
void GAME::setcurrentskindata(int c)
{
	ofstream write;
	write.open("current_skin");
	write << c;
	write.close();
	currentskin = c;
}
void GAME::set_priority(int s_skin)
{
	fstream handle;
	handle.open("priority.txt");
	handle.seekg(s_skin * 2) >> priority;
	handle.close();
}
int GAME::shopfunction()
{
	int buydata = 1;
	int checkmusic;
	int x, y;
	buydata = getbuydata(shopcurrentskin);
	click = false;
	SDL_Event events;
	SDL_RenderCopy(render, shopbg, NULL, NULL);
	if (SDL_PollEvent(&events))
	{
		x = events.motion.x;
		y = events.motion.y;
		//leftarrow 
		if (x >= larrow.x && x <= larrow.x + larrow.w)
		{
			if (y >= larrow.y && y <= larrow.y + larrow.h)
			{
				checkmusic = SHOPLEFTOK;
				SHOPLEFTOK = 1;
				if (checkmusic != SHOPLEFTOK)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				SHOPLEFTOK = 0;
			}
		}
		else
		{
			SHOPLEFTOK = 0;
		}
		//right arrow
		if (x >= rarrow.x && x <= rarrow.x + rarrow.w)
		{
			if (y >= rarrow.y && y <= rarrow.y + rarrow.h)
			{
				checkmusic = SHOPRIGHTOK;
				SHOPRIGHTOK = 1;
				if (checkmusic != SHOPRIGHTOK)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				SHOPRIGHTOK = 0;
			}
		}
		else
		{
			SHOPRIGHTOK = 0;
		}
		//goback
		if (x >= gobackrect.x && x <= gobackrect.x + gobackrect.w)
		{
			if (y >= gobackrect.y && y <= gobackrect.y + gobackrect.h)
			{
				checkmusic = ESCAPESHOP;
				ESCAPESHOP = 1;
				if (checkmusic != ESCAPESHOP)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				ESCAPESHOP = 0;
			}
		}
		else
		{
			ESCAPESHOP = 0;
		}
		//traverse skin
		if (x >= skinpreview.x && x <= skinpreview.x + skinpreview.w)
		{
			if (y >= skinpreview.y && y <= skinpreview.y + skinpreview.h)
			{
				checkmusic = traverseok;
				traverseok = 1;
				if (checkmusic != traverseok)
					Mix_PlayChannel(-1, selecteffect, 0);
			}
			else
			{
				traverseok = 0;
			}
		}
		else
		{
			traverseok = 0;
		}
		//BUY
		if (buydata == 0)
		{
			if (filetokenamount >= priority * 100)
			{
				if (x >= buyrect.x && x <= buyrect.x + buyrect.w)
				{
					if (y >= buyrect.y && y <= buyrect.y + buyrect.h)
					{
						checkmusic = buyok;
						buyok = 1;
						if (checkmusic != buyok)
							Mix_PlayChannel(-1, selecteffect, 0);
					}
					else
					{
						buyok = 0;
					}
				}
				else
				{
					buyok = 0;
				}
			}
		}
		else
		{
			buyok = 0;
		}
		//clicking
		if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				click = true;
			}
			if (click == true && SHOPLEFTOK == 1)
			{
				Mix_PlayChannel(-1, clickeffect, 0);
				shopcurrentskin -= 1;
				if (shopcurrentskin < 0)
					shopcurrentskin = 7;
				set_priority(shopcurrentskin);
			}
			if (click == true && SHOPRIGHTOK == 1)
			{
				Mix_PlayChannel(-1, clickeffect, 0);
				shopcurrentskin += 1;
				if (shopcurrentskin > 7)
					shopcurrentskin = 0;
				set_priority(shopcurrentskin);
			}
			if (ESCAPESHOP)
			{
				if (events.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, clickeffect, 0);
					return 1;

				}
			}
			if (traverseok)
			{
				if (buydata == 1)
				{
					if (events.button.button == SDL_BUTTON_LEFT)
					{
						if (shopcurrentskin != currentskin)
						{
							if (events.button.button = SDL_BUTTON_LEFT)
							{
								Mix_PlayChannel(-1, clickeffect, 0);
								setcurrentskindata(shopcurrentskin);
							}
						}
					}
				}
			}
			if (buyok)
			{
				if (events.button.button == SDL_BUTTON_LEFT)
					if (filetokenamount >= priority * 100)
					{
						Mix_PlayChannel(-1, clickeffect, 0);
						buydata = setbuydata(shopcurrentskin);
					}

			}
		}
		//keyboard
		if (state[SDL_SCANCODE_LEFT])
		{

			SHOPLEFTOK = 1;
			Mix_PlayChannel(-1, clickeffect, 0);
			SDL_Delay(200);
			shopcurrentskin -= 1;
			if (shopcurrentskin < 0)
				shopcurrentskin = 7;
			set_priority(shopcurrentskin);
		}
		if (state[SDL_SCANCODE_RIGHT])
		{
			SHOPRIGHTOK = 1;
			Mix_PlayChannel(-1, clickeffect, 0);
			SDL_Delay(200);
			shopcurrentskin += 1;
			if (shopcurrentskin > 7)
				shopcurrentskin = 0;
			set_priority(shopcurrentskin);
		}
		if (events.type == SDL_QUIT)
		{
			return 2;
			run = false;
		}
	}
	//buy box
	if (buydata == 0)
	{
		if (filetokenamount >= priority * 100)
		{
			if (buyok == 0)
				SDL_RenderCopy(render, BUYABLE[priority], NULL, &buyrect);
			else
				SDL_RenderCopy(render, BUYABLEOK[priority], NULL, &buyrect);
		}
		else
		{
			SDL_RenderCopy(render, notbuyable, NULL, &buyrect);
		}
	}
	if (ESCAPESHOP == 0)
	{
		SDL_RenderCopy(render, goback, NULL, &gobackrect);
	}
	if (ESCAPESHOP == 1)
	{
		SDL_RenderCopy(render, gobackok, NULL, &gobackrect);
	}
	if (SHOPLEFTOK == 0)
	{
		larrow = { 160 - 55,260,50,80 };
		SDL_RenderCopy(render, shopleftarrow, NULL, &larrow);
	}
	if (SHOPLEFTOK == 1)
	{
		larrow = { 160 - 55 - 5,260 - 5,50 + 10,80 + 10 };
		SDL_RenderCopy(render, shopleftarrowzoom, NULL, &larrow);
	}
	if (SHOPRIGHTOK == 0)
	{
		rarrow = { 440 + 5,260,50,80 };
		SDL_RenderCopy(render, shoprightarrow, NULL, &rarrow);
	}
	if (SHOPRIGHTOK == 1)
	{
		rarrow = { 440,260 - 5,50 + 10,80 + 10 };
		SDL_RenderCopy(render, shoprightarrowzoom, NULL, &rarrow);
	}
	SDL_RenderCopy(render, s_preview[shopcurrentskin], NULL, &skinpreview);
	if (buydata == 0)
		SDL_RenderCopy(render, lock[priority], NULL, &skinpreview);
	//traverse box;
	if (traverseok)
	{
		if (buydata == 1 && currentskin == shopcurrentskin)
		{
			SDL_RenderCopy(render, skin_in_use, NULL, &skinpreview);
		}
		else
		{
			SDL_RenderCopy(render, traverseskin, NULL, &skinpreview);
		}
	}
	//in use state box
	if (buydata == 1)
	{
		if (shopcurrentskin == currentskin)
		{
			SDL_RenderCopy(render, inuse, NULL, &use_rect);
		}
		else
		{
			SDL_RenderCopy(render, to_use, NULL, &use_rect);
		}
	}
	//token;
	int tempscore;
	SDL_Rect temporay[10];
	tempscore = score;
	score = filetokenamount;
	for (int i = 0; i < 9; i++)
	{
		temporay[i] = num[i];
	}
	for (int i = 0; i < 9; i++)
	{
		num[i].x = ((i * 24) + 24 + 15);
		num[i].y = 15;
		num[i].w = 24;
		num[i].h = 24;
	}
	ready_score_for_print(score);
	score = tempscore;
	for (int i = 0; i < 9; i++)
	{
		num[i] = temporay[i];
	}
	SDL_RenderCopy(render, token, NULL, &coinrect);
	SDL_RenderPresent(render);
	if (state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_SPACE])
	{
		return 1;
	}

}
SDL_Texture* GAME::texload(const char* file)
{
	SDL_Texture* sample;
	SDL_Surface* temp = IMG_Load(file);
	sample = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
	return sample;
}
SDL_Texture* GAME::gettext(const char* str)
{
	SDL_Texture* text;
	TTF_Font* font = TTF_OpenFont("OCRAEXT.TTF", 24);
	SDL_Color colour = { 0,0,188,255 };
	SDL_Surface* temp = TTF_RenderText_Solid(font, str, colour);
	text = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
	return text;
}
void GAME::setsnake()
{
	int numx = 62;
	int ix = 290;
	int iy = 290;
	int iw = 10;
	int ih = 10;
	for (int i = 0; i < 1000; i++)
	{
		rect[i].x = ix;
		rect[i].y = iy;
		rect[i].w = iw;
		rect[i].h = ih;
		ix -= 10;
	}
	for (int i = 0; i < 3; i++)
	{
		baby[i].x = ix;
		baby[i].y = iy;
		baby[i].w = iw;
		baby[i].h = ih;
		ix -= 10;
	}
	frog = { 500,500,10,10 };
	upfrog();
	border[0] = { 0,0,600,10 };
	border[1] = { 0,0,10,600 };
	border[2] = { 0,590,600,10 };
	border[3] = { 590,0,10,600 };
	textrect = { 12,12,50,12 };
	for (int i = 0; i < 10; i++)
	{
		num[i].x = (i * 12) + numx;
		num[i].y = 12;
		num[i].w = 12;
		num[i].h = 12;
	}

}
void GAME::upsnake(int cas)
{
	for (int i = 999; i > 0; i--)
	{
		rect[i].y = rect[i - 1].y;
		rect[i].x = rect[i - 1].x;
	}
}
int GAME::collision()
{
	int flag = 0;
	for (int i = score + 6; i >= 1; i--)
	{
		if (rect[i].x == rect[0].x && rect[i].y == rect[0].y)
		{
			Mix_PlayChannel(1, deadeffect, 0);
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
		return 0;
}
void GAME::redheadrender()
{
	if (c == 1)
	{
		SDL_RenderCopy(render, shur, NULL, &rect[0]);
	}
	if (c == 2)
	{
		SDL_RenderCopy(render, shdr, NULL, &rect[0]);
	}
	if (c == 3)
	{
		SDL_RenderCopy(render, shrr, NULL, &rect[0]);
	}
	if (c == 4)
	{
		SDL_RenderCopy(render, shlr, NULL, &rect[0]);
	}
}
void GAME::upfrog()
{
	frog.x = rand() % 580;
	if (frog.x <= 10)
	{
		frog.x = frog.x + (10 - frog.x);
	}
	if (frog.x % 10 != 0)
	{
		frog.x = frog.x - (frog.x % 10);
	}
	frog.y = rand() % 580;
	if (frog.y <= 10)
	{
		frog.y = frog.y + (10 - frog.y);
	}
	if (frog.y % 10 != 0)
	{
		frog.y = frog.y - (frog.y % 10);
	}
	for (int i = score + 6; i >= 1; i--)
	{
		if (frog.x == rect[i].x && frog.y == rect[i].y)
		{
			upfrog();
		}
	}
	pop_up_frame++;
	pop_up_rect.x = frog.x - 20;
	pop_up_rect.y = frog.y - 20;
}
int GAME::eating()
{
	if (frog.x == rect[0].x && frog.y == rect[0].y)
	{
		frogscorerender = true;
		frogscoretime = 0;
		Mix_PlayChannel(0, eateffect, 0);
		setscorerect(frog);
		upfrog();
		score++;
		if (probability == 0 && score == p)
		{
			probability += 1;
			probability = probability % 2;
			p = p + 9 + (rand() % 4);

			cout << p << "performed octane  ";
			timenow = 0;
			timetexvar = 8;
			Mix_PlayChannel(1, powerroundeffect, 0);
			powerround = true;
			uppower();
		}

		if (probability == 1 && score == p)
		{
			probability += 1;
			probability = probability % 2;
			p = p + 7 + (rand() % 4);
			cout << p << "performed mirage  ";
			Mix_PlayChannel(1, powerroundeffect, 0);
			tripleround = true;
			tripletime = 0;
			timetexvar = 8;
			uppower2();
		}


	}

	return 0;
}
void GAME::triplepower()
{

	if (tripleround == true)
	{
		if (powerrect2.x == rect[0].x && powerrect2.y == rect[0].y)
		{
			Mix_PlayChannel(1, missileeffect, 0);
			baby[0].x = rect[0].x;
			baby[0].y = rect[0].y;
			baby[1].x = rect[1].x;
			baby[1].y = rect[1].y;
			baby[2].x = rect[2].x;
			baby[2].y = rect[2].y;
			tripleround = false;
			triplecount = 0;
			triplepowerplay = true;
		}

	}
	if (triplepowerplay == true)
	{
		if (triplecount == 3)
			triplepowerplay = false;
	}
	if (triplepowerplay == true)
	{
		for (int i = 2; i >= 1; i--)
		{
			baby[i] = baby[i - 1];
		}
		if (triplecount < 3)
		{
			if (baby[0].x > frog.x&& baby[0].y > frog.y)
			{
				baby[0].x -= 10;
				baby[0].y -= 10;
			}
			if (baby[0].x > frog.x&& baby[0].y < frog.y)
			{
				baby[0].x -= 10;
				baby[0].y += 10;
			}
			if (baby[0].x < frog.x && baby[0].y > frog.y)
			{
				baby[0].x += 10;
				baby[0].y -= 10;
			}
			if (baby[0].x < frog.x && baby[0].y < frog.y)
			{
				baby[0].x += 10;
				baby[0].y += 10;
			}
			if (baby[0].x > frog.x&& baby[0].y == frog.y)
			{

				baby[0].x -= 10;

			}

			if (baby[0].x < frog.x && baby[0].y == frog.y)
			{

				baby[0].x += 10;

			}

			if (baby[0].x == frog.x && baby[0].y > frog.y)
			{


				baby[0].y -= 10;
			}
			if (baby[0].x == frog.x && baby[0].y < frog.y)
			{


				baby[0].y += 10;
			}
			if (baby[0].x == frog.x && baby[0].y == frog.y)
			{
				if (triplecount != 2)
					Mix_PlayChannel(1, missileeffect, 0);
				triplecount++;
				baby[0].x = rect[0].x;
				baby[0].y = rect[0].y;
				score++;
				setscorerect(frog);
				upfrog();
				frogscorerender = true;
				frogscoretime = 0;
			}

		}

	}
}
void GAME::uppower()
{
	powerrect.x = rand() % 580;
	if (powerrect.x <= 10)
	{
		powerrect.x = powerrect.x + (10 - powerrect.x);
	}
	if (powerrect.x % 10 != 0)
	{
		powerrect.x = powerrect.x - (powerrect.x % 10);
	}
	powerrect.y = rand() % 580;
	if (powerrect.y <= 10)
	{
		powerrect.y = powerrect.y + (10 - powerrect.y);
	}
	if (powerrect.y % 10 != 0)
	{
		powerrect.y = powerrect.y - (powerrect.y % 10);
	}
	for (int i = score + 6; i >= 1; i--)
	{
		if (powerrect.x == rect[i].x && powerrect.y == rect[i].y)
		{
			uppower();
		}
	}
	if (frog.x == powerrect.x && frog.y == powerrect.y)
	{
		uppower();
	}
	pop_up_frame++;
	pop_up_rect.x = powerrect.x - 20;
	pop_up_rect.y = powerrect.y - 20;
}
void GAME::uppower2()
{
	powerrect2.x = rand() % 580;
	if (powerrect2.x <= 10)
	{
		powerrect2.x = powerrect2.x + (10 - powerrect2.x);
	}
	if (powerrect2.x % 10 != 0)
	{
		powerrect2.x = powerrect2.x - (powerrect2.x % 10);
	}
	powerrect2.y = rand() % 580;
	if (powerrect2.y <= 10)
	{
		powerrect2.y = powerrect2.y + (10 - powerrect2.y);
	}
	if (powerrect2.y % 10 != 0)
	{
		powerrect2.y = powerrect2.y - (powerrect2.y % 10);
	}
	for (int i = score + 6; i >= 1; i--)
	{
		if (powerrect2.x == rect[i].x && powerrect2.y == rect[i].y)
		{
			uppower2();
		}
	}
	if (frog.x == powerrect2.x && frog.y == powerrect2.y)
	{
		uppower2();
	}
	pop_up_frame++;
	pop_up_rect.x = powerrect2.x - 20;
	pop_up_rect.y = powerrect2.y - 20;
}
int GAME::checkpower()
{
	int flag = 0;
	timenow++;
	if (timenow % 16 == 0)
		timetexvar--;

	if (powerrect.x == rect[0].x && powerrect.y == rect[0].y)
	{
		scorerender = true;
		score += 3;

		Mix_PlayChannel(1, powerupeffect, -1);
		flag = 1;
		powerround = false;
		powerplay = true;
		powerplaytime = 0;
		timer.w = 200;
		nitrotex = 11;
	}
	if (timenow == 131)
	{

		flag = 1;
		powerround = false;
	}

	return flag;
}
int GAME::powerdelay()
{
	if (powerplay == true)
	{
		return 40;
	}

	if (powerplay == false)
		return 60;
}
int GAME::ready_score_for_print(int number)
{
	shiftleft = 1;
	int z = 0;//z is the number of digit of score
	int temp = number * 10;
	do
	{
		temp = temp / 10;
		z++;
	} while (temp / 10 != 0);
	if (z > shiftleft)
		shiftleft = z;
	temp = score * 10;
	do
	{
		temp = temp / 10;
		print_score(numberletter[temp - ((temp / 10) * 10)], z - 1);
		z--;

	} while (temp / 10 != 0);
	return z;

}

void GAME::print_score(SDL_Texture* tex, int n)//n is the place of the digit in the score
{
	SDL_RenderCopy(render, tex, NULL, &num[n]);
}

void GAME::bejiupdate()
{
	if (beji1.beji.y >= 500)
	{
		beji1.bejidirection = -5;
		beji1.vision.y = beji1.beji.y - 50;
	}
	if (beji1.beji.y <= 100)
	{
		beji1.bejidirection = 5;
		beji1.vision.y = 100;
	}
	beji1.beji.y += beji1.bejidirection;
	beji1.vision.y += beji1.bejidirection;
	Vector2 a, b, r;
	a.x = rect[0].x;
	a.y = rect[0].y;
	if (beji1.bejidirection == 5)
	{
		b.x = beji1.vision.x + 25;
		b.y = beji1.vision.y;
	}
	if (beji1.bejidirection == -5)
	{
		b.x = beji1.vision.x + 50;
		b.y = beji1.vision.y + 50;
	}
	r = a - b;
	float angle = Math::Atan2(-r.y, r.x);
	float radius = r.Length();

	if (beji1.bejidirection == 5)
	{
		if (radius <= 50)
		{
			//if (angle >= -1.1812 && angle <= -1.9634)
			beji1.detection = true;
			beji1.detcount = true;
		}
		else
			beji1.detection = false;
	}

	else
	{
		if (radius <= 50)
		{
			//if (angle <= 1.1812 && angle >= 1.9634)
			beji1.detection = true;
			beji1.detcount = true;
		}
		else
			beji1.detection = false;
	}
	if (beji1.detcount)
	{

		if (beji1.detcounter != 0 && beji1.detcounter % 16 == 0)
		{
			bomcounter++;
			boms[bomcounter].bomrect.x = static_cast<int>(b.x);
			boms[bomcounter].bomrect.y = static_cast<int>(b.y);
			boms[bomcounter].blastrad.x = boms[bomcounter].bomrect.x - 20;
			boms[bomcounter].blastrad.y = boms[bomcounter].bomrect.y - 20;
			boms[bomcounter].blastrad.w = 40;
			boms[bomcounter].blastrad.h = 40;
			boms[bomcounter].bomrect.h = 10;
			boms[bomcounter].bomrect.w = 10;
			boms[bomcounter].bomvec = a - b;

		}
		beji1.detcounter++;
		if (beji1.detcounter > 48)
		{
			beji1.detcount = false;
			beji1.detcounter = 0;
		}
	}

}
void GAME::bomupdate()
{

	for (int i = 0; i <= bomcounter; i++)
	{
		if (boms[i].alive)
		{
			if (boms[i].blast_frame >= 75)
			{
				boms[i].alive = false;
			}
			else
				boms[i].blast_frame++;
			Vector2 m, n, o, r;
			m.x = boms[i].bomrect.x;
			m.y = boms[i].bomrect.y;
			n.x = rect[0].x;
			n.y = rect[0].y;
			o = n - m;
			float radius = o.Length();
			if (poison == true)
			{
				if (radius <= poisonrect.h)
				{
					boms[i].alive = false;
				}
			}
			else
			{
				if (radius <= 20)
				{
					boms[i].alive = false;

					if (score >= 4)
					{
						score -= 3;
						blast_score_popdelay = 1;
					}

				}
			}
			if (radius >= 150)
			{
				boms[i].bomvec += 100 * o;
			}
			else
			{
				boms[i].bomvec += 85 * o;
			}
			//one o for less turn the more o the tighter the turn is
			r = boms[i].bomvec;
			r.Normalize();
			r = r * 40;
			boms[i].bomrect.x += static_cast<int>(r.x);
			boms[i].bomrect.y += static_cast<int>(r.y);
			boms[i].blastrad.x = boms[i].bomrect.x - 20;
			boms[i].blastrad.y = boms[i].bomrect.y - 20;
		}
	}
}
void GAME::bomrender()
{
	for (int i = 0; i <= bomcounter; i++)
	{
		if (boms[i].alive)
		{
			SDL_RenderCopy(render, bomtex, NULL, &boms[i].bomrect);
			SDL_RenderCopy(render, blast_rad_tex, NULL, &boms[i].blastrad);
		}

	}
}

void GAME::bejirender()
{
	if (beji1.bejidirection == 5)
	{
		if (beji1.detection)
			SDL_RenderCopy(render, visiontex[2], NULL, &beji1.vision);
		else
			SDL_RenderCopy(render, visiontex[0], NULL, &beji1.vision);
		SDL_RenderCopy(render, bejitex[0], NULL, &beji1.beji);
		//SDL_RenderCopyEx(render, bejitex[0], NULL, &beji1.beji,90.00, NULL,SDL_FLIP_NONE);
	}
	if (beji1.bejidirection == -5)
	{
		if (beji1.detection)
			SDL_RenderCopy(render, visiontex[3], NULL, &beji1.vision);
		else
			SDL_RenderCopy(render, visiontex[1], NULL, &beji1.vision);

		SDL_RenderCopy(render, bejitex[1], NULL, &beji1.beji);

	}
}
int GAME::handle(int filetokenamount)
{

	int quitev = 0;
	SDL_Event event;
	//here

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{
		case SDL_QUIT:
		{

			run = false;
			quitev = 1;

			break;
		}
		}

		if (state[SDL_SCANCODE_ESCAPE])
		{
			SDL_ShowCursor(SDL_ENABLE);
			Mix_Pause(1);
			int menustate = 0;
			while (menustate == 0)
			{
				menustate = menu(1);
			}
			SDL_ShowCursor(SDL_DISABLE);
			Mix_Resume(1);
			if (menustate == 2)
			{
				Mix_HaltChannel(1);
				run = false;
				pausequit = true;
			}
		}
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (poisoncounter >= 160)
		{
			poison = true;
		}

	}

	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
	{
		if (rect[0].x != rect[1].x)
		{
			//Mix_PlayChannel(0, turneffect, 0);
			direction.y = -10;
			c = 1;
		}
	}
	if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
	{
		if (rect[0].x != rect[1].x)
		{
			//Mix_PlayChannel(0, turneffect, 0);
			direction.y = 10;
			c = 2;
		}
	}
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
	{
		if (rect[0].y != rect[1].y)
		{
			//Mix_PlayChannel(0, turneffect, 0);
			direction.x = 10;
			c = 3;
		}
	}
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
	{
		if (rect[0].y != rect[1].y)
		{
			//Mix_PlayChannel(0, turneffect, 0);
			direction.x = -10;
			c = 4;
		}
	}


	return quitev;
}
void GAME::update()
{
	if (poison == false)
	{
		if (poisoncounter <= 160)
		{
			if (poisoncounter % 2 == 0)
			{
				poisonmeterrect.h += 1;
				poisonmeterrect.y -= 1;
			}
			poisoncounter++;
		}
	}
	else
	{

		poisoncounter--;
		if (poisoncounter % 2 == 0)
		{
			poisonmeterrect.h -= 1;
			poisonmeterrect.y += 1;
		}
		poisonrect.w += 3;
		poisonrect.h += 3;
		if (poisoncounter <= 136)
		{
			poisonmeterrect.h = 0;
			poisonmeterrect.y = 580;
			poison = false;
			poisoncounter = 0;
			poisonrect.w = 40;
			poisonrect.h = 40;
		}
	}
	if (frogscorerender == true)
	{
		frogscoretime++;
		if (frogscoretime == 9)
		{
			frogscorerender = false;
		}
	}
	if (powerplay == true)
	{
		powerplaytime++;

		timer.w = timer.w - 1;
		if (powerplaytime > 27)
		{
			scorerender = false;
		}
		if (powerplaytime % 17 == 0)
			nitrotex--;
		if (powerplaytime == 200)
		{

			Mix_PlayChannel(1, powerfinisheffect, 0);
			powerplay = false;
		}
	}

	eating();
	if (tripleround == true)
	{
		tripletime++;
		if (tripletime % 17 == 0)
			timetexvar--;
		if (tripletime == 131)
		{
			tripleround = false;
		}
	}
	triplepower();
	if (collision() == 1)
	{
		run = false;
	}
	else
	{
		if (rect[0].x > 600 - 20 || rect[0].x < 10 || rect[0].y < 10 || rect[0].y > 600 - 20)
		{
			Mix_PlayChannel(1, deadeffect, 0);
			run = false;
		}
		else
		{
			switch (c)
			{
			case 1:
			{
				upsnake(1);
				rect[0].y += direction.y;
				break;
			}
			case 2:
			{
				upsnake(1);
				rect[0].y += direction.y;
				break;
			}
			case 3:
			{
				upsnake(2);
				rect[0].x += direction.x;
				break;
			}
			case 4:
			{
				upsnake(2);
				rect[0].x += direction.x;
				break;
			}
			}
		}
	}
	bejiupdate();
	bomupdate();
}
void GAME::output()
{
	SDL_SetRenderDrawColor(render, 120, 120, 180, 255);
	SDL_RenderClear(render);
	//background
	SDL_RenderCopy(render, bg, NULL, NULL);
	//borders
	SDL_RenderCopy(render, borup, NULL, &border[0]);
	SDL_RenderCopy(render, borleft, NULL, &border[1]);
	SDL_RenderCopy(render, bordown, NULL, &border[2]);
	SDL_RenderCopy(render, borright, NULL, &border[3]);
	//poisonborder
	SDL_RenderCopy(render, poison_meter_tex, NULL, &poisonmeterrect);
	SDL_RenderCopy(render, poison_meter_border_tex, NULL, &poisonmeterborderrect);
	//timer
	if (powerround == true || tripleround == true)
	{
		SDL_RenderCopy(render, timerr[timetexvar], NULL, &roundtimer);
	}
	if (powerplay == true)
	{
		SDL_RenderCopy(render, nitro[nitrotex], NULL, &nitroindicator);
		/*
		SDL_RenderCopy(render, box, NULL, &timerbox);
		SDL_SetRenderDrawColor(render, 0,255, 0, 255);
		SDL_RenderFillRect(render, &timer);
		*/

	}
	//text
	SDL_RenderCopy(render, text, NULL, &textrect);
	//numbres
	ready_score_for_print(score);
	//frog
	SDL_RenderCopy(render, f1, NULL, &frog);
	//power
	if (powerround == true)
	{

		if (checkpower() == 0)
			SDL_RenderCopy(render, power, NULL, &powerrect);
	}
	triplepower();

	//snake
	for (int i = 6 + score; i >= 1; i--)
	{
		if (powerplay == true)
		{

			SDL_RenderCopy(render, powerbody, NULL, &rect[i]);
		}
		else
		{
			SDL_RenderCopy(render, s1[currentskin], NULL, &rect[i]);
		}
	}
	if (run == true)
	{
		if (poison)
		{
			poisonrect.x = rect[0].x - ((poisonrect.w) / 2);
			poisonrect.y = rect[0].y - ((poisonrect.h) / 2);
			SDL_RenderCopy(render, poison_tex, NULL, &poisonrect);
		}
		switch (c)
		{
		case 1:
		{
			SDL_RenderCopy(render, shu, NULL, &rect[0]);
			break;
		}
		case 2:
		{
			SDL_RenderCopy(render, shd, NULL, &rect[0]);
			break;
		}
		case 3:
		{
			SDL_RenderCopy(render, shr, NULL, &rect[0]);
			break;
		}
		case 4:
		{
			SDL_RenderCopy(render, shl, NULL, &rect[0]);
			break;
		}
		}
	}
	if (run == false)
	{
		redheadrender();
	}
	if (blast_score_popdelay >= 1)
	{
		blast_score_popdelay++;
		if (blast_score_popdelay >= 24)
			blast_score_popdelay = 0;
		setscorerect(rect[0]);
		SDL_RenderCopy(render, minusthree, NULL, &scorepop);
	}
	//score pop for power
	if (scorerender == true)
	{
		setscorerect(powerrect);
		SDL_RenderCopy(render, plusthree, NULL, &scorepop);
	}
	//score pop for frogscore
	if (frogscorerender == true)
	{
		SDL_RenderCopy(render, plusone, NULL, &scorepop);
	}
	//baby
	if (tripleround == true)
	{
		SDL_RenderCopy(render, triplepowertex, NULL, &powerrect2);
	}
	if (triplepowerplay == true)
	{
		SDL_RenderCopy(render, babyhead, NULL, &baby[0]);
		SDL_RenderCopy(render, babybody, NULL, &baby[1]);
		SDL_RenderCopy(render, babybody, NULL, &baby[2]);
	}
	bejirender();
	bomrender();
	if (pop_up_frame >= 0)
	{
		SDL_RenderCopy(render, pop_up_tex[pop_up_frame], NULL, &pop_up_rect);
		pop_up_frame++;
		if (pop_up_frame > 5)
		{
			pop_up_frame = -1;
		}
	}
	SDL_RenderPresent(render);
}
void GAME::gameover()
{
	SDL_Rect highs = { 215,341,110,24 };
	int highscore = 0;
	ifstream read;
	read.open("highscore.txt");
	read >> highscore;
	read.close();
	Mix_HaltChannel(2);
	textrect = { 230 - (shiftleft * 6),220,100,24 };
	for (int i = 0; i < 9; i++)
	{
		num[i].x = ((i * 24) + 230 + 102) - (shiftleft * 6);
		num[i].y = 220;
		num[i].w = 24;
		num[i].h = 24;
	}
	SDL_RenderCopy(render, go, NULL, NULL);
	SDL_RenderCopy(render, text, NULL, &textrect);
	ready_score_for_print(score);
	SDL_RenderCopy(render, highscoretex, NULL, &highs);
	for (int i = 0; i < 9; i++)
	{
		num[i].x = ((i * 24) + 215 + 102);
		num[i].y = 341;
		num[i].w = 24;
		num[i].h = 24;
	}
	score = highscore;
	ready_score_for_print(score);
	SDL_RenderPresent(render);
}
void GAME::destroy()
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
}
void GAME::setscorerect(SDL_Rect r)
{
	if (r.x > 590 - 54)
	{
		if (r.y > 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x - 34;
		}
		if (r.y < 54)
		{
			scorepop.y = r.y + 34;
			scorepop.x = r.x - 34;
		}
		if (r.y > 54 && r.y < 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x - 14;
		}
	}
	if (r.x < 74)
	{
		if (r.y > 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x + 20;
		}
		if (r.y < 54)
		{
			scorepop.y = r.y + 34;
			scorepop.x = r.x + 20;
		}
		if (r.y > 54 && r.y < 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x + 20;
		}
	}
	if (r.x > 54 && r.x < 590 - 54)
	{
		if (r.y > 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x - 14;
		}
		if (r.y < 54)
		{
			scorepop.y = r.y + 34;
			scorepop.x = r.x - 14;
		}
		if (r.y > 54 && r.y < 590 - 54)
		{
			scorepop.y = r.y - 34;
			scorepop.x = r.x - 14;
		}
	}
}
