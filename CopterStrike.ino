#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#define SELECTMAP 1
#define GAME 2

#define SCREENWIDTH 84
#define SCREENHEIGHT 48
#define VERTALIGNMENT 10
#define LEVELWIDTH 1000
#define LEVELHEIGHT 1000
#define SPRITESIZE 125

#define MAXALTITUDE 10
#define MAXFUEL 20
#define MAXLIFE 100
#define MAXAMMO 50
#define MAXBULLET 10


//Sprites
extern const byte gamelogo[];

extern const byte HUD[];

extern const byte helix[4][8];
extern const byte impact[3][10];
extern const byte boom[12][14];

extern const byte copterShadow[];
extern const byte copterProfile[];
extern const byte copterProfile_mask[];
extern const byte copterDiag1[];
extern const byte copterDiag1_mask[];
extern const byte copterDiag2[];
extern const byte copterDiag2_mask[];
extern const byte copterDown[];
extern const byte copterUp[];
extern const byte copterUp[];
extern const byte copterUpDown_mask[];

extern const byte Desert_sand[];
extern const byte Desert_bush[];
extern const byte Desert_cactus[];
extern const byte Desert_tree[];
extern const byte Desert_rock[];

extern const byte* sprites[];
extern const byte* destroy[];

//Sounds
extern const byte soundfx[6][8];

//Struct
typedef struct{
  int  x_world;
  int  y_world;
  char dir;
  char vSpeed;
  char hSpeed;
  byte maxSpeed;
  byte altitude;
  byte isLanding;
  byte fire;
  byte ammo;
  byte fuel;
  byte fuelCheck;
  byte life;
  byte isCrashing;
  byte animHelix;
  byte animBoom;
  byte animDamage;
} Player;

typedef struct{
  byte shooter;
  int x_world;
  int y_world;
  byte dir;
  byte distance;
} Bullet;

typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
  byte sprite;
  byte life; 
  byte animBoom;
  byte fireTimer;
} Object;

typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
} Friend;

Player player;
Friend bkgrnd[10];
Object landscape[30];
Bullet bullet[MAXBULLET];

//Global Variables
byte i;
byte j;
byte check01;
byte cptAnim;
byte gameStatus;
byte lvl;
int coordx;
int coordy;
byte width;
byte height;
byte nbLandscape;
byte nbBackground;
byte nbEnnemy;


//#####################################################
//#####################################################
void setup() {
  gb.begin();
  gameStatus = SELECTMAP;
  lvl = 0;
  cptAnim=0;
  fnctn_initPlayer();
  //fnctn_initLandscape();
  gb.titleScreen(gamelogo);
  gb.battery.show=false;
}



//#####################################################
//#####################################################
void loop() {
  if(gb.update()){ 
    switch(gameStatus){
      case 1 :
        outpt_menu();
        fnctn_checkButtons();
      break;


      case 2 :
        //draw
        outpt_drawBackground1();
        fnctn_checkLanding();
        outpt_drawBackground2();
        outpt_drawPlayer();
        outpt_drawPlayerFire();
        outpt_drawEnnemyFire();
        outpt_drawHUD();
        outpt_animBoom();
    
        //checks
        fnctn_checkButtons();
        fnctn_checkPlayerAltitude();
        fnctn_checkPlayerFire();
        fnctn_checkEnnemyFire();
        fnctn_checkFuel();
    
        //animation Timers
        fnctn_initEnnemyFire();
        fnctn_animation();
      break;
    }
  }
}
