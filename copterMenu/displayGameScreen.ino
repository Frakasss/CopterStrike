#define MENU_PLAY 0
#define MENU_DELETESAVE 1
#define MENU_DELETEGAME 2

#define MENU_SIZE 3


#define MIN_VITT_BOUCHE_G 3
#define MAX_VITT_BOUCHE_G 8
int8_t nextMoveG;
bool boucheOuverte;
const byte general1[] PROGMEM = {32,25,0x7F,0xFF,0xFF,0xE0,0xFF,0xFF,0xFF,0xF0,0xFF,0xE0,0xFF,0xF0,0xFF,0xFB,0xFF,0xE0,0x3F,0xFF,0xFF,0xC0,0x1F,0xFF,0xFF,0x80,0x1F,0xFF,0xFF,0x0,0x1F,0xFF,0xFF,0x0,0xF,0xFF,0xFD,0x0,0xF,0xFF,0xF1,0x0,0x9,0xF8,0x3,0x0,0x9,0xF0,0x82,0x0,0x8,0xE0,0xE2,0x0,0xC,0x40,0x2,0x0,0x8,0x8,0x2,0x0,0x48,0xE,0x2,0x20,0xF8,0x0,0x3,0xF0,0x98,0x0,0x1,0x90,0xB8,0x1F,0x83,0xD0,0xF8,0x3F,0xC3,0xF0,0xFE,0x0,0x7,0xF0,0xFF,0x80,0xF,0xF0,0xFF,0xF0,0x7F,0xF0,0xFF,0x70,0x77,0xF0,0xFF,0x1F,0xC7,0xF0,};
const byte general2[] PROGMEM = {32,25,0x7F,0xFF,0xFF,0xE0,0xFF,0xFF,0xFF,0xF0,0xFF,0xE0,0xFF,0xF0,0xFF,0xFB,0xFF,0xE0,0x3F,0xFF,0xFF,0xC0,0x1F,0xFF,0xFF,0x80,0x1F,0xFF,0xFF,0x0,0x1F,0xFF,0xFF,0x0,0xF,0xFF,0xFD,0x0,0xF,0xFF,0xF1,0x0,0x9,0xF8,0x3,0x0,0x9,0xF0,0x82,0x0,0x8,0xE0,0xE2,0x0,0xC,0x40,0x2,0x0,0x8,0x8,0x2,0x0,0x48,0xE,0x2,0x20,0xF8,0x0,0x3,0xF0,0x98,0x0,0x1,0x90,0xB8,0x1F,0x83,0xD0,0xF8,0x20,0x43,0xF0,0xFE,0x10,0x87,0xF0,0xFF,0x8F,0xF,0xF0,0xFF,0xF0,0x7F,0xF0,0xFF,0x70,0x77,0xF0,0xFF,0x1F,0xC7,0xF0,};


byte slideNumber;
byte currentSlide;
byte menuSelection;
boolean askingConfirmation;
byte scrollBarTimeLeft;

void displayGameScreen() {
  initDisplayGameScreen();

  while (1) {
    if (gb.update()) {
      if (gb.buttons.pressed(BTN_B) || gb.buttons.pressed(BTN_C)) {
        gb.sound.playTick();
          return;
      }
      if (gb.buttons.pressed(BTN_A)) {
        gb.sound.playTick();
            loadSelectedFile();
      }

      if (gb.buttons.pressed(BTN_UP) || (gb.buttons.states[BTN_UP] > 10 && gb.buttons.repeat(BTN_UP, 3))) {
        currentSlide += slideNumber - 1;
        currentSlide %= slideNumber;
        drawSlide(currentSlide);
        scrollBarTimeLeft = 12;
          nextMoveG = -1;
      } else {
        if (gb.buttons.pressed(BTN_DOWN) || (gb.buttons.states[BTN_DOWN] > 10 && gb.buttons.repeat(BTN_DOWN, 3)))  {
          currentSlide ++;
          currentSlide %= slideNumber;
          drawSlide(currentSlide);
          scrollBarTimeLeft = 12;
          nextMoveG = -1;
        }
      }
      
      if ((slideNumber > 1) && (scrollBarTimeLeft > 0)) {
        scrollBarTimeLeft --;
        if (!scrollBarTimeLeft) { //time to hide the scrollbar and redraw the bitmap
          gb.display.setColor(WHITE);
          gb.display.fillRect(LCDWIDTH - 5, 7, 5, LCDHEIGHT - 7 - 7);
          gb.display.setColor(BLACK);
          drawSlide(currentSlide);
          nextMoveG = -1;
        } else { //draw the scrollbar
          gb.display.setColor(WHITE);
          gb.display.fillRect(LCDWIDTH - 5, 7, 5, LCDHEIGHT - 7 - 7);
          gb.display.setColor(BLACK);
          gb.display.drawRect(LCDWIDTH - 4, 7, 1, LCDWIDTH - 4);
          gb.display.drawRect(LCDWIDTH - 1, 7, 1, LCDWIDTH - 1);
          gb.display.fillRect(LCDWIDTH - 3,
                              7 + currentSlide * (LCDHEIGHT - 7 - 7) / slideNumber,
                              3,
                              1 + max(3, (LCDHEIGHT - 7 - 7) / slideNumber));
        }
      }

      if(nextMoveG<0){
        nextMoveG = random(MIN_VITT_BOUCHE_G,MAX_VITT_BOUCHE_G);
        boucheOuverte = !boucheOuverte;
        
          gb.display.setColor(WHITE);
          gb.display.fillRect(0,0,28,25);
          gb.display.setColor(BLACK);
          
          if(boucheOuverte){
            gb.display.drawBitmap(0,0,general1);
          }else {
            gb.display.drawBitmap(0,0,general2);
          }
      }
      nextMoveG--;
    }
  }
}

void initDisplayGameScreen() {

  gb.display.clear();
  gb.display.setColor(BLACK);

  slideNumber = 0;
  currentSlide = 0;
  scrollBarTimeLeft = 30;
  nextMoveG = 0;
  boucheOuverte = false;
  
  menuSelection = 0;
  askingConfirmation = false;

  strcpy(completeName, thisPageFiles[cursorPos]);
  strcat(completeName, ".INF");
  bool displayed = false;
  //loads the .inf file
  if (file.open(completeName, O_READ)) {
    if (file.read(buffer, HEADERSIZE) == HEADERSIZE && buffer[VERSIONOFFSET] == 0x01) {
      buffer[1 + NAMEOFFSET + NAMELENGTH] = '\0';
      displayed = true; // this file has an INF file!
      gb.display.cursorY = 5;
      gb.display.cursorX = 30;
      gb.display.print(buffer + NAMEOFFSET);
      slideNumber = buffer[SLIDENUMBEROFFSET];
    }
  }
  if (!displayed) {
    strcpy(completeName, thisPageFiles[cursorPos]);
    strcat(completeName, ".HEX");
    buffer[NAMELENGTH] = '\0';
    file.open(completeName, O_READ);
    gb.display.cursorY = 5;
    gb.display.cursorX = 30;
    if (file.isLFN()) {
      file.getName(buffer, NAMELENGTH);
      gb.display.print(buffer);
    } else {
      gb.display.print(thisPageFiles[cursorPos]);
    }
  }
  file.close();

  if (!drawSlide(currentSlide)) {
    gb.display.cursorY = 22;
    gb.display.cursorX = 3;
    gb.display.print(F(" - GOGOGOGOGO ! War dont wait ! - "));
  }
}
