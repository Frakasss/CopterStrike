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
      if(gb.buttons.pressed(BTN_RIGHT)){lvl=(lvl+1)%3;}
      if(gb.buttons.pressed(BTN_LEFT)) {if(lvl==0){lvl=2;}else{lvl=(lvl%3-1);}}
      if(gb.buttons.pressed(BTN_A))    {gameStatus = GAME;fnctn_initLevel(); }
    break;

    case 2:
  
      if(gb.buttons.pressed(BTN_C)){gb.titleScreen(gamelogo);}
    
      if(gb.buttons.pressed(BTN_B)){
        switch(player.isLanding){
          case 0: if(player.hSpeed==0 && player.vSpeed==0 && player.altitude == MAXALTITUDE){player.isLanding = 1;}break;
          case 1: if(player.isCrashing==0){player.isLanding = 0;} break;
        }
      }
    
      if(gb.buttons.repeat(BTN_A,0) && player.isLanding==0 && player.altitude == MAXALTITUDE){
        if(player.ammo>0){
          player.fire = 1;
          player.ammo--;
        }else{
          player.fire = 0;
        }
      }else{
        player.fire = 0;
        if(player.ammo<50){player.ammo++;}
      }
    
    
      if(player.isLanding==0){
        if(gb.buttons.repeat(BTN_RIGHT,0)){
          if(player.hSpeed<player.maxSpeed){player.hSpeed++;}
        }else if(gb.buttons.repeat(BTN_LEFT,0)){
          if(player.hSpeed>-player.maxSpeed){player.hSpeed--;}
        }else{
          if(player.hSpeed>0)     {player.hSpeed--;}
          else if(player.hSpeed<0){player.hSpeed++;}
        }
          
        if(gb.buttons.repeat(BTN_DOWN,0)){
          if(player.vSpeed<player.maxSpeed){player.vSpeed++;}
        }else if(gb.buttons.repeat(BTN_UP,0)){
          if(player.vSpeed>-player.maxSpeed){player.vSpeed--;}
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
          for(i=0;i<abs(player.vSpeed);i++) {if(player.y_world>5){player.y_world--;}}
        }
    
        if(gb.buttons.repeat(BTN_A,0) && player.isLanding==0 && player.altitude == MAXALTITUDE){
          player.fire = 1;
        }else{
          player.fire = 0;
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
  player.x_world=65;
  player.y_world=43;
  player.altitude=0;
  player.dir=0;
  
  player.hSpeed = 0;
  player.vSpeed = 0;
  player.maxSpeed = 4;
  
  player.isLanding=1;
  player.isCrashing=0;
  
  player.ammo=MAXAMMO;
  player.life=MAXLIFE;
  player.fuel=MAXFUEL;
  player.fuelCheck = 0;
  player.fire=0;
  
  player.animHelix=0;
  player.animBoom = 0;

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
  switch(lvl){
    case 0:
    nbBackground=8;
    bkgrnd[0].x_world=61;   bkgrnd[0].y_world=41;   bkgrnd[0].width=13;  bkgrnd[0].height=7;
    bkgrnd[1].x_world=57;   bkgrnd[1].y_world=351;  bkgrnd[1].width=13;  bkgrnd[1].height=7;
    bkgrnd[2].x_world=177;  bkgrnd[2].y_world=918;  bkgrnd[2].width=13;  bkgrnd[2].height=7; 
    bkgrnd[3].x_world=368;  bkgrnd[3].y_world=440;  bkgrnd[3].width=13;  bkgrnd[3].height=7;
    bkgrnd[4].x_world=921;  bkgrnd[4].y_world=32;   bkgrnd[4].width=13;  bkgrnd[4].height=7;
    bkgrnd[5].x_world=812;  bkgrnd[5].y_world=331;  bkgrnd[5].width=13;  bkgrnd[5].height=7;
    bkgrnd[6].x_world=693;  bkgrnd[6].y_world=849;  bkgrnd[6].width=13;  bkgrnd[6].height=7;
    bkgrnd[7].x_world=906;  bkgrnd[7].y_world=961;  bkgrnd[7].width=13;  bkgrnd[7].height=7;

    nbLandscape=30;
    //village + not ennemies first
    landscape[0].x_world=104;     landscape[0].y_world=48;    landscape[0].width=72;   landscape[0].height=41;   landscape[0].sprite=4;  landscape[0].animBoom=0;   landscape[0].life = 255;  landscape[0].fireTimer = 0;
    landscape[1].x_world=837;     landscape[1].y_world=44;    landscape[1].width=72;   landscape[1].height=41;   landscape[1].sprite=4;  landscape[1].animBoom=0;   landscape[1].life = 255;  landscape[1].fireTimer = 0;
    landscape[2].x_world=705;     landscape[2].y_world=269;   landscape[2].width=72;   landscape[2].height=41;   landscape[2].sprite=4;  landscape[2].animBoom=0;   landscape[2].life = 255;  landscape[2].fireTimer = 0;
    landscape[3].x_world=654;     landscape[3].y_world=769;   landscape[3].width=72;   landscape[3].height=41;   landscape[3].sprite=4;  landscape[3].animBoom=0;   landscape[3].life = 255;  landscape[3].fireTimer = 0;
    landscape[4].x_world=51;      landscape[4].y_world=866;   landscape[4].width=72;   landscape[4].height=41;   landscape[4].sprite=4;  landscape[4].animBoom=0;   landscape[4].life = 255;  landscape[4].fireTimer = 0;
   
    //ennemies all ennemies then
    landscape[5].x_world=403;    landscape[5].y_world=181;    landscape[5].width=16;   landscape[5].height=22;   landscape[5].sprite=7;  landscape[5].animBoom=0;   landscape[5].life = 20;  landscape[5].fireTimer = 0;
    landscape[6].x_world=472;    landscape[6].y_world=181;    landscape[6].width=16;   landscape[6].height=22;   landscape[6].sprite=7;  landscape[6].animBoom=0;   landscape[6].life = 20;  landscape[6].fireTimer = 0;
    landscape[7].x_world=404;    landscape[7].y_world=246;    landscape[7].width=16;   landscape[7].height=22;   landscape[7].sprite=7;  landscape[7].animBoom=0;   landscape[7].life = 20;  landscape[7].fireTimer = 0;
    landscape[8].x_world=474;    landscape[8].y_world=246;    landscape[8].width=16;   landscape[8].height=22;   landscape[8].sprite=7;  landscape[8].animBoom=0;   landscape[8].life = 20;  landscape[8].fireTimer = 0;
    landscape[9].x_world=332;    landscape[9].y_world=651;    landscape[9].width=16;   landscape[9].height=22;   landscape[9].sprite=7;  landscape[9].animBoom=0;   landscape[9].life = 20;  landscape[9].fireTimer = 0;
    landscape[10].x_world=360;   landscape[10].y_world=651;   landscape[10].width=16;  landscape[10].height=22;  landscape[10].sprite=7; landscape[10].animBoom=0;  landscape[10].life = 20;  landscape[10].fireTimer = 0;
    landscape[11].x_world=869;   landscape[11].y_world=534;   landscape[11].width=16;  landscape[11].height=22;  landscape[11].sprite=7; landscape[11].animBoom=0;  landscape[11].life = 20;  landscape[11].fireTimer = 0;
    landscape[12].x_world=913;   landscape[12].y_world=571;   landscape[12].width=16;  landscape[12].height=22;  landscape[12].sprite=7; landscape[12].animBoom=0;  landscape[12].life = 20;  landscape[12].fireTimer = 0;
    landscape[13].x_world=958;   landscape[13].y_world=533;   landscape[13].width=16;  landscape[13].height=22;  landscape[13].sprite=7; landscape[13].animBoom=0;  landscape[13].life = 20;  landscape[13].fireTimer = 0;
    landscape[14].x_world=913;   landscape[14].y_world=492;   landscape[14].width=16;  landscape[14].height=22;  landscape[14].sprite=7; landscape[14].animBoom=0;  landscape[14].life = 20;  landscape[14].fireTimer = 0;
    landscape[15].x_world=324;   landscape[15].y_world=645;   landscape[15].width=7;   landscape[15].height=10;  landscape[15].sprite=8; landscape[15].animBoom=0;  landscape[15].life = 80;  landscape[15].fireTimer = 0;
    landscape[16].x_world=324;   landscape[16].y_world=669;   landscape[16].width=7;   landscape[16].height=10;  landscape[16].sprite=8; landscape[16].animBoom=0;  landscape[16].life = 80;  landscape[16].fireTimer = 0;
    landscape[17].x_world=376;   landscape[17].y_world=645;   landscape[17].width=7;   landscape[17].height=10;  landscape[17].sprite=8; landscape[17].animBoom=0;  landscape[17].life = 80;  landscape[17].fireTimer = 0;
    landscape[18].x_world=376;   landscape[18].y_world=669;   landscape[18].width=7;   landscape[18].height=10;  landscape[18].sprite=8; landscape[18].animBoom=0;  landscape[18].life = 80;  landscape[18].fireTimer = 0;
    landscape[19].x_world=314;   landscape[19].y_world=833;   landscape[19].width=7;   landscape[19].height=10;  landscape[19].sprite=8; landscape[19].animBoom=0;  landscape[19].life = 80;  landscape[19].fireTimer = 0;
    landscape[20].x_world=382;   landscape[20].y_world=863;   landscape[20].width=7;   landscape[20].height=10;  landscape[20].sprite=8; landscape[20].animBoom=0;  landscape[20].life = 80;  landscape[20].fireTimer = 0;
    landscape[21].x_world=413;   landscape[21].y_world=895;   landscape[21].width=7;   landscape[21].height=10;  landscape[21].sprite=8; landscape[21].animBoom=0;  landscape[21].life = 80;  landscape[21].fireTimer = 0;
    landscape[22].x_world=444;   landscape[22].y_world=863;   landscape[22].width=7;   landscape[22].height=10;  landscape[22].sprite=8; landscape[22].animBoom=0;  landscape[22].life = 80;  landscape[22].fireTimer = 0;
    landscape[23].x_world=885;   landscape[23].y_world=511;   landscape[23].width=7;   landscape[23].height=10;  landscape[23].sprite=8; landscape[23].animBoom=0;  landscape[23].life = 80;  landscape[23].fireTimer = 0;
    landscape[24].x_world=885;   landscape[24].y_world=573;   landscape[24].width=7;   landscape[24].height=10;  landscape[24].sprite=8; landscape[24].animBoom=0;  landscape[24].life = 80;  landscape[24].fireTimer = 0;
    landscape[25].x_world=948;   landscape[25].y_world=573;   landscape[25].width=7;   landscape[25].height=10;  landscape[25].sprite=8; landscape[25].animBoom=0;  landscape[25].life = 80;  landscape[25].fireTimer = 0;
    landscape[26].x_world=948;   landscape[26].y_world=511;   landscape[26].width=7;   landscape[26].height=10;  landscape[26].sprite=8; landscape[26].animBoom=0;  landscape[26].life = 80;  landscape[26].fireTimer = 0;
    landscape[27].x_world=426;   landscape[27].y_world=207;   landscape[27].width=32;  landscape[27].height=32;  landscape[27].sprite=6; landscape[27].animBoom=0;  landscape[27].life = 150;  landscape[27].fireTimer = 0;
    landscape[28].x_world=401;   landscape[28].y_world=852;   landscape[28].width=32;  landscape[28].height=32;  landscape[28].sprite=6; landscape[28].animBoom=0;  landscape[28].life = 150;  landscape[28].fireTimer = 0;
    landscape[29].x_world=904;   landscape[29].y_world=530;   landscape[29].width=32;  landscape[29].height=32;  landscape[29].sprite=6; landscape[29].animBoom=0;  landscape[29].life = 150;  landscape[29].fireTimer = 0;
  break;
  
    
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
        landscape[bullet[j].shooter].fireTimer=0;
        bullet[j].x_world=0;
        bullet[j].y_world=0;
        bullet[j].dir=0;
        bullet[j].distance=0;
      }
    }
  }

  //define new
  for(i=5;i<30;i++){
    coordx = landscape[i].x_world+ (landscape[i].width/2);
    coordy = landscape[i].y_world+ (landscape[i].height/2);
    if(abs(player.x_world-coordx)<75 && abs(player.y_world-coordy)<75 && landscape[i].fireTimer<1 && landscape[i].life>0){
      check01=0;
      for(j=0;j<MAXBULLET;j++){
        if(bullet[j].distance==0 && check01==0){
          check01=1;
          landscape[i].fireTimer=20;
          switch(landscape[i].sprite){
            case 6 : landscape[i].fireTimer=5; break;
            case 7 : landscape[i].fireTimer=12; break;
          }
          landscape[i].fireTimer=20;
          bullet[j].shooter=i;
          bullet[j].x_world=coordx;
          bullet[j].y_world=coordy;
          bullet[j].distance=1;
          bullet[j].dir=0;
          if(player.x_world>coordx+5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=1;}
          if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude>coordy)   {bullet[j].dir=2;}
          if(player.x_world<coordx-5 && player.y_world-player.altitude>coordy+5)                            {bullet[j].dir=3;}
          if(player.x_world<coordx && player.y_world-player.altitude>coordy-6 && player.y_world-player.altitude<coordy+6){bullet[j].dir=4;}
          if(player.x_world<coordx-5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=5;}
          if(player.x_world>coordx-6 && player.x_world<coordx+6 && player.y_world-player.altitude<coordy-6) {bullet[j].dir=6;}
          if(player.x_world>coordx+5 && player.y_world-player.altitude<coordy-5)                            {bullet[j].dir=7;}
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
      if(bullet[j].x_world>player.x_world-4 && bullet[j].x_world<player.x_world+4 && bullet[j].y_world>player.y_world-player.altitude-4 && bullet[j].y_world<player.y_world-player.altitude+4){
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
void fnctn_checkPlayerAltitude(){
  switch(player.isLanding){
    case 0: if(player.altitude<MAXALTITUDE){player.altitude++;} break;
    case 1: if(player.altitude>0){player.altitude--;} break;
  }
  if(player.isCrashing==1 && player.altitude>0) {player.dir = (player.dir + 1)%8;}
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
    for(i=0;i<nbLandscape;i++){
      if(coordx>landscape[i].x_world && coordx<landscape[i].x_world+landscape[i].width && coordy>landscape[i].y_world && coordy<landscape[i].y_world+landscape[i].height){
        if(landscape[i].life>0){landscape[i].life--;}
      }
    }   
  }
}

//##################################################################
//##################################################################
void fnctn_checkLanding(){
  if(player.isLanding==1 && player.altitude ==3){
    check01=0;
    for(i=fnctn_playerXpos(player.x_world)-2;i <fnctn_playerXpos(player.x_world)+2;i++){
      for(j=fnctn_playerYpos(player.y_world)-1;j<fnctn_playerYpos(player.y_world)+1;j++){
        if(gb.display.getPixel(i,j)==1){check01=1;}
      }
    }
    if(check01==1){
      if(player.life>0){player.life=player.life -5;}
      if(player.life<=0){
        player.isCrashing=1;
      }else{
        player.animDamage = 12;
        player.isLanding=0;
      }
    }
  }

  if(player.isLanding==1 && player.altitude==0 && player.isCrashing==0){
    switch(lvl){
      case 0:
        for(i=0;i<nbBackground;i++){
          if(player.x_world>bkgrnd[i].x_world   && player.x_world<bkgrnd[i].x_world+bkgrnd[i].width     && player.y_world>bkgrnd[i].y_world     && player.y_world<bkgrnd[i].y_world+bkgrnd[i].height){
            switch(i){
              case 0: player.life = MAXLIFE; player.fuel = MAXFUEL; break;
              case 1: player.life = MAXLIFE; break;
              case 2: player.fuel = MAXFUEL; break;
              case 3: player.fuel = MAXFUEL; break;
              case 4: player.fuel = MAXFUEL; break;
              case 5: player.fuel = MAXFUEL; break;
              case 6: player.life = MAXLIFE; break;
              case 7: player.life = MAXLIFE; player.fuel = MAXFUEL; break;
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

  for(i=0;i<nbLandscape;i++){
    if(landscape[i].life == 0 && landscape[i].animBoom<12){landscape[i].animBoom++;}
  }

  for(i=5;i<30;i++){
    if(landscape[i].fireTimer>0){
      landscape[i].fireTimer--;
    }
  }
  
}



