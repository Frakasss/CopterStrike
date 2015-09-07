//fnctn_checkButtons()
//fnctn_initPlayer()
//fnctn_initLevel()
//fnctn_checkPlayerAltitude()
//fnctn_checkPlayerFire()
//fnctn_checkLanding()
//byte fnctn_playerXpos(int x)
//byte fnctn_playerYpos(int y)
//int fnctn_backgrndXpos(int x)
//int fnctn_backgrndYpos(int y)
//int fnctn_lndscapeXpos(int x)
//int fnctn_lndscapeYpos(int y)
//void fnctn_animation()



//##################################################################
//##################################################################
void fnctn_checkButtons() {
  switch(gameStatus){
    case 1 :
      if(gb.buttons.pressed(BTN_RIGHT)){lvl=(lvl+1)%2;}
      if(gb.buttons.pressed(BTN_LEFT)) {if(lvl==0){lvl=1;}else{lvl=(lvl%2-1);}}
      if(gb.buttons.pressed(BTN_DOWN)){difficulty=(difficulty+1)%3;}
      if(gb.buttons.pressed(BTN_UP)) {if(difficulty==0){difficulty=2;}else{difficulty=(difficulty%3-1);}}
      if(gb.buttons.pressed(BTN_A))    {gameStatus = GAME;fnctn_initLevel();fnctn_initPlayer(); }
      if(gb.buttons.pressed(BTN_C)){gb.titleScreen(gamelogo);}
    break;

    case 2:
  
      if(gb.buttons.pressed(BTN_C)){gameStatus=SELECTMAP;}
    
      if(gb.buttons.pressed(BTN_B)){
        switch(player.moveMode){
          case 0: player.moveMode=1; break;
          case 1: player.moveMode=0; break;
        }
      }
    
      if(gb.buttons.repeat(BTN_A,0) && player.isLanding==0 && player.altitude == MAXALTITUDE){
        player.fire = 1;
      }else{
        player.fire = 0;
      }
    
    
      if(player.isLanding==0 && player.life>0){
        if(gb.buttons.repeat(BTN_RIGHT,0)){
          if(player.hSpeed<3){player.hSpeed++;}
        }else if(gb.buttons.repeat(BTN_LEFT,0)){
          if(player.hSpeed>-3){player.hSpeed--;}
        }else{
          if(player.hSpeed>0)     {player.hSpeed--;}
          else if(player.hSpeed<0){player.hSpeed++;}
        }
          
        if(gb.buttons.repeat(BTN_DOWN,0)){
          if(player.vSpeed<3){player.vSpeed++;}
        }else if(gb.buttons.repeat(BTN_UP,0)){
          if(player.vSpeed>-3){player.vSpeed--;}
        }else{
          if(player.vSpeed>0)     {player.vSpeed--;}
          else if(player.vSpeed<0){player.vSpeed++;}
        }
      
        if(player.hSpeed>0){
          for(i=0;i<player.hSpeed;i++)      {if(player.x_world<LEVELWIDTH){player.x_world++;}}
        }else if(player.hSpeed<0){
          for(i=0;i<abs(player.hSpeed);i++) {if(player.x_world>0){player.x_world--;}}
        }
        
        
        if(player.vSpeed>0){
          for(i=0;i<player.vSpeed;i++)      {if(player.y_world<LEVELHEIGHT){player.y_world++;}}
        }else if(player.vSpeed<0){
          for(i=0;i<abs(player.vSpeed);i++) {if(player.y_world>13){player.y_world--;}}
        }
    
        if(gb.buttons.repeat(BTN_A,0) && player.isLanding==0 && player.altitude == MAXALTITUDE){
          player.fire = 1;
        }else{
          player.fire = 0;
        }

        if(player.moveMode==0){
          if(player.hSpeed>0  && player.vSpeed==0){player.dir=0;}
          if(player.hSpeed>0  && player.vSpeed>0 ){player.dir=1;}
          if(player.hSpeed==0 && player.vSpeed>0 ){player.dir=2;}
          if(player.hSpeed<0  && player.vSpeed>0 ){player.dir=3;}
          if(player.hSpeed<0  && player.vSpeed==0){player.dir=4;}
          if(player.hSpeed<0  && player.vSpeed<0 ){player.dir=5;}
          if(player.hSpeed==0 && player.vSpeed<0 ){player.dir=6;}
          if(player.hSpeed>0  && player.vSpeed<0 ){player.dir=7;}
        }
      }
    break;
  }
}

//##################################################################
//##################################################################
void fnctn_initPlayer(){
  switch(lvl){
    case 0:
    player.x_world=65;
    player.y_world=43;
    break;

    case 1:
    player.x_world=572;
    player.y_world=593;
    break;
  }

  player.altitude=0;
  player.dir=0;
  
  player.hSpeed = 0;
  player.vSpeed = 0;
  
  player.isLanding=1;
  player.isCrashing=0;
  
  player.life=MAXLIFE-MAXFUEL;
  player.fuel=1;
  player.fuelCheck = 0;
  player.fire=0;
  
  player.animHelix=0;
  player.animBoom = 0;

  player.moveMode = 0; //0rotate //1straff

  for(i=0;i<MAXBULLET;i++){
    bullet[i].x_world=0;
    bullet[i].y_world=0;
    bullet[i].dir=0;
    bullet[i].distance=0;
  }
}

//##################################################################
//##################################################################
void fnctn_initLevel(){
  destroyedBuildings=0;
  money=0;
  
  switch(lvl){
    case 0:
    nbHeliport=5;
    nbBuilding_Friend=9;
    nbBuilding_Hostile = 21;

    //background
    bkg[0].x_world=22;   bkg[0].y_world=16;   bkg[0].sprite=3;
    bkg[1].x_world=30;   bkg[1].y_world=21;   bkg[1].sprite=3;
    bkg[2].x_world=22;   bkg[2].y_world=26;   bkg[2].sprite=3;
    bkg[3].x_world=77;   bkg[3].y_world=11;   bkg[3].sprite=3;
    bkg[4].x_world=43;   bkg[4].y_world=45;   bkg[4].sprite=3;
    bkg[5].x_world=82;   bkg[5].y_world=48;   bkg[5].sprite=3;
    bkg[6].x_world=27;   bkg[6].y_world=81;   bkg[6].sprite=3;
    bkg[7].x_world=36;   bkg[7].y_world=85;   bkg[7].sprite=3;
    bkg[8].x_world=28;   bkg[8].y_world=91;   bkg[8].sprite=3;
    bkg[9].x_world=103;  bkg[9].y_world=116;  bkg[9].sprite=3;
    bkg[10].x_world=64;  bkg[10].y_world=30;  bkg[10].sprite=0;
    bkg[11].x_world=14;  bkg[11].y_world=64;  bkg[11].sprite=0;
    bkg[12].x_world=53;  bkg[12].y_world=119; bkg[12].sprite=0;
    bkg[13].x_world=4;   bkg[13].y_world=3;   bkg[13].sprite=1;
    bkg[14].x_world=89;  bkg[14].y_world=73;  bkg[14].sprite=1;
    bkg[15].x_world=98;  bkg[15].y_world=80;  bkg[15].sprite=1;
    bkg[16].x_world=84;  bkg[16].y_world=84;  bkg[16].sprite=5;
    bkg[17].x_world=7;   bkg[17].y_world=109; bkg[17].sprite=4;
    bkg[18].x_world=110; bkg[18].y_world=26;  bkg[18].sprite=4;

    //building not shooting / not destructible
    bkgrnd[0].x_world=60;     bkgrnd[0].y_world=40;     bkgrnd[0].width=13;   bkgrnd[0].height=7;   bkgrnd[0].sprite=0;   //heliport
    bkgrnd[1].x_world=593;    bkgrnd[1].y_world=57;     bkgrnd[1].width=13;   bkgrnd[1].height=7;   bkgrnd[1].sprite=0;
    bkgrnd[2].x_world=395;    bkgrnd[2].y_world=133;    bkgrnd[2].width=13;   bkgrnd[2].height=7;   bkgrnd[2].sprite=0;
    bkgrnd[3].x_world=258;    bkgrnd[3].y_world=294;    bkgrnd[3].width=13;   bkgrnd[3].height=7;   bkgrnd[3].sprite=0;
    bkgrnd[4].x_world=46;     bkgrnd[4].y_world=567;    bkgrnd[4].width=13;   bkgrnd[4].height=7;   bkgrnd[4].sprite=0;
    bkgrnd[5].x_world=57;     bkgrnd[5].y_world=19;     bkgrnd[5].width=19;   bkgrnd[5].height=15;  bkgrnd[5].sprite=1;   //basecamp
    bkgrnd[6].x_world=24;     bkgrnd[6].y_world=27;     bkgrnd[6].width=32;   bkgrnd[6].height=29;  bkgrnd[6].sprite=2;   //fuel
    bkgrnd[7].x_world=10;     bkgrnd[7].y_world=550;    bkgrnd[7].width=32;   bkgrnd[7].height=29;  bkgrnd[7].sprite=2;
    bkgrnd[8].x_world=385;    bkgrnd[8].y_world=103;    bkgrnd[8].width=32;   bkgrnd[8].height=29;  bkgrnd[8].sprite=2;
    bkgrnd[9].x_world=77;     bkgrnd[9].y_world=33;     bkgrnd[9].width=25;   bkgrnd[9].height=26;  bkgrnd[9].sprite=3;   //garage
    bkgrnd[10].x_world=589;   bkgrnd[10].y_world=26;    bkgrnd[10].width=25;  bkgrnd[10].height=26; bkgrnd[10].sprite=3;
    bkgrnd[11].x_world=274;   bkgrnd[11].y_world=287;   bkgrnd[11].width=25;  bkgrnd[11].height=26; bkgrnd[11].sprite=3;
    bkgrnd[12].x_world=253;   bkgrnd[12].y_world=159;   bkgrnd[12].width=36;  bkgrnd[12].height=24; bkgrnd[12].sprite=9; //oasis
    bkgrnd[13].x_world=152;   bkgrnd[13].y_world=414;   bkgrnd[13].width=36;  bkgrnd[13].height=24; bkgrnd[13].sprite=9;
    bkgrnd[14].x_world=526;   bkgrnd[14].y_world=284;   bkgrnd[14].width=36;  bkgrnd[14].height=24; bkgrnd[14].sprite=9;

    //building not shooting / destructible
    building_friend[0].x_world=31;      building_friend[0].y_world=72;  //village
    building_friend[1].x_world=538;     building_friend[1].y_world=73;
    building_friend[2].x_world=16;      building_friend[2].y_world=580;
    building_friend[3].x_world=289;     building_friend[3].y_world=164; //camp
    building_friend[4].x_world=568;     building_friend[4].y_world=276;
    building_friend[5].x_world=381;     building_friend[5].y_world=456;
    building_friend[6].x_world=600;     building_friend[6].y_world=517;
    building_friend[7].x_world=533;     building_friend[7].y_world=532;
    building_friend[8].x_world=511;     building_friend[8].y_world=600;
    for(i=0;i<9;i++){
      building_friend[i].animBoom=0;
      if(i<3){ //village
        building_friend[i].width=72;      
        building_friend[i].height=41;   
        building_friend[i].sprite=4;     
        building_friend[i].life = 80;
      }else{   //camp
        building_friend[i].width=16;      
        building_friend[i].height=22;   
        building_friend[i].sprite=7;  
        building_friend[i].life = 20;
      }
    }

    //building shooting / destructible
    building_hostile[0].x_world=95;    building_hostile[0].y_world=286;   //tours
    building_hostile[1].x_world=77;    building_hostile[1].y_world=324;   
    building_hostile[2].x_world=117;   building_hostile[2].y_world=344;   
    building_hostile[3].x_world=134;   building_hostile[3].y_world=304;   
    building_hostile[4].x_world=381;   building_hostile[4].y_world=38;    
    building_hostile[5].x_world=436;   building_hostile[5].y_world=21;    
    building_hostile[6].x_world=417;   building_hostile[6].y_world=77;    
    building_hostile[7].x_world=397;   building_hostile[7].y_world=396;   
    building_hostile[8].x_world=378;   building_hostile[8].y_world=428;   
    building_hostile[9].x_world=413;   building_hostile[9].y_world=456;   
    building_hostile[10].x_world=451;  building_hostile[10].y_world=424;  
    building_hostile[11].x_world=436;  building_hostile[11].y_world=399;  
    building_hostile[12].x_world=608;  building_hostile[12].y_world=552;  
    building_hostile[13].x_world=586;  building_hostile[13].y_world=554;  
    building_hostile[14].x_world=556;  building_hostile[14].y_world=564;  
    building_hostile[15].x_world=550;  building_hostile[15].y_world=585;  
    building_hostile[16].x_world=547;  building_hostile[16].y_world=609;  
    building_hostile[17].x_world=94;   building_hostile[17].y_world=302;  //bunker
    building_hostile[18].x_world=401;  building_hostile[18].y_world=36;
    building_hostile[19].x_world=401;  building_hostile[19].y_world=411;
    building_hostile[20].x_world=577;  building_hostile[20].y_world=584;
    for(i=0;i<21;i++){
      building_hostile[i].animBoom=0;
      building_hostile[i].fireTimer = 0;
      if(i<17){
        building_hostile[i].width=7;
        building_hostile[i].height=10;   
        building_hostile[i].sprite=8;  
        building_hostile[i].life = 20;   
      }else{
        building_hostile[i].width=32; 
        building_hostile[i].height=32;  
        building_hostile[i].sprite=6;   
        building_hostile[i].life = 80;  
      }
    }

    if(difficulty>0){
      //mobile ennemies
      mobilUnit_hostile[0].x_world=572;  mobilUnit_hostile[0].y_world=123;   mobilUnit_hostile[0].batiment=1; //infantry
      mobilUnit_hostile[1].x_world=309;  mobilUnit_hostile[1].y_world=166;   mobilUnit_hostile[1].batiment=3;
      mobilUnit_hostile[2].x_world=294;  mobilUnit_hostile[2].y_world=191;   mobilUnit_hostile[2].batiment=3;
      mobilUnit_hostile[3].x_world=586;  mobilUnit_hostile[3].y_world=275;   mobilUnit_hostile[3].batiment=4;
      mobilUnit_hostile[4].x_world=579;  mobilUnit_hostile[4].y_world=300;   mobilUnit_hostile[4].batiment=4;
      mobilUnit_hostile[5].x_world=366;  mobilUnit_hostile[5].y_world=455;   mobilUnit_hostile[5].batiment=5;
      mobilUnit_hostile[6].x_world=389;  mobilUnit_hostile[6].y_world=483;   mobilUnit_hostile[6].batiment=5;
      mobilUnit_hostile[7].x_world=617;  mobilUnit_hostile[7].y_world=520;   mobilUnit_hostile[7].batiment=6;
      mobilUnit_hostile[8].x_world=610;  mobilUnit_hostile[8].y_world=541;   mobilUnit_hostile[8].batiment=6;
      mobilUnit_hostile[9].x_world=550;  mobilUnit_hostile[9].y_world=535;   mobilUnit_hostile[9].batiment=7;
      mobilUnit_hostile[10].x_world=544; mobilUnit_hostile[10].y_world=558;  mobilUnit_hostile[10].batiment=7;
      mobilUnit_hostile[11].x_world=519; mobilUnit_hostile[11].y_world=592;  mobilUnit_hostile[11].batiment=8;
      mobilUnit_hostile[12].x_world=528; mobilUnit_hostile[12].y_world=603;  mobilUnit_hostile[12].batiment=8;
      mobilUnit_hostile[13].x_world=93;  mobilUnit_hostile[13].y_world=586;  mobilUnit_hostile[13].batiment=2;
      mobilUnit_hostile[14].x_world=345; mobilUnit_hostile[14].y_world=540;  mobilUnit_hostile[14].batiment=2;
      mobilUnit_hostile[15].x_world=379; mobilUnit_hostile[15].y_world=23;   mobilUnit_hostile[0].batiment=18; //tank
      mobilUnit_hostile[16].x_world=73;  mobilUnit_hostile[16].y_world=284;  mobilUnit_hostile[0].batiment=17;
      mobilUnit_hostile[17].x_world=411; mobilUnit_hostile[17].y_world=398;  mobilUnit_hostile[0].batiment=19;
      mobilUnit_hostile[18].x_world=279; mobilUnit_hostile[18].y_world=544;  mobilUnit_hostile[0].batiment=20;
      mobilUnit_hostile[19].x_world=576; mobilUnit_hostile[19].y_world=531;  mobilUnit_hostile[0].batiment=20;
      for(i=0;i<20;i++){
        mobilUnit_hostile[i].animBoom=0;
        mobilUnit_hostile[i].fireTimer=0;  
        mobilUnit_hostile[i].dir=4;
        if(i<15){
          mobilUnit_hostile[i].width=6;  
          mobilUnit_hostile[i].height=6;  
          mobilUnit_hostile[i].sprite=0;  
          mobilUnit_hostile[i].life=5;   
        }else{
          mobilUnit_hostile[i].width=16;  
          mobilUnit_hostile[i].height=14;  
          mobilUnit_hostile[i].sprite=1;   
          mobilUnit_hostile[i].life=30;  
        }
      }
    }
  break;


  case 1:
    nbHeliport=5;
    nbBuilding_Friend=9;
    nbBuilding_Hostile = 21;

    //background
    bkg[0].x_world=55;   bkg[0].y_world=40;   bkg[0].sprite=6;  //grass
    bkg[1].x_world=78;   bkg[1].y_world=37;   bkg[1].sprite=6;
    bkg[2].x_world=72;   bkg[2].y_world=58;   bkg[2].sprite=6;
    bkg[3].x_world=52;   bkg[3].y_world=92;   bkg[3].sprite=6;
    bkg[4].x_world=105;  bkg[4].y_world=108;  bkg[4].sprite=6;
    bkg[5].x_world=19;   bkg[5].y_world=16;   bkg[5].sprite=5;  //rock
    bkg[6].x_world=89;   bkg[6].y_world=23;   bkg[6].sprite=5;
    bkg[7].x_world=4;    bkg[7].y_world=111;  bkg[7].sprite=5;
    bkg[8].x_world=5;    bkg[8].y_world=72;   bkg[8].sprite=7;  //tree (small one)
    bkg[9].x_world=105;  bkg[9].y_world=64;   bkg[9].sprite=7;
    bkg[10].x_world=49;  bkg[10].y_world=11;  bkg[10].sprite=8; //tree (normal one)
    bkg[11].x_world=2;   bkg[11].y_world=33;  bkg[11].sprite=8;
    bkg[12].x_world=103; bkg[12].y_world=39;  bkg[12].sprite=8;
    bkg[13].x_world=34;  bkg[13].y_world=55;  bkg[13].sprite=8;
    bkg[14].x_world=75;  bkg[14].y_world=82;  bkg[14].sprite=8;
    bkg[15].x_world=26;  bkg[15].y_world=95;  bkg[15].sprite=8;
    bkg[16].x_world=3;   bkg[16].y_world=9;   bkg[16].sprite=9; //tree (big one)
    bkg[17].x_world=33;  bkg[17].y_world=29;  bkg[17].sprite=9;
    bkg[18].x_world=11;  bkg[18].y_world=51;  bkg[18].sprite=9;

    //building not shooting / not destructible
    bkgrnd[0].x_world=567;    bkgrnd[0].y_world=590;    bkgrnd[0].width=13;   bkgrnd[0].height=7;   bkgrnd[5].sprite=0;   //heliport
    bkgrnd[1].x_world=273;    bkgrnd[1].y_world=92;     bkgrnd[1].width=13;   bkgrnd[1].height=7;   bkgrnd[5].sprite=0;
    bkgrnd[2].x_world=569;    bkgrnd[2].y_world=31;     bkgrnd[2].width=13;   bkgrnd[2].height=7;   bkgrnd[5].sprite=0;
    bkgrnd[3].x_world=31;     bkgrnd[3].y_world=344;    bkgrnd[3].width=13;   bkgrnd[3].height=7;   bkgrnd[5].sprite=0;
    bkgrnd[4].x_world=58;     bkgrnd[4].y_world=600;    bkgrnd[4].width=13;   bkgrnd[4].height=7;   bkgrnd[5].sprite=0;
    bkgrnd[5].x_world=565;    bkgrnd[5].y_world=571;    bkgrnd[5].width=19;   bkgrnd[5].height=15;  bkgrnd[5].sprite=1;   //base
    bkgrnd[6].x_world=544;    bkgrnd[6].y_world=595;    bkgrnd[6].width=32;   bkgrnd[6].height=29;  bkgrnd[6].sprite=2;   //fuel
    bkgrnd[7].x_world=536;    bkgrnd[7].y_world=18;     bkgrnd[7].width=32;   bkgrnd[7].height=29;  bkgrnd[7].sprite=2;
    bkgrnd[8].x_world=23;     bkgrnd[8].y_world=584;    bkgrnd[8].width=32;   bkgrnd[8].height=29;  bkgrnd[8].sprite=2;
    bkgrnd[9].x_world=585;    bkgrnd[9].y_world=597;    bkgrnd[9].width=25;   bkgrnd[9].height=26;  bkgrnd[9].sprite=3;   //garage
    bkgrnd[10].x_world=292;   bkgrnd[10].y_world=85;    bkgrnd[10].width=25;  bkgrnd[10].height=26; bkgrnd[10].sprite=3;
    bkgrnd[11].x_world=47;    bkgrnd[11].y_world=336;   bkgrnd[11].width=25;  bkgrnd[11].height=26; bkgrnd[11].sprite=3;
    bkgrnd[12].x_world=169;   bkgrnd[12].y_world=465;   bkgrnd[12].width=36;  bkgrnd[12].height=24; bkgrnd[12].sprite=10;  //oasis
    bkgrnd[13].x_world=147;   bkgrnd[13].y_world=211;   bkgrnd[13].width=36;  bkgrnd[13].height=24; bkgrnd[13].sprite=10;
    bkgrnd[14].x_world=394;   bkgrnd[14].y_world=339;   bkgrnd[14].width=36;  bkgrnd[14].height=24; bkgrnd[14].sprite=10;

    //building not shooting / destructible
    building_friend[0].x_world=395;     building_friend[0].y_world=577; //village
    building_friend[1].x_world=36;      building_friend[1].y_world=81;
    building_friend[2].x_world=535;     building_friend[2].y_world=91;
    building_friend[3].x_world=122;     building_friend[3].y_world=8;   //camp
    building_friend[4].x_world=372;     building_friend[4].y_world=7;
    building_friend[5].x_world=372;     building_friend[5].y_world=133;
    building_friend[6].x_world=247;     building_friend[6].y_world=257;
    building_friend[7].x_world=372;     building_friend[7].y_world=382;
    building_friend[8].x_world=123;     building_friend[8].y_world=507;
    for(i=0;i<9;i++){
      building_friend[i].animBoom=0;
      if(i<3){ //village
        building_friend[i].width=72;      
        building_friend[i].height=41;   
        building_friend[i].sprite=5;     
        building_friend[i].life = 80;
      }else{   //camp
        building_friend[i].width=16;      
        building_friend[i].height=22;   
        building_friend[i].sprite=7;  
        building_friend[i].life = 20;
      }
    }

    

    //building shooting / destructible
    building_hostile[0].x_world=3;     building_hostile[0].y_world=16;    //tours
    building_hostile[1].x_world=43;    building_hostile[1].y_world=2;   
    building_hostile[2].x_world=59;    building_hostile[2].y_world=51;   
    building_hostile[3].x_world=73;    building_hostile[3].y_world=35;   
    building_hostile[4].x_world=177;   building_hostile[4].y_world=97; 
    building_hostile[5].x_world=406;   building_hostile[5].y_world=86;    
    building_hostile[6].x_world=423;   building_hostile[6].y_world=70;    
    building_hostile[7].x_world=463;   building_hostile[7].y_world=107;
    building_hostile[8].x_world=435;   building_hostile[8].y_world=225;   
    building_hostile[9].x_world=132;   building_hostile[9].y_world=279;   
    building_hostile[10].x_world=272;  building_hostile[10].y_world=352;  
    building_hostile[11].x_world=314;  building_hostile[11].y_world=325;  
    building_hostile[12].x_world=335;  building_hostile[12].y_world=362;
    building_hostile[13].x_world=17;   building_hostile[13].y_world=433;  
    building_hostile[14].x_world=126;  building_hostile[14].y_world=389;  
    building_hostile[15].x_world=98;   building_hostile[15].y_world=453;  
    building_hostile[16].x_world=4;    building_hostile[16].y_world=515;  
    building_hostile[17].x_world=36;   building_hostile[17].y_world=14;   //bunker
    building_hostile[18].x_world=46;   building_hostile[18].y_world=462;
    building_hostile[19].x_world=298;  building_hostile[19].y_world=337;
    building_hostile[20].x_world=422;  building_hostile[20].y_world=85;
    for(i=0;i<21;i++){
      building_hostile[i].animBoom=0;
      building_hostile[i].fireTimer = 0;
      if(i<17){
        building_hostile[i].width=7;
        building_hostile[i].height=10;   
        building_hostile[i].sprite=8;  
        building_hostile[i].life = 20;   
      }else{
        building_hostile[i].width=32; 
        building_hostile[i].height=32;  
        building_hostile[i].sprite=6;   
        building_hostile[i].life = 80;  
      }
    }

    if(difficulty>0){
      //mobile ennemies
      mobilUnit_hostile[0].x_world=572; mobilUnit_hostile[0].y_world=123;   mobilUnit_hostile[0].batiment=1;  //infantry
      mobilUnit_hostile[1].x_world=309; mobilUnit_hostile[1].y_world=166;   mobilUnit_hostile[1].batiment=3;
      mobilUnit_hostile[2].x_world=294; mobilUnit_hostile[2].y_world=191;   mobilUnit_hostile[2].batiment=3;
      mobilUnit_hostile[3].x_world=586; mobilUnit_hostile[3].y_world=275;   mobilUnit_hostile[3].batiment=4;
      mobilUnit_hostile[4].x_world=579; mobilUnit_hostile[4].y_world=300;   mobilUnit_hostile[4].batiment=4;
      mobilUnit_hostile[5].x_world=366; mobilUnit_hostile[5].y_world=455;   mobilUnit_hostile[5].batiment=5;
      mobilUnit_hostile[6].x_world=389; mobilUnit_hostile[6].y_world=483;   mobilUnit_hostile[6].batiment=5;
      mobilUnit_hostile[7].x_world=617; mobilUnit_hostile[7].y_world=520;   mobilUnit_hostile[7].batiment=6;
      mobilUnit_hostile[8].x_world=610; mobilUnit_hostile[8].y_world=541;   mobilUnit_hostile[8].batiment=6;
      mobilUnit_hostile[9].x_world=550; mobilUnit_hostile[9].y_world=535;   mobilUnit_hostile[9].batiment=7;
      mobilUnit_hostile[10].x_world=544; mobilUnit_hostile[10].y_world=558; mobilUnit_hostile[10].batiment=7;
      mobilUnit_hostile[11].x_world=519; mobilUnit_hostile[11].y_world=592; mobilUnit_hostile[11].batiment=8;
      mobilUnit_hostile[12].x_world=528; mobilUnit_hostile[12].y_world=603; mobilUnit_hostile[12].batiment=8;
      mobilUnit_hostile[13].x_world=93;  mobilUnit_hostile[13].y_world=586; mobilUnit_hostile[13].batiment=2;
      mobilUnit_hostile[14].x_world=345; mobilUnit_hostile[14].y_world=540; mobilUnit_hostile[14].batiment=2;
      mobilUnit_hostile[15].x_world=379; mobilUnit_hostile[15].y_world=23;   mobilUnit_hostile[0].batiment=18;  //tank
      mobilUnit_hostile[16].x_world=73;  mobilUnit_hostile[16].y_world=284;  mobilUnit_hostile[0].batiment=17;
      mobilUnit_hostile[17].x_world=411; mobilUnit_hostile[17].y_world=398;  mobilUnit_hostile[0].batiment=19;
      mobilUnit_hostile[18].x_world=279; mobilUnit_hostile[18].y_world=544;  mobilUnit_hostile[0].batiment=20;
      mobilUnit_hostile[19].x_world=576; mobilUnit_hostile[19].y_world=531;  mobilUnit_hostile[0].batiment=20;
      for(i=0;i<20;i++){
        mobilUnit_hostile[i].animBoom=0;
        mobilUnit_hostile[i].fireTimer=0;  
        mobilUnit_hostile[i].dir=4;
        if(i<15){
          mobilUnit_hostile[i].width=6;  
          mobilUnit_hostile[i].height=6;  
          mobilUnit_hostile[i].sprite=0;  
          mobilUnit_hostile[i].life=5;   
        }else{
          mobilUnit_hostile[i].width=16;  
          mobilUnit_hostile[i].height=14;  
          mobilUnit_hostile[i].sprite=1;   
          mobilUnit_hostile[i].life=30;  
        }
      }
    }
  break;   
  }
}




//##################################################################
//##################################################################
void fnctn_moveunit(byte i){
  if(mobilUnit_hostile[i].life>0){
    check02=8;
    
    if(mobilUnit_hostile[i].x_world+ (mobilUnit_hostile[i].width/2)>player.x_world+10){
      mobilUnit_hostile[i].x_world--;
      mobilUnit_hostile[i].dir=4;
      check02=4;
    }

    if(mobilUnit_hostile[i].x_world+ (mobilUnit_hostile[i].width/2)<player.x_world-10){
      mobilUnit_hostile[i].x_world++;
      mobilUnit_hostile[i].dir=0;
      check02=0;
    } 

    if(mobilUnit_hostile[i].y_world+ (mobilUnit_hostile[i].height/2)<player.y_world-8){
      mobilUnit_hostile[i].y_world++;
      switch(check02){
        case 0: mobilUnit_hostile[i].dir=1; break;
        case 4: mobilUnit_hostile[i].dir=3; break;
        case 8: mobilUnit_hostile[i].dir=2; break;
      }
    }

    if(mobilUnit_hostile[i].y_world+ (mobilUnit_hostile[i].height/2)>player.y_world+8){
      mobilUnit_hostile[i].y_world--;
      switch(check02){
        case 0: mobilUnit_hostile[i].dir=7; break;
        case 4: mobilUnit_hostile[i].dir=5; break;
        case 8: mobilUnit_hostile[i].dir=6; break;
      }
    }
  }
}



//##################################################################
//##################################################################
void fnctn_initEnnemyFire(){
  //move bullets
  for(j=0;j<MAXBULLET;j++){
    if(bullet[j].distance>0){
      switch(bullet[j].dir){
        case 0: bullet[j].x_world=bullet[j].x_world+2; break;
        case 1: bullet[j].x_world+=1; bullet[j].y_world+=1; break;
        case 2: bullet[j].y_world=bullet[j].y_world+2; break;
        case 3: bullet[j].x_world-=1; bullet[j].y_world+=1; break;
        case 4: bullet[j].x_world=bullet[j].x_world-2; break;
        case 5: bullet[j].x_world-=1; bullet[j].y_world-=1; break;
        case 6: bullet[j].y_world=bullet[j].y_world-2; break;
        case 7: bullet[j].x_world+=1; bullet[j].y_world-=1; break;  
      }
      bullet[j].distance++;
      if(bullet[j].distance>30){
        building_hostile[bullet[j].shooter].fireTimer=0;
        bullet[j].x_world=0;
        bullet[j].y_world=0;
        bullet[j].dir=0;
        bullet[j].distance=0;
      }
    }
  }

  //define new
  for(i=0;i<nbBuilding_Hostile;i++){
    coordx = building_hostile[i].x_world+ (building_hostile[i].width/2);
    coordy = building_hostile[i].y_world+ (building_hostile[i].height/2);
    if(abs(player.x_world-coordx)<75 && abs(player.y_world-coordy)<75 && building_hostile[i].fireTimer<1 && building_hostile[i].life>0){
      check01=0;
      for(j=0;j<MAXBULLET;j++){
        if(bullet[j].distance==0 && check01==0){
          check01=1;
          building_hostile[i].fireTimer=20;
          switch(building_hostile[i].sprite){
            case 6 : building_hostile[i].fireTimer=TMPBUNKER; break; //bunker
            case 7 : building_hostile[i].fireTimer=TMPTOUR; break; //tour
          }
          bullet[j].shooter=i;
          bullet[j].x_world=coordx;
          bullet[j].y_world=coordy;
          bullet[j].distance=1;
          bullet[j].dir=0;
          if(player.x_world>coordx+5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=1;}
          if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude>coordy)   {bullet[j].dir=2;}
          if(player.x_world<coordx-5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=3;}
          if(player.x_world<coordx   && player.y_world-player.altitude>coordy-6 && player.y_world-player.altitude<coordy+6){bullet[j].dir=4;}
          if(player.x_world<coordx-5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=5;}
          if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude<coordy-6) {bullet[j].dir=6;}
          if(player.x_world>coordx+5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=7;}
        }
      }
    }
  }

  if(difficulty>0){
    for(i=0;i<20;i++){
      coordx = mobilUnit_hostile[i].x_world+ (mobilUnit_hostile[i].width/2);
      coordy = mobilUnit_hostile[i].y_world+ (mobilUnit_hostile[i].height/2);
      if(abs(player.x_world-coordx)<75 && abs(player.y_world-coordy)<75 && mobilUnit_hostile[i].fireTimer<1 && mobilUnit_hostile[i].life>0){
        check01=0;
        for(j=0;j<MAXBULLET;j++){
          if(bullet[j].distance==0 && check01==0){
            check01=1;
            bullet[j].shooter=i;
            bullet[j].x_world=coordx;
            bullet[j].y_world=coordy;
            bullet[j].distance=1;
            switch (mobilUnit_hostile[i].sprite){
              case 0: //unit
                mobilUnit_hostile[i].fireTimer=TMPUNIT;
                bullet[j].dir=0;
                if(player.x_world>coordx+5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=1;}
                if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude>coordy)   {bullet[j].dir=2;}
                if(player.x_world<coordx-5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=3;}
                if(player.x_world<coordx   && player.y_world-player.altitude>coordy-6 && player.y_world-player.altitude<coordy+6){bullet[j].dir=4;}
                if(player.x_world<coordx-5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=5;}
                if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude<coordy-6) {bullet[j].dir=6;}
                if(player.x_world>coordx+5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=7;}
              break;
  
              case 1: //tank
                mobilUnit_hostile[i].fireTimer=TMPTANK;
                bullet[j].dir=mobilUnit_hostile[i].dir;
                bullet[j].y_world=bullet[j].y_world-5;
              break;
            }
          }
        }
      }
    }
  }
}



//##################################################################
//##################################################################
void fnctn_checkEnnemyFire(){
  if(player.animDamage==0){
    for(j=0;j<MAXBULLET;j++){
      if(bullet[j].x_world>player.x_world-4 && bullet[j].x_world<player.x_world+4 && bullet[j].y_world>player.y_world-player.altitude-6 && bullet[j].y_world<player.y_world-player.altitude+2){
        if(player.life>0){player.life=player.life -5;}
        if(player.life<=0){
          player.isCrashing=1;
        }else{
          player.animDamage = 12;
          player.isLanding=0;
        }
      }
    }
  }
}

//##################################################################
//##################################################################
void fnctn_resurection(){
  for(i=0;i<15;i++){
    if(mobilUnit_hostile[i].batiment!=0 && mobilUnit_hostile[i].life==0 && mobilUnit_hostile[i].animBoom==TMPRESURECTION){

      if(mobilUnit_hostile[i].sprite==0){
        if(building_friend[mobilUnit_hostile[i].batiment].life > 0){
          mobilUnit_hostile[i].life=5;
          mobilUnit_hostile[i].animBoom=0;
          mobilUnit_hostile[i].x_world = building_friend[mobilUnit_hostile[i].batiment].x_world + (building_friend[mobilUnit_hostile[i].batiment].width/2);
          mobilUnit_hostile[i].y_world = building_friend[mobilUnit_hostile[i].batiment].y_world + (building_friend[mobilUnit_hostile[i].batiment].height/2);
        }
      }

      if(mobilUnit_hostile[i].sprite==1){
        if(building_hostile[mobilUnit_hostile[i].batiment].life > 0){
          mobilUnit_hostile[i].life=30;
          mobilUnit_hostile[i].animBoom=0;
          mobilUnit_hostile[i].x_world = building_hostile[mobilUnit_hostile[i].batiment].x_world + (building_hostile[mobilUnit_hostile[i].batiment].width/2);
          mobilUnit_hostile[i].y_world = building_hostile[mobilUnit_hostile[i].batiment].y_world + building_hostile[mobilUnit_hostile[i].batiment].height + 5;
        }
      }    
    }
  }
}

//##################################################################
//##################################################################
void fnctn_checkPlayerAltitude(){
  switch(player.isLanding){
    case 0: if(player.altitude<MAXALTITUDE && player.isCrashing==0){player.altitude++;} break;
    case 1: if(player.altitude>0){player.altitude--;} break;
  }
  if(player.isCrashing==1 && player.altitude>0) {
    player.dir = (player.dir + 1)%8;
    player.altitude --;
  }
}


//##################################################################
//##################################################################
void fnctn_checkPlayerFire(){
  if(player.fire==1){
    switch(player.dir){
      case 0 : coordx=player.x_world+16;  coordy=player.y_world;    break;
      case 1 : coordx=player.x_world+8;   coordy=player.y_world+5;  break;
      case 2 : coordx=player.x_world;     coordy=player.y_world+8;  break;
      case 3 : coordx=player.x_world-8;   coordy=player.y_world+5;  break;
      case 4 : coordx=player.x_world-16;  coordy=player.y_world;    break;
      case 5 : coordx=player.x_world-8;   coordy=player.y_world-5;  break;
      case 6 : coordx=player.x_world;     coordy=player.y_world-8;  break;
      case 7 : coordx=player.x_world+8;   coordy=player.y_world-5;  break;
    }
    for(i=0;i<nbBuilding_Hostile;i++){
      if(coordx>building_hostile[i].x_world && coordx<building_hostile[i].x_world+building_hostile[i].width && coordy>building_hostile[i].y_world && coordy<building_hostile[i].y_world+building_hostile[i].height){
        if(building_hostile[i].life>0){
          building_hostile[i].life--;
          if(building_hostile[i].life==0 && building_hostile[i].animBoom==0){
            destroyedBuildings = destroyedBuildings+1;
            switch(building_hostile[i].sprite){
              case 8: money = money + 250; break;  //tour
              case 6: money = money + 1000; break; //bunker
            }
          }
        }
      }
    }
    for(i=0;i<nbBuilding_Friend;i++){
      if(coordx>building_friend[i].x_world && coordx<building_friend[i].x_world+building_friend[i].width && coordy>building_friend[i].y_world && coordy<building_friend[i].y_world+building_friend[i].height){
        if(building_friend[i].life>0){
          building_friend[i].life--;
          if(building_friend[i].life==0 && difficulty==2 && building_friend[i].animBoom==0){
            switch(building_friend[i].sprite){
               case 4: money = money + 200; break; //village
               case 7: money = money + 350; break; //camp
               case 9: money = money + 200; break; //village
            }
          }
        }
      }
    }

    if(difficulty>0){
      for(i=0;i<20;i++){
        if(coordx>mobilUnit_hostile[i].x_world && coordx<mobilUnit_hostile[i].x_world+mobilUnit_hostile[i].width && coordy>mobilUnit_hostile[i].y_world && coordy<mobilUnit_hostile[i].y_world+mobilUnit_hostile[i].height){
          if(mobilUnit_hostile[i].life>0){
            mobilUnit_hostile[i].life--;
            if(mobilUnit_hostile[i].life==0 && difficulty==1 && mobilUnit_hostile[i].animBoom==0){
            switch(building_friend[i].sprite){
               case 0: money = money + 50; break;  //unit
               case 1: money = money + 100; break; //tank
            }
          }
          
          }
        }
      }
    }    
  }
}

//##################################################################
//##################################################################
void fnctn_checkLanding(){
  if(player.vSpeed==0    && player.hSpeed==0   && player.isLanding==0){
    switch(lvl){
      case 0:
        for(i=0;i<nbHeliport;i++){
          if(player.x_world>bkgrnd[i].x_world   && player.x_world<bkgrnd[i].x_world+bkgrnd[i].width     && player.y_world>bkgrnd[i].y_world     && player.y_world<bkgrnd[i].y_world+bkgrnd[i].height){
            switch(i){
              case 0: if(player.life<MAXLIFE-1 || player.fuel<MAXFUEL-1){player.isLanding=1;} break;
              case 1: if(player.life<MAXLIFE-1){player.isLanding=1;} break;
              case 2: if(player.fuel<MAXFUEL-1){player.isLanding=1;} break;
              case 3: if(player.life<MAXLIFE-1){player.isLanding=1;} break;
              case 4: if(player.fuel<MAXFUEL-1){player.isLanding=1;} break;
            }
          }
        }
      break;
      
      case 1:
        for(i=0;i<nbHeliport;i++){
          if(player.x_world>bkgrnd[i].x_world   && player.x_world<bkgrnd[i].x_world+bkgrnd[i].width     && player.y_world>bkgrnd[i].y_world     && player.y_world<bkgrnd[i].y_world+bkgrnd[i].height){
            switch(i){
              case 0: if(player.life<MAXLIFE-1 || player.fuel<MAXFUEL-1){player.isLanding=1;} break;
              case 1: if(player.life<MAXLIFE-1){player.isLanding=1;} break;
              case 2: if(player.fuel<MAXFUEL-1){player.isLanding=1;} break;
              case 3: if(player.life<MAXLIFE-1){player.isLanding=1;} break;
              case 4: if(player.fuel<MAXFUEL-1){player.isLanding=1;} break;
            }
          }
        }
      break;
    }
  }

  if(player.isLanding==1 && player.altitude==0){
    switch(lvl){
      case 0:
        for(i=0;i<nbHeliport;i++){
          if(player.x_world>bkgrnd[i].x_world   && player.x_world<bkgrnd[i].x_world+bkgrnd[i].width     && player.y_world>bkgrnd[i].y_world     && player.y_world<bkgrnd[i].y_world+bkgrnd[i].height){
            switch(i){
              case 0: 
              if(destroyedBuildings==nbBuilding_Hostile){
                outpt_Congratulation();
              }else{             
                if(player.life==MAXLIFE && player.fuel==MAXFUEL){player.isLanding=0;}
                else{
                  if(player.life<MAXLIFE){player.life++;} if(player.fuel<MAXFUEL){player.fuel++;} 
                  if(player.life==MAXLIFE && player.fuel==MAXFUEL){
                    if(money<1000){money = 0;}else{money = money-800;}
                  }
                }
              
              } break;
              
              case 1: 
              if(player.life==MAXLIFE){player.isLanding=0;}
              else{
                if(player.life<MAXLIFE){player.life++;}
                if(player.life==MAXLIFE){
                  if(money<750){money = 0;}else{money = money-750;}
                }
              } break;
              
              case 2: 
              if(player.fuel==MAXFUEL){player.isLanding=0;}
              else{
                if(player.fuel<MAXFUEL){player.fuel++;}
                if(player.fuel==MAXFUEL){
                  if(money<750){money = 0;}else{money = money-150;}
                }
              } break;
              
              case 3: 
              if(player.life==MAXLIFE){player.isLanding=0;}
              else{
                if(player.life<MAXLIFE){player.life++;}
                if(player.life==MAXLIFE){
                  if(money<750){money = 0;}else{money = money-750;}
                }
              } break;
              
              case 4: 
              if(player.fuel==MAXFUEL){player.isLanding=0;}
              else{
                if(player.fuel<MAXFUEL){player.fuel++;}
                if(player.fuel==MAXFUEL){
                  if(money<750){money = 0;}else{money = money-150;}
                }
              } break;
            }
          }
        }
      break;

      case 1:
        for(i=0;i<nbHeliport;i++){
          if(player.x_world>bkgrnd[i].x_world   && player.x_world<bkgrnd[i].x_world+bkgrnd[i].width     && player.y_world>bkgrnd[i].y_world     && player.y_world<bkgrnd[i].y_world+bkgrnd[i].height){
            switch(i){
              case 0: if(player.life==MAXLIFE && player.fuel==MAXFUEL){player.isLanding=0;}else{if(player.life<MAXLIFE){player.life++;} if(player.fuel<MAXFUEL){player.fuel++;}} break;
              case 1: if(player.life==MAXLIFE){player.isLanding=0;}else{if(player.life<MAXLIFE){player.life++;}} break;
              case 2: if(player.fuel==MAXFUEL){player.isLanding=0;}else{if(player.fuel<MAXFUEL){player.fuel++;}} break;
              case 3: if(player.life==MAXLIFE){player.isLanding=0;}else{if(player.life<MAXLIFE){player.life++;}} break;
              case 4: if(player.fuel==MAXFUEL){player.isLanding=0;}else{if(player.fuel<MAXFUEL){player.fuel++;}} break;
            }
          }
        }
      break;
    }  
    
  } 
}

//##################################################################
//##################################################################
void fnctn_checkFuel(){
  if(player.altitude>0){
    player.fuelCheck = (player.fuelCheck+1)%100;
    if(player.fuelCheck==0 && player.fuel>0){player.fuel--;}
    if(player.fuel==0){
      player.isCrashing = 1;
      player.isLanding = 1;
    }  
  }
}

//##################################################################
//##################################################################
byte fnctn_playerXpos(int x){
  if(x<SCREENWIDTH/2)                                 {return x;}
  if(x>=SCREENWIDTH/2 && x<=LEVELWIDTH-SCREENWIDTH/2) {return SCREENWIDTH/2;}
  if(x>LEVELWIDTH-SCREENWIDTH/2)                      {return (SCREENWIDTH)-(LEVELWIDTH-x);}
}

//##################################################################
//##################################################################
byte fnctn_playerYpos(int y){
  if(y<SCREENHEIGHT/2+VERTALIGNMENT)                                                {return y;}
  if(y>=SCREENHEIGHT/2+VERTALIGNMENT && y<=LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT){return SCREENHEIGHT/2+VERTALIGNMENT;}
  if(y>LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT)                                    {return (SCREENHEIGHT)-(LEVELHEIGHT-y);}
}

//##################################################################
//##################################################################
int fnctn_backgrndXpos(int x){
  if(player.x_world<SCREENWIDTH/2)                                                {return (x%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
  if(player.x_world>=SCREENWIDTH/2 && player.x_world<=LEVELWIDTH-SCREENWIDTH/2)   {return ((x-(player.x_world-SCREENWIDTH/2))%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
  if(player.x_world>LEVELWIDTH-SCREENWIDTH/2)                                     {return (((SCREENWIDTH)-(LEVELWIDTH-x))%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
}

//##################################################################
//##################################################################
int fnctn_backgrndYpos(int y){
  if(player.y_world<SCREENHEIGHT/2+VERTALIGNMENT)                                                             {return (y%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
  if(player.y_world>=SCREENHEIGHT/2+VERTALIGNMENT && player.y_world<=LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT){return ((y-(player.y_world-(VERTALIGNMENT+SCREENHEIGHT/2)))%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
  if(player.y_world>LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT)                                                 {return (((SCREENHEIGHT)-(LEVELHEIGHT-y))%SPRITESIZE+SPRITESIZE)%SPRITESIZE;}
}

//##################################################################
//##################################################################
int fnctn_lndscapeXpos(int x){
  if(player.x_world<SCREENWIDTH/2)                                                {return x;}
  if(player.x_world>=SCREENWIDTH/2 && player.x_world<=LEVELWIDTH-SCREENWIDTH/2)   {return (x-(player.x_world-SCREENWIDTH/2));}
  if(player.x_world>LEVELWIDTH-SCREENWIDTH/2)                                     {return ((SCREENWIDTH)-(LEVELWIDTH-x));}
}

//##################################################################
//##################################################################
int fnctn_lndscapeYpos(int y){
  if(player.y_world<SCREENHEIGHT/2+VERTALIGNMENT)                                                             {return y;}
  if(player.y_world>=SCREENHEIGHT/2+VERTALIGNMENT && player.y_world<=LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT){return (y-(player.y_world-(VERTALIGNMENT+SCREENHEIGHT/2)));}
  if(player.y_world>LEVELHEIGHT-SCREENHEIGHT/2+VERTALIGNMENT)                                                 {return ((SCREENHEIGHT)-(LEVELHEIGHT-y));}
}

//##################################################################
//##################################################################
void fnctn_animation(){
  if(player.fuel>0 && player.altitude>0){player.animHelix = (player.animHelix+1)%4;}
  cptAnim = (cptAnim +1)%50;
  if(player.isCrashing==1 && player.altitude==0 && player.animBoom<11){player.animBoom++;}
  if(player.animDamage>0){player.animDamage--;}

  for(i=0;i<nbBuilding_Hostile;i++){
    if(building_hostile[i].life == 0 && building_hostile[i].animBoom<12){building_hostile[i].animBoom++;}
    if(building_hostile[i].fireTimer>0){building_hostile[i].fireTimer--;}
  }

  for(i=0;i<nbBuilding_Friend;i++){
    if(building_friend[i].life == 0 && building_friend[i].animBoom<12){building_friend[i].animBoom++;}
  }

  if(difficulty>0){
    for(i=0;i<20;i++){
      if(mobilUnit_hostile[i].life == 0 && mobilUnit_hostile[i].animBoom<TMPRESURECTION+1){mobilUnit_hostile[i].animBoom++;}
      if(mobilUnit_hostile[i].fireTimer>0){mobilUnit_hostile[i].fireTimer--;}
    }
  }
}



