#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#define NAME_MENU "CS"

#define GAME 2

#define SCREENWIDTH 84
#define SCREENHEIGHT 48
#define VERTALIGNMENT 10
#define LEVELWIDTH 630
#define LEVELHEIGHT 630
#define SPRITESIZE 125

#define MAXALTITUDE 8
#define MAXFUEL 30
#define MAXLIFE 50
#define MAXBULLET 10

#define TMPUNIT 20
#define TMPTANK 40
#define TMPTOUR 20
#define TMPBUNKER 10
#define TMPRESURECTION 200
#define NB_MOBILE_UNIT 12
extern const byte HUD[];

extern const byte helix[4][8];
extern const byte impact[3][10];
extern const byte boom[12][13];


extern const byte copterShadow[];
extern const byte copterProfile[];
extern const byte copterProfile_mask[];
extern const byte copterDiag1[];
extern const byte copterDiag1_mask[];
extern const byte copterDiag2[];
extern const byte copterDiag2_mask[];
extern const byte copterDown[];
extern const byte copterUp[];
extern const byte copterUpDown_mask[];

extern const byte Ennemy_Unit[];

extern const byte* sprites[];
extern const byte* destroy[];
extern const byte* tank[];
extern const byte* spriteBkg[];

//Struct
typedef struct{
  int  x_world;
  int  y_world;
  char dir;
  char vSpeed;
  char hSpeed;
  byte altitude;
  byte isLanding;
  byte fire;
  byte fuel;
  byte fuelCheck;
  byte life;
  byte isCrashing;
  byte animHelix;
  byte animBoom;
  byte animDamage;
  byte moveMode;
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
} Hostile;

typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
  byte sprite;
  byte life; 
  byte animBoom;
  byte fireTimer;
  byte dir;
  byte batiment;
} HostileMobile;

typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
  byte sprite;
  byte life; 
  byte animBoom;
} Object;

typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
  byte sprite;
} Friend;

typedef struct{
  int x_world;
  int y_world;
  byte sprite;
} Bkgrnd;

Player        player;
Friend        bkgrnd[15];
Bkgrnd        bkg[19];
Object        building_friend[9];
Hostile       building_hostile[21];
HostileMobile mobilUnit_hostile[NB_MOBILE_UNIT];
Bullet        bullet[MAXBULLET];


//Global Variables
byte i;
byte j;
byte check01;
byte check02;
byte cptAnim;
byte gameStatus;
//byte lvl;
//byte difficulty;
int money;
byte destroyedBuildings;
int coordx;
int coordy;
byte width;
byte height;
byte nbHeliport;
byte nbBuilding_Hostile;
byte nbBuilding_Friend;

#define NB_POSSIBLE_POS 5
uint8_t possblePosData[NB_POSSIBLE_POS] = {20,19,17,20,18};
uint8_t wherIsData;
bool findData;

//#####################################################
//#####################################################
void setup() {
  gb.begin();
  gb.battery.show=false;
  intialiseMap();
}

void intialiseMap()
{
  gb.pickRandomSeed();
  gameStatus = GAME;
  money=0;
  cptAnim=0;
  fnctn_initLevel();
  fnctn_initPlayer(); 
  findData = false;
  wherIsData = possblePosData[random(0,NB_POSSIBLE_POS)];
}

//#####################################################
//#####################################################
void loop() {
  if(gb.update()){ 
    
      if(gb.buttons.pressed(BTN_C)){
        returnToMenu();
      }

      //draw baseCamps          (Base, fuel, garage, heliport)
      outpt_drawbaseCamps();
      
      //draw friendBuildings  (Village, Camps) 
      outpt_drawBuilding_Friend();
      //draw hostileBuildings (Tour, Bunker) & Mobiles(Units, Tank)
      outpt_drawBuilding_Hostile();
      outpt_drawMobile_Hostile();

      //draw background         (tree, bush, sand, rocks)
      outpt_drawBackground();
      
      //draw player & ennemy Fire
      outpt_drawPlayerFire();
      outpt_drawEnnemyFire();
      
      //draw HUD + Player
      outpt_drawHUD();
      outpt_drawPlayer();
      
      //draw animBoom
      outpt_animBoom();

      //outpt_GameOver
      outpt_GameOver();

      
      //checks
      fnctn_checkLanding();
      fnctn_checkButtons();
      fnctn_checkPlayerAltitude();
      fnctn_checkPlayerFire();
      fnctn_checkEnnemyFire();
      fnctn_checkFuel();
  
      //Timers
      fnctn_initEnnemyFire();
      fnctn_animation();
      fnctn_resurection();
  }
}

void returnToMenu()
{
  while(true){
    if(gb.update()){
      gb.display.println("Are you sur to return "); 
      gb.display.println("To Game menu?");
      gb.display.println("Press \25 to quit");
      gb.display.println("Press \27 to restart");
      
      if(gb.buttons.pressed(BTN_C)){
        intialiseMap();
        return;  
      }
      if(gb.buttons.pressed(BTN_A)){
        gb.display.clear();
        gb.display.println("Extraction ...");
        gb.display.println("Please Wait"); 
        gb.display.update();
        load_game(NAME_MENU);
      }
      if(gb.buttons.pressed(BTN_B)){
        break;
      }
    }
  }
}
