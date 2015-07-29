//void outpt_drawBackground1()
//void outpt_drawBackground2()


//##################################################################
//##################################################################
void outpt_drawBackground1(){ 
  switch(lvl){
   case 0:
    coordx=fnctn_backgrndXpos(64);   coordy=fnctn_backgrndYpos(30);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(14);   coordy=fnctn_backgrndYpos(64);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(53);   coordy=fnctn_backgrndYpos(119);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_bush);
    coordx=fnctn_backgrndXpos(4);    coordy=fnctn_backgrndYpos(3);     gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(89);   coordy=fnctn_backgrndYpos(73);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(84);   coordy=fnctn_backgrndYpos(84);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_rock);
    coordx=fnctn_backgrndXpos(98);   coordy=fnctn_backgrndYpos(80);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_cactus);
    coordx=fnctn_backgrndXpos(7);    coordy=fnctn_backgrndYpos(109);   gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);
    coordx=fnctn_backgrndXpos(110);  coordy=fnctn_backgrndYpos(26);    gb.display.drawBitmap(coordx-20   ,coordy-20  ,Desert_tree);

    //base 01
    coordx=fnctn_lndscapeXpos(58);    coordy=fnctn_lndscapeYpos(20);    width=19;  height=15;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[1]);} //basecamp
    coordx=fnctn_lndscapeXpos(25);    coordy=fnctn_lndscapeYpos(28);    width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(138);   coordy=fnctn_lndscapeYpos(905);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(334);   coordy=fnctn_lndscapeYpos(427);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(940);   coordy=fnctn_lndscapeYpos(19);    width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(775);   coordy=fnctn_lndscapeYpos(312);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(922);   coordy=fnctn_lndscapeYpos(949);   width=32;  height=29;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[2]);} //fuel
    coordx=fnctn_lndscapeXpos(78);    coordy=fnctn_lndscapeYpos(34);    width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(28);    coordy=fnctn_lndscapeYpos(340);   width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(667);   coordy=fnctn_lndscapeYpos(832);   width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(876);   coordy=fnctn_lndscapeYpos(954);   width=25;  height=26;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[3]);} //garage
    coordx=fnctn_lndscapeXpos(144);   coordy=fnctn_lndscapeYpos(356);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis
    coordx=fnctn_lndscapeXpos(462);   coordy=fnctn_lndscapeYpos(938);   width=36;  height=24;  if(coordx<SCREENWIDTH  && coordx>0-width   && coordy<SCREENHEIGHT    && coordy>0-height){gb.display.drawBitmap(coordx   ,coordy  ,sprites[5]);} //oasis


    for(i=0;i<nbLandscape;i++){
      coordx=fnctn_lndscapeXpos(landscape[i].x_world);
      coordy=fnctn_lndscapeYpos(landscape[i].y_world);
      if(coordx<SCREENWIDTH  && coordx>0-landscape[i].width   && coordy<SCREENHEIGHT    && coordy>0-landscape[i].height){
        if(landscape[i].life==0 && landscape[i].animBoom>5){
          gb.display.drawBitmap(coordx   ,coordy  ,destroy[landscape[i].sprite]);
        }else{
          gb.display.drawBitmap(coordx   ,coordy  ,sprites[landscape[i].sprite]);}
      }
    }
   break;
   
  }
}


//##################################################################
//##################################################################
void outpt_drawBackground2(){ 
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

    
    for(i=0;i<8;i++){
      coordx=fnctn_lndscapeXpos(bkgrnd[i].x_world);
      coordy=fnctn_lndscapeYpos(bkgrnd[i].y_world);
      if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
        gb.display.drawBitmap(coordx   ,coordy  ,sprites[0]);
      }
    }
    break;
   
  }
}



