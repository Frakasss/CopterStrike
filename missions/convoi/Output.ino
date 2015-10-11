//##################################################################
//##################################################################
void outpt_drawPlayer(){
  coordx=fnctn_playerXpos(player.x_world);
  coordy=fnctn_playerYpos(player.y_world);
  gb.display.drawBitmap(coordx-2   ,coordy-2   ,copterShadow);
  if(player.animDamage%3==0){
    gb.display.drawBitmap(coordx-7   ,coordy-player.altitude-8   ,helix[player.animHelix]);
    switch(player.dir){
      case 0: 
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-6  ,copterProfile_mask  ,NOROT, NOFLIP); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-6  ,copterProfile  ,NOROT, NOFLIP); 
      break;
      
      case 1: 
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-13 ,copterDiag1_mask    ,NOROT, NOFLIP); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-13 ,copterDiag1    ,NOROT, NOFLIP); 
      break;
      
      case 2:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-4 ,coordy-player.altitude-6  ,copterUpDown_mask     ,NOROT, NOFLIP); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-4 ,coordy-player.altitude-6  ,copterDown     ,NOROT, NOFLIP); 
      break;
      
      case 3:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-13 ,copterDiag1_mask    ,NOROT, FLIPH ); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-13 ,copterDiag1    ,NOROT, FLIPH ); 
      break;
      
      case 4:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-6  ,copterProfile_mask  ,NOROT, FLIPH ); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-6  ,copterProfile  ,NOROT, FLIPH ); 
      break;
      
      case 5:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-6  ,copterDiag2_mask    ,NOROT, FLIPH ); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-7 ,coordy-player.altitude-6  ,copterDiag2    ,NOROT, FLIPH ); 
      break;
      
      case 6:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-4 ,coordy-player.altitude-6  ,copterUpDown_mask     ,NOROT, NOFLIP); 
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-4 ,coordy-player.altitude-6  ,copterUp       ,NOROT, NOFLIP); 
      break;
      
      case 7:  
      gb.display.setColor(WHITE);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-6  ,copterDiag2_mask    ,NOROT, NOFLIP);
      gb.display.setColor(BLACK);
      gb.display.drawBitmap(coordx-9 ,coordy-player.altitude-6  ,copterDiag2    ,NOROT, NOFLIP); 
      break;
    }
  }
}

//##################################################################
//##################################################################
void outpt_drawPlayerFire(){
  if(player.fire == 1){
    outpt_soundfx(0);
    coordx=fnctn_playerXpos(player.x_world);
    coordy=fnctn_playerYpos(player.y_world);
    switch(player.dir){
      case 0 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+6 , coordy-player.altitude  , coordx+16 , coordy-0 );} //10
      gb.display.drawBitmap(coordx+12 , coordy-4, impact[cptAnim%3]);
      break;
      
      case 1 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+3 , coordy-(player.altitude-1)  , coordx+8 , coordy+5 );}//9
      gb.display.drawBitmap(coordx+4 , coordy+1,  impact[cptAnim%3]);
      break;
      
      case 2 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+0  , coordy-player.altitude  , coordx+0  , coordy+8);}
      gb.display.drawBitmap(coordx-4  , coordy+4, impact[cptAnim%3]);
      break;
      
      case 3 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-3  , coordy-(player.altitude-1)  , coordx-8  , coordy+5 );}
      gb.display.drawBitmap(coordx-12 , coordy+1, impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 4 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-6  , coordy-player.altitude  , coordx-16  , coordy+0 );} 
      gb.display.drawBitmap(coordx-20  , coordy-4,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 5 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-5  , coordy-(player.altitude+2) , coordx-8  , coordy-5 );} 
      gb.display.drawBitmap(coordx-12  , coordy-9,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 6 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+0  , coordy-player.altitude  , coordx+0  , coordy-8 );} 
      gb.display.drawBitmap(coordx-4  , coordy-12,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 7 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+5 , coordy-(player.altitude+2) , coordx+8 , coordy-5 );} 
      gb.display.drawBitmap(coordx+4 , coordy-9,  impact[cptAnim%3]); 
      break;
    }
     
    
  }
}


//##################################################################
//##################################################################
void outpt_drawEnnemyFire(){
  for(i=0;i<MAXBULLET;i++){
    if(bullet[i].distance>0){
      if(bullet[i].distance==1){outpt_soundfx(0);}
      coordx = fnctn_lndscapeXpos(bullet[i].x_world);
      coordy = fnctn_lndscapeYpos(bullet[i].y_world);
      if(coordx>0 && coordx<SCREENWIDTH && coordy>0 && coordy<SCREENHEIGHT){gb.display.fillRect(coordx,coordy,2,2);}
      
    }
  }
}

//##################################################################
//##################################################################
void outpt_drawHUD(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,84,5);
  gb.display.setColor(BLACK);


  if(convoiSecuriser && cptAnim<15 && player.altitude>0){
    gb.display.print("    Return to base.");
  }else{
    gb.display.drawBitmap(21,1,HUD);
    switch(player.moveMode){
      case 0: gb.display.print("$");gb.display.print(money); break;
      case 1: gb.display.print(destroyedBuildings);gb.display.print("/");gb.display.print(nbBuilding_Hostile); break;
    }
    
    gb.display.fillRect(49,2,player.life/(MAXLIFE/10),2); //life
    gb.display.fillRect(29,2,Camion.life/(MAX_LIFE_CAM/10),2); //life Camion
    gb.display.fillRect(66,2,player.fuel/(MAXFUEL/10),2); //fuel
  
  
    gb.display.cursorX = 79;
    gb.display.cursorY = 0;
    switch(player.moveMode){
      case 0: gb.display.print("@  "); break;
      case 1: gb.display.print("-  "); break;
    }
  }
}

//##################################################################
//##################################################################
void outpt_animBoom(){
  if(player.isCrashing==1 && player.altitude==0 && player.animBoom<11){
    outpt_soundfx(1);
    coordx=fnctn_playerXpos(player.x_world)-2;
    coordy=fnctn_playerYpos(player.y_world)-10;
    gb.display.drawBitmap(coordx,coordy,boom[player.animBoom]);
  }

  if(nbBuilding_Hostile>nbBuilding_Friend){
    check01=nbBuilding_Hostile;
  }else{
    check01=nbBuilding_Friend;
  }
  if(check01<20){check01=20;}
  

  for(i=0;i<check01;i++){
    if(i<=nbBuilding_Hostile){
      if(building_hostile[i].life==0 && building_hostile[i].animBoom<12){
        outpt_soundfx(1);
        coordx=fnctn_lndscapeXpos(building_hostile[i].x_world);
        coordy=fnctn_lndscapeYpos(building_hostile[i].y_world)-3;
        if(building_hostile[i].sprite==4){
          gb.display.drawBitmap(coordx+5    ,coordy     ,boom[building_hostile[i].animBoom]);
          gb.display.drawBitmap(coordx+20   ,coordy+5   ,boom[building_hostile[i].animBoom]);
          gb.display.drawBitmap(coordx+8    ,coordy+15  ,boom[building_hostile[i].animBoom]);
        }else{
          gb.display.drawBitmap(coordx,coordy,boom[building_hostile[i].animBoom]);
        }
      }
    }

    if(i<=nbBuilding_Friend){
      if(building_friend[i].life==0 && building_friend[i].animBoom<12){
        outpt_soundfx(1);
        coordx=fnctn_lndscapeXpos(building_friend[i].x_world);
        coordy=fnctn_lndscapeYpos(building_friend[i].y_world)-3;
        if(building_friend[i].sprite==4){
          gb.display.drawBitmap(coordx+10   ,coordy+3  ,boom[building_friend[i].animBoom]);
          gb.display.drawBitmap(coordx+41   ,coordy+4  ,boom[building_friend[i].animBoom]);
          gb.display.drawBitmap(coordx+38   ,coordy+24 ,boom[building_friend[i].animBoom]);
        }else{
          gb.display.drawBitmap(coordx+3    ,coordy    ,boom[building_friend[i].animBoom]);
        }
      }
    }

    if(i<=20){
      if(mobilUnit_hostile[i].life==0 && mobilUnit_hostile[i].animBoom<12){
        coordx=fnctn_lndscapeXpos(mobilUnit_hostile[i].x_world)+5;
        coordy=fnctn_lndscapeYpos(mobilUnit_hostile[i].y_world)-3;
        if(mobilUnit_hostile[i].sprite==1){ 
          outpt_soundfx(1);
          gb.display.drawBitmap(coordx    ,coordy  ,boom[mobilUnit_hostile[i].animBoom]);
        }
      }
    }
    
  }
}

//##################################################################
//##################################################################
void outpt_drawBackground(){ 
  for(i=0;i<19;i++){
    coordx=fnctn_backgrndXpos(bkg[i].x_world);   coordy=fnctn_backgrndYpos(bkg[i].y_world);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,spriteBkg[bkg[i].sprite]);
  }
}

//##################################################################
//##################################################################
void outpt_drawbaseCamps(){
  for(i=0;i<15;i++){
    coordx=fnctn_lndscapeXpos(bkgrnd[i].x_world);
    coordy=fnctn_lndscapeYpos(bkgrnd[i].y_world);
    if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
      gb.display.drawBitmap(coordx   ,coordy  ,sprites[bkgrnd[i].sprite]);
    }
  }
}


//##################################################################
//##################################################################
void outpt_drawBuilding_Friend(){
  for(i=0;i<nbBuilding_Friend;i++){
    coordx=fnctn_lndscapeXpos(building_friend[i].x_world);
    coordy=fnctn_lndscapeYpos(building_friend[i].y_world);
    if(coordx<SCREENWIDTH  && coordx>0-building_friend[i].width   && coordy<SCREENHEIGHT    && coordy>0-building_friend[i].height){
      if(building_friend[i].life==0 && building_friend[i].animBoom>5){
        gb.display.drawBitmap(coordx   ,coordy  ,destroy[building_friend[i].sprite]);
      }else{
        gb.display.drawBitmap(coordx   ,coordy  ,sprites[building_friend[i].sprite]);}
    }
  }
}

//##################################################################
//##################################################################
void outpt_drawBuilding_Hostile(){
  for(i=0;i<nbBuilding_Hostile;i++){
    coordx=fnctn_lndscapeXpos(building_hostile[i].x_world);
    coordy=fnctn_lndscapeYpos(building_hostile[i].y_world);
    if(coordx<SCREENWIDTH  && coordx>0-building_hostile[i].width   && coordy<SCREENHEIGHT    && coordy>0-building_hostile[i].height){
      if(building_hostile[i].life==0 && building_hostile[i].animBoom>5){
        gb.display.drawBitmap(coordx   ,coordy  ,destroy[building_hostile[i].sprite]);
      }else{
        gb.display.drawBitmap(coordx   ,coordy  ,sprites[building_hostile[i].sprite]);}
    }
  }
}



//##################################################################
//##################################################################
void outpt_drawMobile_Hostile(){
  for(i=0;i<20;i++){
    if(mobilUnit_hostile[i].life> 0 || (mobilUnit_hostile[i].animBoom<8) || (mobilUnit_hostile[i].animBoom<24 && mobilUnit_hostile[i].animBoom%4==2)){
      coordx = fnctn_lndscapeXpos(mobilUnit_hostile[i].x_world);
      coordy = fnctn_lndscapeYpos(mobilUnit_hostile[i].y_world);
      fnctn_moveunit(i);
      //if(coordx<SCREENWIDTH+20  && coordx>0-mobilUnit_hostile[i].width-20   && coordy<SCREENHEIGHT+20    && coordy>0-mobilUnit_hostile[i].height-20){fnctn_moveunit(i);}
      if(coordx<SCREENWIDTH  && coordx>0-mobilUnit_hostile[i].width   && coordy<SCREENHEIGHT    && coordy>0-mobilUnit_hostile[i].height){
        if(mobilUnit_hostile[i].sprite==0){
          if(mobilUnit_hostile[i].life> 0){
            if(mobilUnit_hostile[i].dir>1 && mobilUnit_hostile[i].dir<6){gb.display.drawBitmap(coordx   ,coordy  ,Ennemy_Unit, NOROT,FLIPH);}
            else{gb.display.drawBitmap(coordx   ,coordy  ,Ennemy_Unit);}
          }else{
          if(mobilUnit_hostile[i].dir>1 && mobilUnit_hostile[i].dir<6){gb.display.drawBitmap(coordx   ,coordy  ,Ennemy_Unit, ROTCCW,NOFLIP);}
            else{gb.display.drawBitmap(coordx   ,coordy  ,Ennemy_Unit,ROTCCW,NOFLIP);}
          }
        }else{
          switch(mobilUnit_hostile[i].dir){
            case 0: gb.display.drawBitmap(coordx   ,coordy  ,tank[0]); break;
            case 1: gb.display.drawBitmap(coordx   ,coordy  ,tank[1]); break;
            case 2: gb.display.drawBitmap(coordx   ,coordy  ,tank[2]); break;
            case 3: gb.display.drawBitmap(coordx   ,coordy  ,tank[1], NOROT, FLIPH); break;
            case 4: gb.display.drawBitmap(coordx   ,coordy  ,tank[0], NOROT, FLIPH); break;
            case 5: gb.display.drawBitmap(coordx   ,coordy  ,tank[4], NOROT, FLIPH); break;
            case 6: gb.display.drawBitmap(coordx   ,coordy  ,tank[3]); break;
            case 7: gb.display.drawBitmap(coordx   ,coordy  ,tank[4]); break;
          }
        }
      }
    }
  }
}

//##################################################################
//##################################################################
void outpt_draw_route()
{
  for(uint8_t i=0;i<NB_TSPRITE_ROUTE;i++){
    int x = pgm_read_word_near(&Routes[i].x_world);
    int y = pgm_read_word_near(&Routes[i].y_world);
   
    coordx = fnctn_lndscapeXpos(x);
    coordy = fnctn_lndscapeYpos(y);
    if(coordx<SCREENWIDTH  && coordx> -16   && coordy<SCREENHEIGHT    && coordy>-16){
      const uint8_t  tutu = pgm_read_byte(&Routes[i].sprite);
      switch(tutu){
        case 0 :
          gb.display.drawBitmap(coordx,coordy, roudeH);
        break;
        case 1 :
          gb.display.drawBitmap(coordx,coordy, roudeV);
        break;
        case 2 :
          gb.display.drawBitmap(coordx,coordy, virage1);
        break;
        case 3 :
          gb.display.drawBitmap(coordx,coordy, virage2);
        break;
        case 4 :
          gb.display.drawBitmap(coordx,coordy, virage3);
        break;
        case 5 :
          gb.display.drawBitmap(coordx,coordy, virage4);
        break;
        case 6 :
          if(currentCheckPoint<7){
            gb.display.drawBitmap(coordx,coordy, roudeH);
          }else if(cptExplosion<TEMP_EXPOLOSION) {
            uint8_t index = (uint8_t) (cptExplosion/NB_FRAME_EXPLOSION);
            gb.display.drawBitmap(coordx,(coordy - 16), explosion[index]);
          }else {
            gb.display.drawBitmap(coordx,coordy, routeExplose);  
          }
        
        break;
      }
    }
  }
}


void outpt_draw_camion()
{
  coordx = fnctn_lndscapeXpos(Camion.x_world);
  coordy = fnctn_lndscapeYpos(Camion.y_world);
  if(coordx<SCREENWIDTH  && coordx> -16   && coordy<SCREENHEIGHT    && coordy>-16){
    if(Camion.animDamage%3==0){
      gb.display.drawBitmap(coordx,coordy,Camion.sprites[Camion.dir]);
    }
  } 
}



//##################################################################
//##################################################################
void outpt_GameOver(){
  if(player.life==0 && player.animBoom==11){
    gb.display.setColor(WHITE);
    gb.display.fillRect(24,18,38,7);
    gb.display.setColor(BLACK);
    gb.display.drawRect(23,17,40,9);
    gb.display.cursorX = 25;
    gb.display.cursorY = 19;
    gb.display.print("Game Over");
    
  }
}

//##################################################################
//##################################################################
void outpt_Congratulation(){
    gb.display.setColor(WHITE);
    gb.display.fillRect(4,4,76,15);
    gb.display.setColor(BLACK);
    gb.display.drawRect(3,3,74,17);
    gb.display.cursorX = 9;
    gb.display.cursorY = 5;
    gb.display.print("Mission Complete");
    if(money<10){gb.display.cursorX = 40;}
    if(money>=10){gb.display.cursorX = 35;}
    if(money>=100){gb.display.cursorX = 31;}
    if(money>=1000){gb.display.cursorX = 27;}
    if(money>=10000){gb.display.cursorX = 23;}
    if(money>=100000){gb.display.cursorX = 19;}
    gb.display.cursorY = 12;
    gb.display.print("$");
    gb.display.print(money);
    
}


//##################################################################
//##################################################################
void outpt_soundfx(byte fxno) {
  switch(fxno){                   // set volume
    case 0: gb.sound.command(0,3,0,0);  break;
    case 1: gb.sound.command(0,10,0,0); break;
  }
  gb.sound.command(1,1,0,0);      // set waveform
  gb.sound.command(2,0,-7,0);     // set volume slide
  //gb.sound.command(3,0,53-58,0);  // set pitch slide
  gb.sound.command(3,0,-8,0);
  gb.sound.playNote(17,3,0);      // play note
}

