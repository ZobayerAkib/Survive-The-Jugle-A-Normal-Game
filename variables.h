#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
struct menuItemsPosition
{
	int x, y;

};
menuItemsPosition pn[5];

int c = 0, s = 0;

int cx = 620;

int score = 0; char scorearray[20];

int index = 0;

int charX = 0, charY = 155;


int mposx, mposy;
int menuSelect = -1;
int gameSelect = -1;
char lowerBG[19] = { "image\\STSPath2.bmp" };

char run[6][15] = { "image\\run1.bmp", "image\\run2.bmp", "image\\run3.bmp", "image\\run4.bmp", "image\\run5.bmp", "image\\run6.bmp" };
char runBack[6][16] = { "image\\run7.bmp", "image\\run8.bmp", "image\\run9.bmp", "image\\run10.bmp", "image\\run11.bmp", "image\\run12.bmp" };
char jum[4][18] = { "image\\jump04.bmp", "image\\jump05.bmp", "image\\jumpr04.bmp", "image\\jumpr05.bmp" };
char menuItems[5][16] = { "image\\SPlay.bmp", "image\\SA.bmp", "image\\SE.bmp", "image\\SIns.bmp", "image\\SHs.bmp" };
char stand[16] = { "image\\stand.bmp" };
char bullet[17] = { "image\\bullet.bmp" };
char bulletR[18] = { "image\\bullet2.bmp" };
char homemenu[17] = "image\\SpearH.bmp";
char play[19] = "image\\Spear-01.bmp";
char instraction[21] = "image\\SpearStory.bmp";
char hs[14] = "image\\SHs.bmp";
char about[16] = "image\\temp2.bmp";
char Exit[13] = "image\\SE.bmp";
char gameOver[19] = "image\\gameOver.bmp";

char en[4][18] = { "image\\enemy01.bmp", "image\\enemy02.bmp", "image\\enemy03.bmp", "image\\enemy04.bmp" };
char obstacle[4][15] = { "image\\obs1.bmp", "image\\obs2.bmp", "image\\obs3.bmp", "image\\obs4.bmp" };
char dragon[9][18] = { "image\\dragon1.bmp", "image\\dragon2.bmp", "image\\dragon3.bmp", "image\\dragon4.bmp", "image\\dragon5.bmp", "image\\dragon6.bmp", "image\\dragon7.bmp", "image\\dragon8.bmp", "image\\dragon9.bmp" };
char birdFire[19] = { "image\\birdFire.bmp" };
char enemyBird[9][16] = { "image\\bird1.bmp", "image\\bird2.bmp", "image\\bird3.bmp", "image\\bird4.bmp", "image\\bird5.bmp", "image\\bird6.bmp", "image\\bird7.bmp", "image\\bird8.bmp", "image\\bird9.bmp" };
char nm[19] = { "image\\nameInfo.bmp" };
char str[100], str2[100];
int len;
bool standPosition = true;
int standCounter = 0;
boolean music1 = true;

int dir = 0;
bool jump = false;
bool jumpUp = false;
int jumpLimit = 75;
int jumpPosition = 0;

bool throwBullet = false;
int bulletX = charX + 86, bulletY = charY + jumpPosition + 65;

int enemyX = 1280, enemyY = 155, enemyIndex = 0;
bool enemyShow = true;

int obsX = 1280, obsY = 155, obsIndex = 0;
int enemyBirdX = -100, enemyBirdY = 265, enemyBirdIndex = 0;
bool enemyBirdShow = false;

int dragonX = 0, dragonY = 520, dragonIndex = 0;

int birdFireX = dragonX + 182, birdFireY = dragonY + 30;
bool birdFireShow = true;
bool pause = false;

int dx = 200;
bool groundStop = false;
#endif