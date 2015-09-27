#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;






const byte camionB[] PROGMEM = {16,14,0x7,0xE0,0xA,0x50,0xE,0x70,0x4,0x20,0x4,0x20,0x4,0x20,0x7,0xE0,0x7,0xE0,0x7,0xE0,0x4,0x20,0x7,0xE0,0xF,0xF0,0xB,0xD0,0x7,0xE0,};
const byte camionBD[] PROGMEM = {16,15,0xC,0x0,0xF,0x0,0x1F,0xC0,0x27,0xF0,0xE3,0xF8,0xF0,0xCE,0xFC,0x9B,0xFF,0xF1,0xBF,0x23,0x9F,0xEF,0x7F,0xF9,0x1F,0xE3,0x7,0x7E,0x1,0x3C,0x0,0xF0,};
const byte camionBG[] PROGMEM = {16,15,0x0,0x30,0x0,0xF0,0x3,0xFD,0xF,0xE3,0x1F,0xCF,0x73,0x1F,0xD9,0xBF,0x8F,0xFF,0xC4,0xFD,0xF7,0xF9,0x9F,0xFE,0xC7,0xF8,0x7E,0xE0,0x3C,0x80,0xF,0x0,};
const byte camionD[] PROGMEM = {16,14,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x70,0xFF,0xC8,0xFF,0xC8,0xFF,0xFC,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0x50,0x28,0x20,0x10,0x0,0x0,};
const byte camionG[] PROGMEM = {16,14,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xE,0x0,0x13,0xFF,0x13,0xFF,0x3F,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0x14,0xA,0x8,0x4,0x0,0x0,};
const byte camionH[] PROGMEM = {16,14,0x0,0x0,0x7,0xE0,0x7,0xE0,0x7,0xE0,0x4,0x20,0xF,0xF0,0xC,0x30,0xC,0x30,0xC,0x30,0xC,0x30,0xC,0x30,0xB,0xD0,0x7,0xE0,0x2,0x40,};
const byte camionHD[] PROGMEM = {16,14,0x0,0xF0,0x1,0xFC,0x3,0x7E,0xF,0x3A,0x1F,0x97,0x7E,0x7F,0x58,0x7E,0xD1,0xFC,0xE7,0xF8,0xCB,0xE8,0xEB,0xB0,0x7F,0x80,0x1D,0x0,0xE,0x0,};
const byte camionHG[] PROGMEM = {16,14,0xF,0x0,0x3F,0x80,0x7E,0xC0,0x5C,0xF0,0xE9,0xF8,0xFE,0x7E,0x7E,0x1A,0x3F,0x8B,0x1F,0xE7,0x17,0xD3,0xD,0xD7,0x1,0xFE,0x0,0xB8,0x0,0x70,};
const byte mecaB[] PROGMEM = {16,22,0x0,0x0,0x0,0x0,0xF0,0xF,0x90,0x9,0xD0,0xD,0xB3,0xCB,0xD6,0x6D,0xBC,0x3B,0xD8,0x1D,0xBC,0x3B,0xD7,0xED,0x91,0x89,0xF0,0xF,0x22,0x44,0x33,0xCC,0x12,0x48,0x12,0x48,0x1E,0x78,0x12,0x48,0x3E,0x7C,0x52,0x4A,0x9E,0x79,};
const byte mecaBD[] PROGMEM = {16,22,0x0,0x70,0x0,0xCC,0x0,0xE3,0x0,0x9F,0x70,0x85,0xDF,0xC5,0xE2,0x25,0x9F,0x1D,0x87,0x77,0x85,0xC2,0x85,0xC7,0x85,0x79,0x7F,0xE6,0x1F,0xFC,0x1C,0xEC,0xC,0xB4,0xB,0xA8,0xA,0xBC,0xB,0xB2,0x17,0xDC,0x1A,0x40,0x3,0x80,};
const byte mecaBG[] PROGMEM = {16,22,0xE,0x0,0x33,0x0,0xC7,0x0,0xF9,0x0,0xA1,0xE,0xA3,0xFB,0xA4,0x47,0xB8,0xF9,0xEE,0xE1,0x43,0xA1,0xE3,0xA1,0x9E,0xA1,0x67,0xFE,0x3F,0xF8,0x37,0x38,0x2D,0x30,0x15,0xD0,0x3D,0x50,0x4D,0xD0,0x3B,0xE8,0x2,0x58,0x1,0xC0,};
const byte mecaD[] PROGMEM = {16,22,0x0,0x0,0x0,0x0,0x1F,0xE0,0x10,0x20,0x10,0x40,0x10,0x20,0x10,0x40,0x70,0x30,0x50,0x6C,0x50,0x24,0x50,0x62,0x50,0x3F,0x30,0x5E,0x1F,0xE0,0xC,0x40,0x1F,0x60,0x13,0x20,0x31,0x30,0x21,0x18,0xE7,0xC,0xA5,0xF4,0xDF,0x9C,};
const byte mecaG[] PROGMEM = {16,22,0x0,0x0,0x0,0x0,0x7,0xF8,0x4,0x8,0x2,0x8,0x4,0x8,0x2,0x8,0xC,0xE,0x36,0xA,0x24,0xA,0x46,0xA,0xFC,0xA,0x7A,0xC,0x7,0xF8,0x2,0x30,0x6,0xF8,0x4,0xC8,0xC,0x8C,0x18,0x84,0x30,0xE7,0x2F,0xA5,0x39,0xFB,};
const byte mecaH[] PROGMEM = {16,22,0x0,0x0,0x0,0x0,0xF0,0xF,0x90,0x9,0xB0,0xD,0xF3,0xCF,0xF7,0xEF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xEF,0x91,0x89,0xF0,0xF,0x22,0x44,0x33,0xCC,0x12,0x48,0x12,0x48,0x1E,0x78,0x12,0x48,0x3E,0x7C,0x52,0x4A,0x9E,0x79,};
const byte mecaHD[] PROGMEM = {16,22,0xE,0x0,0x33,0x0,0xC7,0x0,0xF9,0x0,0xA1,0xE,0xE3,0xFB,0xE6,0x47,0xB9,0xF9,0xE0,0xE1,0x43,0xA1,0xE3,0xE1,0xFE,0xE1,0x7F,0xBE,0x3F,0xF8,0x35,0x38,0x2D,0x30,0x37,0xD0,0x23,0x58,0x2F,0xD4,0x39,0xEC,0x0,0x1C,0x0,0x0,};
const byte mecaHG[] PROGMEM = {16,22,0x0,0x70,0x0,0xCC,0x0,0xE3,0x0,0x9F,0x70,0x85,0xDF,0xC7,0xE2,0x67,0x9F,0x9D,0x87,0x7,0x85,0xC2,0x87,0xC7,0x87,0x7F,0x7D,0xFE,0x1F,0xFC,0x1C,0xAC,0xC,0xB4,0xB,0xEC,0x1A,0xC4,0x2B,0xF4,0x37,0x9C,0x38,0x0,0x0,0x0,};

const byte roudeH[] PROGMEM = {16,16,0xF7,0xD9,0x9E,0xFF,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x52,0x9,0x8,0xA2,0x52,0x0,0x0,0xA,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xCF,0xF7,0xFB,0x6F,};
const byte roudeV[] PROGMEM = {16,16,0xC0,0x3,0xC1,0x41,0x84,0x1,0x80,0x43,0xC1,0x2,0x40,0x83,0xC1,0x43,0xC0,0x1,0x45,0x3,0xC0,0xA3,0xC0,0x82,0x40,0x3,0x81,0x43,0xC2,0x2,0xC2,0x82,0xC0,0x3,};
const byte virage1[] PROGMEM = {16,16,0xEE,0x4,0xFF,0x80,0x7,0xA0,0x1,0xE2,0x0,0x78,0x0,0x3C,0xC0,0x1C,0x51,0xE,0x4,0xE,0xA,0x84,0x0,0x6,0x5,0x7,0x0,0x3,0x1,0x43,0xC0,0x83,0xC1,0x3,};
const byte virage2[] PROGMEM = {16,16,0x20,0x77,0x1,0xFF,0x5,0xE0,0x47,0x80,0x1E,0x0,0x3C,0x8,0x38,0x2,0x70,0x8A,0x70,0x20,0x21,0x10,0x60,0x8,0xE0,0xA0,0xC0,0x0,0xC2,0x80,0xC0,0x3,0xC0,0x83,};
const byte virage3[] PROGMEM = {16,16,0xC1,0x3,0xC0,0x83,0x1,0x43,0x0,0x3,0x5,0x7,0x0,0x6,0xA,0x84,0x4,0xE,0x71,0xE,0x40,0x1C,0x0,0x3C,0x0,0x78,0x1,0xE2,0x7,0xA0,0xFF,0x80,0xEE,0x4,};
const byte virage4[] PROGMEM = {16,16,0xC0,0x83,0xC1,0x3,0xC2,0x80,0xC3,0x0,0xE2,0xA0,0x60,0x80,0x21,0x50,0x70,0x20,0x70,0x8A,0x38,0x3,0x3C,0x0,0x1E,0x0,0x47,0x80,0x5,0xE0,0x1,0xFF,0x20,0x77,};
const byte routeExplose[] PROGMEM = {16,16,0xF7,0xD9,0x98,0x37,0x9,0x48,0x19,0x46,0x21,0x22,0x42,0x20,0xC4,0x13,0x84,0x8A,0xC8,0xC8,0x84,0x12,0x62,0x11,0x62,0x22,0x21,0x42,0x30,0x94,0xC8,0x97,0xFB,0x6F,};










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
#define WAIT_TIME 240

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


typedef struct{
  uint16_t  x_world;
  uint16_t  y_world;
  byte sprite;
} route;


typedef struct{
  int x_world;
  int y_world;
  byte width;
  byte height;
  const byte * sprites[8] = {camionD,camionHD,camionBD,camionG,camionHG,camionBG,camionH,camionB};
  byte life; 
  byte animBoom;
  byte dir;
  byte animDamage;
} friendMobile;

friendMobile Camion;

typedef struct{
  uint16_t  x_world;
  uint16_t  y_world;
} checkPoint;

//18
#define NB_CHECK_POINT 19
const checkPoint CheckPoint[NB_CHECK_POINT] PROGMEM = {
  {160,56},
  {161,25},
  {249,25},
  {270,45},
  {270,117},
  {350,122},
  {353,196},
  {342,202}, //route exploser
  {373,279},
  {329,349},
  {230,301},
  {220,335},
  {155,332},
  {145,387},
  {104,395},
  {98,454},
  {66,486},
  {64,536},
  {30,543}//fin
};

uint8_t currentCheckPoint = 0;

//68
#define NB_TSPRITE_ROUTE 68 

const route Routes[NB_TSPRITE_ROUTE] PROGMEM = {
  {112,56,0},
  {128,56,0},
  {144,56,0},
  {160,56,4},
  {160,40,1},
  {160,24,3},
  {176,24,0},
  {192,24,0},
  {208,24,0},
  {224,24,0},
  {240,24,0},
  {256,25,2},
  {256,41,5},
  {272,41,2},
  {272,57,1},
  {272,73,1},
  {272,89,1},
  {272,105,1},
  {272,121,5},
  {288,121,0},
  {304,121,0},
  {320,121,0},
  {336,121,0},
  {352,121,2},
  {352,137,1},
  {352,153,1},
  {352,169,1},
  {352,185,1},
  {352,200,4},
  {336,200,0},
  {320,200,6},//route barrer
  {304,200,0},
  {288,200,0},
  {272,200,0},
  {256,200,3},
  {256,216,1},
  {256,232,1},
  {256,248,1},
  {256,264,4},
  {240,264,0},
  {224,264,3},
  {224,280,1},
  {224,296,1},
  {224,312,1},
  {224,328,4},
  {208,328,0},
  {192,328,0},
  {176,328,0},
  {160,328,0},
  {144,328,3},
  {144,344,1},
  {144,360,1},
  {144,376,1},
  {144,392,4},
  {128,392,0},
  {112,392,0},
  {96,392,3},
  {96,408,1},
  {96,424,1},
  {96,440,1},
  {96,456,4},
  {80,456,3},
  {80,472,4},
  {64,472,3},
  {64,488,1},
  {64,504,1},
  {64,520,1},
  {64,536,4},
};

Player        player;
Friend        bkgrnd[15];
Bkgrnd        bkg[19];
Object        building_friend[9];
Hostile       building_hostile[21];
HostileMobile mobilUnit_hostile[20];
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
boolean convoiSecuriser = false;
byte wait_time;


//global methode
uint8_t getNext();


//#####################################################
//#####################################################
void setup() {
  gb.begin();
  gameStatus = GAME;
  money=0;
  cptAnim=0;
  gb.battery.show=false;
  fnctn_initLevel();
  fnctn_initPlayer(); 
  initFriendMobile();
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

      outpt_draw_route();
      //draw background         (tree, bush, sand, rocks)
      outpt_drawBackground();
      
      //draw player & ennemy Fire
      outpt_drawPlayerFire();
      outpt_drawEnnemyFire();
      
      //draw HUD + Player
      outpt_drawHUD();
      outpt_drawPlayer();
      
      //
      updateFriendMobile();
      outpt_draw_camion();
      
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
      //fnctn_resurection();
  }
}

void returnToMenu()
{
  while(true){
    if(gb.update()){
      gb.display.println("Are you sur to return "); 
      gb.display.println("To Game menu?");
      gb.display.println("Press \25 to quit");
      
      if(gb.buttons.pressed(BTN_A)){
        gb.display.clear();
        gb.display.println("Extraction ...");
        gb.display.println("Please Wait"); 
        gb.display.update();
        load_game(NAME_MENU);
      }
      if(gb.buttons.pressed(BTN_B) || gb.buttons.pressed(BTN_C)){
        break;
      }
    }
  }
}