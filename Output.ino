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
      gb.display.drawLine(coordx+6 , coordy-10  , coordx+16 , coordy-0 );} 
      gb.display.drawBitmap(coordx+12 , coordy-4, impact[cptAnim%3]);
      break;
      
      case 1 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+3 , coordy-9  , coordx+8 , coordy+5 );}
      gb.display.drawBitmap(coordx+4 , coordy+1,  impact[cptAnim%3]);
      break;
      
      case 2 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+0  , coordy-10  , coordx+0  , coordy+8);}
      gb.display.drawBitmap(coordx-4  , coordy+4, impact[cptAnim%3]);
      break;
      
      case 3 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-3  , coordy-9  , coordx-8  , coordy+5 );}
      gb.display.drawBitmap(coordx-12 , coordy+1, impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 4 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-6  , coordy-10  , coordx-16  , coordy+0 );} 
      gb.display.drawBitmap(coordx-20  , coordy-4,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 5 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx-5  , coordy-12 , coordx-8  , coordy-5 );} 
      gb.display.drawBitmap(coordx-12  , coordy-9,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 6 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+0  , coordy-10  , coordx+0  , coordy-8 );} 
      gb.display.drawBitmap(coordx-4  , coordy-12,  impact[cptAnim%3],NOROT,FLIPH); 
      break;
      
      case 7 : 
      if(cptAnim%4==0){
      gb.display.drawLine(coordx+5 , coordy-12 , coordx+8 , coordy-5 );} 
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
  gb.display.fillRect(0,0,84,4);
  gb.display.setColor(BLACK);
  gb.display.drawBitmap(0,0,HUD);
  
  gb.display.fillRect(7,1,player.life/(MAXLIFE/10),2); //life
  gb.display.fillRect(24,1,player.fuel/(MAXFUEL/10),2); //fuel
  gb.display.fillRect(42,1,player.ammo/(MAXAMMO/10),2); //ammo

  gb.display.print("              "); 
  gb.display.print(gb.getCpuLoad());
  //gb.display.print("  "); 
  
}


//##################################################################
//##################################################################
void outpt_menu(){

  switch(lvl){
    case 0: gb.display.print("     Desert Strike"); break;
    case 1: gb.display.print("     Forest Strike"); break;
    case 2: gb.display.print("      City Strike"); break;
  }
  gb.display.drawRect(3,14,24,24);
  gb.display.drawBitmap(7,28,Desert_sand);
  gb.display.drawBitmap(15,20,Desert_bush);

  gb.display.drawRect(30,14,24,24);
  //gb.display.drawBitmap(33,16,tree03);

  gb.display.drawRect(57,14,24,24);
  //gb.display.drawBitmap(62,26,rock01);

  gb.display.drawRect(2+(lvl*27),13,26,26);
}



//##################################################################
//##################################################################
void outpt_animBoom(){
  if(player.isCrashing==1 && player.altitude==0){
    outpt_soundfx(1);
    coordx=fnctn_playerXpos(player.x_world)-2;
    coordy=fnctn_playerYpos(player.y_world);
    gb.display.drawBitmap(coordx,coordy,boom[player.animBoom]);
  }

  for(i=0;i<nbLandscape;i++){
    if(landscape[i].life==0 && landscape[i].animBoom<12){
      outpt_soundfx(1);
      coordx=fnctn_lndscapeXpos(landscape[i].x_world);
      coordy=fnctn_lndscapeYpos(landscape[i].y_world)-4;
      gb.display.drawBitmap(coordx,coordy,boom[landscape[i].animBoom]);
      switch(landscape[i].sprite){
        case 4: 
        gb.display.drawBitmap(coordx+2    ,coordy+15  ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+10   ,coordy+1   ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+14   ,coordy+23  ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+27   ,coordy+2   ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+30   ,coordy+28  ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+46   ,coordy+21  ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+57   ,coordy+2   ,boom[landscape[i].animBoom]);
        gb.display.drawBitmap(coordx+63   ,coordy+26  ,boom[landscape[i].animBoom]);
        break;
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

