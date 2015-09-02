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
      gb.display.drawPixel(coordx,coordy);
      gb.display.drawPixel(coordx+1,coordy);
      gb.display.drawPixel(coordx+1,coordy+1);
      gb.display.drawPixel(coordx,coordy+1);
    }
  }
}




//##################################################################
//##################################################################
void outpt_drawHUD(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,84,5);
  gb.display.setColor(BLACK);
  gb.display.drawBitmap(42,1,HUD);

  switch(player.moveMode){
    case 0: gb.display.print("$");gb.display.print(money); break;
    case 1: gb.display.print(destroyedBuildings);gb.display.print("/");gb.display.print(nbBuilding_Hostile); break;
  }
  
  gb.display.fillRect(49,2,player.life/(MAXLIFE/10),2); //life
  gb.display.fillRect(66,2,player.fuel/(MAXFUEL/10),2); //fuel


  gb.display.cursorX = 79;
  gb.display.cursorY = 0;
  switch(player.moveMode){
    case 0: gb.display.print("@  "); break;
    case 1: gb.display.print("-  "); break;
  }
}


//##################################################################
//##################################################################
void outpt_menu(){
  switch(lvl){
    case 0: gb.display.print("     Desert Strike"); break;
    case 1: gb.display.print("     Forest Strike"); break;
  }
  gb.display.drawRect(10,7,30,19);
  gb.display.drawBitmap(22,17,Desert_sand);
  gb.display.drawBitmap(29,19,Desert_sand);
  gb.display.drawBitmap(30,9,Desert_bush);
  gb.display.drawBitmap(12,9,Desert_cactus);

  gb.display.drawRect(50,7,30,19);
  //gb.display.drawBitmap(33,16,tree03);

  gb.display.drawRect(9+(lvl*40),6,32,21);
  
  gb.display.cursorX = 35;
  gb.display.cursorY = 30;
  gb.display.print("Easy");
  gb.display.cursorX = 35;
  gb.display.cursorY = 36;
  gb.display.print("Normal");
  gb.display.cursorX = 35;
  gb.display.cursorY = 42;
  gb.display.print("Hard");
  gb.display.drawBitmap(15 ,29+(difficulty*6)     ,copterProfile);
  gb.display.drawBitmap(17 ,29+(difficulty*6)-2   ,helix[1]);
}



//##################################################################
//##################################################################
void outpt_animBoom(){
  if(player.isCrashing==1 && player.altitude==0 && player.animBoom<11){
    outpt_soundfx(1);
    coordx=fnctn_playerXpos(player.x_world)-2;
    coordy=fnctn_playerYpos(player.y_world);
    gb.display.drawBitmap(coordx,coordy,boom[player.animBoom]);
  }

  for(i=0;i<nbBuilding_Hostile;i++){
    if(building_hostile[i].life==0 && building_hostile[i].animBoom<12){
      outpt_soundfx(1);
      coordx=fnctn_lndscapeXpos(building_hostile[i].x_world);
      coordy=fnctn_lndscapeYpos(building_hostile[i].y_world)-4;
      gb.display.drawBitmap(coordx,coordy,boom[building_hostile[i].animBoom]);
      switch(building_hostile[i].sprite){
        case 4: 
        gb.display.drawBitmap(coordx+2    ,coordy+15  ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+10   ,coordy+1   ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+14   ,coordy+23  ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+27   ,coordy+2   ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+30   ,coordy+28  ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+46   ,coordy+21  ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+57   ,coordy+2   ,boom[building_hostile[i].animBoom]);
        gb.display.drawBitmap(coordx+63   ,coordy+26  ,boom[building_hostile[i].animBoom]);
        break;
      }
    }    
  }
  
  for(i=0;i<nbBuilding_Friend;i++){
    if(building_friend[i].life==0 && building_friend[i].animBoom<12){
      outpt_soundfx(1);
      coordx=fnctn_lndscapeXpos(building_friend[i].x_world);
      coordy=fnctn_lndscapeYpos(building_friend[i].y_world)-4;
      gb.display.drawBitmap(coordx,coordy,boom[building_friend[i].animBoom]);
      switch(building_friend[i].sprite){
        case 4: 
        gb.display.drawBitmap(coordx+2    ,coordy+15  ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+10   ,coordy+1   ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+14   ,coordy+23  ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+27   ,coordy+2   ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+30   ,coordy+28  ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+46   ,coordy+21  ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+57   ,coordy+2   ,boom[building_friend[i].animBoom]);
        gb.display.drawBitmap(coordx+63   ,coordy+26  ,boom[building_friend[i].animBoom]);
        break;
      }
    }    
  }

  if(difficulty>0){
    for(i=0;i<20;i++){
      if(mobilUnit_hostile[i].life==0 && mobilUnit_hostile[i].animBoom<12){
        coordx=fnctn_lndscapeXpos(mobilUnit_hostile[i].x_world);
        coordy=fnctn_lndscapeYpos(mobilUnit_hostile[i].y_world)-4;
        switch(mobilUnit_hostile[i].sprite){
          case 1: 
          outpt_soundfx(1);
          gb.display.drawBitmap(coordx+5    ,coordy-3  ,boom[mobilUnit_hostile[i].animBoom]);
          break;
        }
      }
    }
  }
}

//##################################################################
//##################################################################
void outpt_drawBackground(){ 
    switch(lvl){
    case 0:
    coordx=fnctn_backgrndXpos(22);   coordy=fnctn_backgrndYpos(16);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(30);   coordy=fnctn_backgrndYpos(21);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(22);   coordy=fnctn_backgrndYpos(26);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(77);   coordy=fnctn_backgrndYpos(11);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(43);   coordy=fnctn_backgrndYpos(45);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(82);   coordy=fnctn_backgrndYpos(48);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(27);   coordy=fnctn_backgrndYpos(81);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(36);   coordy=fnctn_backgrndYpos(85);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(28);   coordy=fnctn_backgrndYpos(91);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(103);  coordy=fnctn_backgrndYpos(116);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);

    coordx=fnctn_backgrndXpos(64);   coordy=fnctn_backgrndYpos(30);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(14);   coordy=fnctn_backgrndYpos(64);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(53);   coordy=fnctn_backgrndYpos(119);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(4);    coordy=fnctn_backgrndYpos(3);     gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(89);   coordy=fnctn_backgrndYpos(73);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(84);   coordy=fnctn_backgrndYpos(84);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_rock);
    coordx=fnctn_backgrndXpos(98);   coordy=fnctn_backgrndYpos(80);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(7);    coordy=fnctn_backgrndYpos(109);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);
    coordx=fnctn_backgrndXpos(110);  coordy=fnctn_backgrndYpos(26);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);
    break;

    case 1:
    coordx=fnctn_backgrndXpos(22);   coordy=fnctn_backgrndYpos(16);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(30);   coordy=fnctn_backgrndYpos(21);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(22);   coordy=fnctn_backgrndYpos(26);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(77);   coordy=fnctn_backgrndYpos(11);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(43);   coordy=fnctn_backgrndYpos(45);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(82);   coordy=fnctn_backgrndYpos(48);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(27);   coordy=fnctn_backgrndYpos(81);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(36);   coordy=fnctn_backgrndYpos(85);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(28);   coordy=fnctn_backgrndYpos(91);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);
    coordx=fnctn_backgrndXpos(103);  coordy=fnctn_backgrndYpos(116);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_sand);

    coordx=fnctn_backgrndXpos(64);   coordy=fnctn_backgrndYpos(30);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(14);   coordy=fnctn_backgrndYpos(64);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(53);   coordy=fnctn_backgrndYpos(119);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(4);    coordy=fnctn_backgrndYpos(3);     gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(89);   coordy=fnctn_backgrndYpos(73);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(84);   coordy=fnctn_backgrndYpos(84);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_rock);
    coordx=fnctn_backgrndXpos(98);   coordy=fnctn_backgrndYpos(80);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(7);    coordy=fnctn_backgrndYpos(109);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);
    coordx=fnctn_backgrndXpos(110);  coordy=fnctn_backgrndYpos(26);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);
    break;
  }
}

//##################################################################
//##################################################################
void outpt_drawbaseCamps(){
   switch(lvl){
   case 0:
    coordx=fnctn_lndscapeXpos(57);    coordy=fnctn_lndscapeYpos(19);    width=19;  height=15;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[1]);} //basecamp
    coordx=fnctn_lndscapeXpos(24);    coordy=fnctn_lndscapeYpos(27);    width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(10);    coordy=fnctn_lndscapeYpos(550);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(385);   coordy=fnctn_lndscapeYpos(103);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(77);    coordy=fnctn_lndscapeYpos(33);    width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(589);   coordy=fnctn_lndscapeYpos(26);    width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(274);   coordy=fnctn_lndscapeYpos(287);   width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(253);   coordy=fnctn_lndscapeYpos(159);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis
    coordx=fnctn_lndscapeXpos(152);   coordy=fnctn_lndscapeYpos(414);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis
    coordx=fnctn_lndscapeXpos(526);   coordy=fnctn_lndscapeYpos(284);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis

    for(i=0;i<5;i++){
      coordx=fnctn_lndscapeXpos(bkgrnd[i].x_world);
      coordy=fnctn_lndscapeYpos(bkgrnd[i].y_world);
      if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
        gb.display.drawBitmap(coordx   ,coordy  ,sprites[0]);
      }
    }
    break;

    case 1:
    coordx=fnctn_lndscapeXpos(57);    coordy=fnctn_lndscapeYpos(19);    width=19;  height=15;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[1]);} //basecamp
    coordx=fnctn_lndscapeXpos(24);    coordy=fnctn_lndscapeYpos(27);    width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(10);    coordy=fnctn_lndscapeYpos(550);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(385);   coordy=fnctn_lndscapeYpos(103);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(77);    coordy=fnctn_lndscapeYpos(33);    width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(589);   coordy=fnctn_lndscapeYpos(26);    width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(274);   coordy=fnctn_lndscapeYpos(287);   width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(253);   coordy=fnctn_lndscapeYpos(159);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis
    coordx=fnctn_lndscapeXpos(152);   coordy=fnctn_lndscapeYpos(414);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis
    coordx=fnctn_lndscapeXpos(526);   coordy=fnctn_lndscapeYpos(284);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis

    for(i=0;i<5;i++){
      coordx=fnctn_lndscapeXpos(bkgrnd[i].x_world);
      coordy=fnctn_lndscapeYpos(bkgrnd[i].y_world);
      if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
        gb.display.drawBitmap(coordx   ,coordy  ,sprites[0]);
      }
    }
    break;
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
      if(coordx<SCREENWIDTH+20  && coordx>0-mobilUnit_hostile[i].width-20   && coordy<SCREENHEIGHT+20    && coordy>0-mobilUnit_hostile[i].height-20){fnctn_moveunit(i);}
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
void outpt_soundfx(byte fxno) {
  gb.sound.command(0,soundfx[fxno][6],0,0); // set volume
  gb.sound.command(1,soundfx[fxno][0],0,0); // set waveform
  gb.sound.command(2,soundfx[fxno][5],-soundfx[fxno][4],0); // set volume slide
  gb.sound.command(3,soundfx[fxno][3],soundfx[fxno][2]-58,0); // set pitch slide
  gb.sound.playNote(soundfx[fxno][1],soundfx[fxno][7],0); // play note
}

