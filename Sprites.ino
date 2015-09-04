//######### Welcome Image #############
const byte PROGMEM gamelogo[] = {72,35,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00011000,B00000000,B00000000,B00000000,B00000001,
B00000000,B00000000,B00000000,B00000000,B00000111,B11000000,B00000000,B00000000,B00111110,
B00000000,B00000000,B00000000,B00000000,B00000000,B01111100,B00000010,B00000001,B11100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000111,B11110010,B01111111,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111101,B11100000,B00000000,
B00000000,B10000000,B00100000,B00000000,B00000000,B00000011,B11011111,B11011111,B00000000,
B00000001,B00011011,B00110110,B11000000,B00000000,B00011110,B00000010,B00000001,B11100000,
B00000001,B00101010,B10100100,B10000000,B00000001,B11110000,B00000111,B00000000,B00111110,
B00000000,B10110011,B00010010,B10000000,B00000111,B00000000,B00000010,B00000000,B00000001,
B00000000,B00000010,B00000000,B00000000,B00011000,B00000000,B00000111,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001101,B10000000,B00000000,
B00000000,B00000000,B01010000,B00000000,B00000000,B00000000,B00011000,B11000000,B00000000,
B00000000,B01010000,B00010000,B00000000,B00000000,B00000000,B00011000,B11000000,B00000000,
B00000000,B10011011,B01010101,B10000000,B00000000,B00000000,B00111111,B11100000,B00000000,
B00000000,B01010010,B01011001,B00000000,B00000000,B00000000,B11101111,B10111000,B00000000,
B00000000,B10001010,B01010100,B10000000,B00000000,B00000001,B11101111,B10111100,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11111111,B11111100,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11111111,B11111100,B00000000,
B00000000,B00000000,B10000000,B00000000,B00000000,B11111111,B11111111,B11111111,B11111000,
B00000111,B11111011,B11101111,B11110000,B00000000,B01111111,B11111111,B11111111,B11110000,
B00000000,B00000001,B11000000,B00000000,B00000000,B00100010,B00011111,B11000010,B00100000,
B00000000,B01111001,B01001111,B00000000,B00000000,B01110111,B00011111,B11000111,B01110000,
B00000000,B00000000,B00000000,B00000000,B00000000,B01110010,B00001111,B10000010,B01110000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00110101,B00000111,B00000101,B01100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,B11111000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,B11110000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000010,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000010,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000001,B00000000,B00000000,B00100001,B00000000,B00000010,B00000000,B00000100,B00000000,
B11000101,B01100011,B00010000,B10100001,B01000100,B01000100,B00100000,B11000101,B00000010,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
};


//######### HUD #############
const byte HUD[] PROGMEM = {40,4, B11011011,B11111111,B11000101,B11111111,B11100000,
                                  B11111010,B00000000,B01001001,B00000000,B00100000,
                                  B01110010,B00000000,B01001101,B00000000,B00100000,
                                  B00100011,B11111111,B11001001,B11111111,B11100000,};


//######### Helicopter ############
const byte PROGMEM helix[4][8] = {
  {15,3,B00000000,B01110000,B00000011,B10000000,B00011100,B00000000},
  {15,3,B00000000,B00000000,B11111111,B11111110,B00000000,B00000000},
  {15,3,B00011100,B00000000,B00000011,B10000000,B00000000,B01110000},
  {15,3,B00000001,B00000000,B00000011,B10000000,B00000001,B00000000}
};

const byte PROGMEM copterShadow[]       = {8,5,B00000000,B01010000,B10101000,B01010000,B00000000,};
const byte PROGMEM copterProfile[]      = {16,6,B10000000,B01000000,B11000001,B11110000,B10111111,B11101000,B01000111,B11100100,B00000011,B00111010,B00000001,B11111110,};
const byte PROGMEM copterProfile_mask[] = {16,6,B10000000,B01000000,B11000001,B11110000,B11111111,B11111000,B01000111,B11111100,B00000011,B11111110,B00000001,B11111110,};
const byte PROGMEM copterDiag1[]        = {16,14,B10000000,B00000000,B11000000,B00000000,B11000000,B00000000,B10100000,B00000000,B01110000,B00000000,B00011000,B00000000,B00001110,B00000000,B00001111,B00000000,B00001111,B10000000,B11111110,B01100000,B01111110,B01110000,B00100111,B01001000,B00010011,B11000000,B00000001,B11000000,};
const byte PROGMEM copterDiag1_mask[]   = {16,14,B10000000,B00000000,B11000000,B00000000,B11000000,B00000000,B11100000,B00000000,B01110000,B00000000,B00011000,B00000000,B00001110,B00000000,B00001111,B00000000,B00001111,B10000000,B11111111,B11100000,B01111111,B11110000,B00110111,B11011000,B00011011,B11000000,B00000001,B11000000,};
const byte PROGMEM copterDiag2[]        = {16,9,B00000000,B01111000,B00000010,B11111000,B00000101,B11110010,B00000011,B11111100,B00000111,B11111000,B00001101,B11000000,B01011000,B00000000,B01101000,B00000000,B00110000,B00000000,};
const byte PROGMEM copterDiag2_mask[]   = {16,9,B00000000,B01111000,B00000011,B11111000,B00000111,B11111110,B00000011,B11111100,B00000111,B11111000,B00001101,B11000000,B01011000,B00000000,B01111000,B00000000,B00110000,B00000000,};
const byte PROGMEM copterDown[]         = {15,7,B00011100,B00000000,B00100010,B00000000,B00100010,B00000000,B11110111,B10000000,B10111110,B10000000,B00011100,B00000000,B00100010,B00000000,};
const byte PROGMEM copterUp[]           = {15,7,B00011100,B00000000,B00111110,B00000000,B00110110,B00000000,B11110011,B10000000,B10111110,B10000000,B00011100,B00000000,B00100010,B00000000,};
const byte PROGMEM copterUpDown_mask[]  = {16,7,B00011100,B00000000,B00111110,B00000000,B00111110,B00000000,B11111111,B10000000,B10111110,B10000000,B00011100,B00000000,B00100010,B00000000,};

//######### Bullet impacts ##########
const byte PROGMEM impact[3][10] = {
  {8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00001000,B00011100,B00000000,},
  {8,8,B00000000,B00000000,B00000000,B00000000,B00001000,B00100010,B00010100,B00000000,},
  {8,8,B00000000,B00000000,B00000000,B00000000,B00100010,B00001000,B01000100,B00000000,}
};

//#########  explosion animation #############
const byte PROGMEM boom[12][14] = {
  {8,12,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00101010,},
  {8,12,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00111110,B00111110,},
  {8,12,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111110,B01111111,B01111111,B01111111,},
  {8,12,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111110,B01111111,B01111111,B01111111,B01111111,B00011100,},
  {8,12,B00000000,B00000000,B00000000,B00000000,B00111110,B01111111,B01111111,B01111111,B01111111,B00011100,B00011100,B00111110,},
  {8,12,B00000000,B00000000,B00111110,B01111111,B01111111,B01111111,B01111111,B00011100,B00001000,B00001000,B00011100,B00111110,},
  {8,12,B00000000,B00111110,B01111111,B01111111,B01111111,B01111111,B00000000,B00000000,B00000000,B00000000,B00001000,B00011100,},
  {8,12,B00000000,B00011100,B00111110,B01111111,B01111111,B00110110,B00000000,B00000000,B00000000,B00000000,B00000000,B00001000,},
  {8,12,B00000000,B00000000,B00011100,B00111110,B00110110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,},
  {8,12,B00000000,B00000000,B00001000,B00011100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,},
  {8,12,B00000000,B00000000,B00000000,B00001000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,},
  {8,12,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,}
};

//Friends
const byte Friend_heliport[] PROGMEM = {16,9,B10101010,B10101000,B00000000,B00000000,B10001101,B10001000,B00001101,B10000000,B10001111,B10001000,B00001101,B10000000,B10001101,B10001000,B00000000,B00000000,B10101010,B10101000,};
const byte Friend_basecamp[] PROGMEM = {24,15,B00000001,B11110000,B00000000,B00000011,B11111000,B00000000,B00000111,B11111100,B00000000,B00000010,B00001000,B00000000,B00111110,B01001111,B10000000,B01111110,B10101111,B11000000,B11111100,B01000111,B11100000,B01000000,B00000000,B01000000,B01011100,B11100111,B01000000,B01010100,B11100101,B01000000,B01011100,B11100111,B01000000,B01000000,B11100000,B01000000,B01000011,B11111000,B01000000,B01111100,B00000111,B11000000,B00000111,B11111100,B00000000,};
const byte Friend_fuel[] PROGMEM = {32,29,B00000000,B00111111,B10000000,B00000000,B00000000,B11010101,B01000000,B00000000,B00011111,B10101011,B11100000,B00000000,B01110101,B11010110,B00000000,B00000000,B10101010,B10111100,B00000000,B00000000,B11011101,B01101011,B00000000,B00000000,B10100111,B11010101,B10000000,B00000000,B11001011,B01111110,B11000000,B00000000,B10010101,B01000000,B00111111,B11111100,B00011101,B01000000,B01000000,B00000010,B00001011,B01000000,B11111111,B11111111,B00001101,B01000000,B10010000,B00001001,B00001001,B01000000,B10100101,B01101001,B00000010,B10000000,B10110101,B01001001,B00000010,B10000000,B10100110,B00100101,B00000100,B10000000,B11111111,B11111111,B00000111,B10000110,B01000000,B00000010,B00000000,B01101001,B01001110,B11111010,B00000000,B10011111,B01001110,B10101010,B00000000,B11100101,B01001110,B11111010,B00000000,B10111101,B01001110,B00000010,B01100000,B10100101,B01111111,B11111110,B10010110,B01100110,B00000000,B00000000,B11111001,B00011000,B00001110,B00111000,B10100111,B00000000,B00001011,B00101100,B10111101,B00000000,B00001110,B10111010,B10100101,B00000000,B00001111,B00111100,B01100110,B00000000,B00001110,B00111000,B00011000,B00000000,B00000000,B00000000,};
const byte Friend_garage[] PROGMEM = {32,26,B00000011,B11100000,B00000000,B00000000,B00001100,B00011000,B00000000,B00000000,B00010000,B00000100,B00000000,B00000000,B00100010,B00000010,B00000000,B00000000,B01000000,B00010001,B00000000,B00000000,B01000000,B00000001,B00000000,B00000000,B10000011,B11100000,B10000000,B00000000,B10101100,B00011000,B10000000,B00000000,B10010000,B00000100,B10111111,B10000000,B10101111,B11111010,B10111101,B10000000,B11010111,B11110101,B10111100,B10000000,B11010111,B11110101,B10111011,B10000000,B10010111,B11110100,B10100111,B10000000,B10010111,B11110100,B10110111,B10000000,B10010111,B11110100,B10111111,B10000000,B11111111,B11111111,B10100000,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000110,B00000000,B00000000,B00000011,B10001000,B00000000,B00000000,B00000010,B01010000,B00000000,B00000000,B00000010,B01100000,B00000000,B00000000,B11111111,B10111100,B01110000,B00000000,B10110000,B00110010,B11100000,B00000000,B11001000,B01001010,B01110000,B00000000,B11001111,B11001100,B11100000,B00000000,};

//Desert
const byte Desert_bush[]    PROGMEM = {8,5,B00100101,B10010010,B01100010,B00111100,B00010000,};
const byte Desert_cactus[]  PROGMEM = {8,9,B00010000,B00011000,B00011000,B01011000,B11011010,B11111011,B01111111,B00011110,B00011000,};
const byte Desert_oasis[]   PROGMEM = {40,24,B00000000,B00000000,B11000000,B00000000,B00000000,B00000000,B00000011,B10111000,B00000000,B00000000,B00000000,B00000101,B01010100,B00000000,B00000000,B00000000,B00001010,B10101010,B00000000,B00000000,B00000000,B00010101,B01010101,B00000000,B00000000,B00000000,B00011001,B10101011,B00000000,B00000000,B00000000,B00010001,B01110101,B00000000,B00000000,B00001000,B00000001,B10110011,B00000000,B00000000,B00001010,B00000001,B00101001,B00000000,B00000000,B00101100,B01000000,B00101000,B00000000,B00000000,B00011100,B01010000,B00101000,B00000000,B00000000,B00000000,B00000000,B00101000,B00000000,B00000000,B00111111,B11111110,B00110000,B00000000,B00000000,B01010101,B01010101,B11000000,B11111100,B00000000,B10101010,B10101010,B10100001,B01000010,B00000000,B11010101,B01010101,B01100010,B10100001,B00000000,B01101010,B11111010,B10100100,B10010000,B10000000,B00011111,B00000111,B11001100,B10011111,B11000000,B00000000,B00110000,B00010111,B11110100,B10100000,B00000001,B00010100,B00000000,B00000000,B00000000,B00000011,B10011110,B00000000,B00000000,B00000000,B00000001,B00011110,B00000000,B00000000,B00000000,B00000010,B10001010,B00000000,B00000000,B00000000,B00000000,B00001010,B00000000,B00000000,B00000000,};
const byte Desert_sand[]    PROGMEM = {8,8,B00000010,B00000000,B01000000,B00000100,B00000000,B00100000,B00000100,B00000000,};
const byte Desert_tree[]    PROGMEM = {8,12,B00000100,B00000100,B10001100,B10101000,B11111000,B01100000,B01101000,B01110000,B00100000,B01100000,B01110000,B11111000,};
const byte Desert_rock[]    PROGMEM = {14,9,B00001100,B00000000,B00011110,B00000000,B00010111,B00000000,B00101011,B10000000,B00110111,B11100000,B01101011,B11110000,B11010101,B11111000,B10101010,B11111100,B11111111,B11111100,};

const byte Forest_grass[]   PROGMEM = {8,8,B00000101,B10100010,B01000000,B00000000,B00001010,B00000100,B01010000,B00100000,};
const byte Forest_tree[]    PROGMEM = {8,14,B00011000,B00101100,B00110100,B00101100,B00110110,B01101010,B01010100,B10101100,B11010100,B01101100,B01010100,B00111000,B00010000,B00010000,};
const byte Forest_forest[]  PROGMEM = {40,24,B00000000,B00000100,B00000000,B00110000,B00100000,B00100000,B00000100,B00000000,B01011000,B01100000,B00100000,B00001010,B00000000,B01101000,B10100000,B01010000,B00010101,B00000000,B01011000,B11100000,B10101000,B00001010,B00000000,B01101100,B10110000,B01010000,B00011111,B00000000,B11010101,B01010000,B11111000,B00000100,B00000000,B10101001,B10110000,B00100000,B00000000,B00000001,B01011001,B01010000,B00000000,B00101100,B00000001,B10101001,B10110000,B00010000,B01011100,B00000000,B11011001,B01010000,B00011000,B10001100,B00000000,B10101000,B11100000,B00101001,B00000110,B00000000,B01110000,B01000000,B01011011,B00011001,B10000000,B00100000,B01000000,B01101001,B00011000,B01100000,B00100001,B00000000,B01011001,B01100110,B10110001,B00000000,B10000000,B01101101,B01100110,B10100001,B01000010,B10100000,B01010101,B00000110,B00100000,B00000001,B01000000,B01101101,B11111111,B11101111,B11111101,B01000000,B01010100,B00000000,B00010000,B00000110,B01000000,B01101100,B00000000,B00100010,B00000001,B11000000,B01010100,B00001000,B01000000,B00100000,B01100000,B00111000,B00001010,B10010000,B10000100,B00010000,B00010000,B00101100,B10000000,B00000011,B11100000,B00010000,B00011100,B01111111,B11111100,B00000000,};
const byte Forest_Tree1[]   PROGMEM = {16,17,B00001111,B00000000,B00110101,B11000000,B01101010,B10110000,B11010101,B01010000,B10101010,B10101000,B11010101,B01010100,B10101010,B10101100,B01010101,B01010100,B10111010,B10101100,B11011101,B11010100,B01101111,B10101000,B00110111,B01010000,B00011111,B11100000,B00000111,B10000000,B00000111,B00000000,B00000111,B00000000,B00001111,B10000000,};
const byte Forest_Tree2[]   PROGMEM = {16,21,B00011111,B00000000,B00110101,B11110000,B01101010,B10101100,B01010101,B01010110,B00101010,B10101010,B00110101,B01011110,B00001111,B11100000,B00000110,B01000000,B00000011,B01001110,B00000001,B11010101,B01111101,B11001010,B10101011,B11111100,B01010111,B11100000,B00111001,B11000000,B00001101,B11000000,B00000111,B11000000,B00000011,B11000000,B00000001,B11000000,B00000001,B11000000,B00000001,B11000000,B00000011,B11100000,};

//FriendlyBuildings
const byte Ennemy_camp[]          PROGMEM = {16,22,B00010000,B00010000,B00111000,B00111000,B01010100,B01010100,B10010010,B10010010,B10101010,B10101010,B11000110,B11000110,B10010010,B10010010,B10010010,B10010010,B11111110,B11111110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00010000,B00010000,B00111000,B00111000,B01010100,B01010100,B10010010,B10010010,B10101010,B10101010,B11000110,B11000110,B10000010,B10000010,B10000010,B10000010,B11111110,B11111110,};
const byte Ennemy_camp_destr[]    PROGMEM = {16,22,B00010000,B00010000,B00010000,B00010000,B01010100,B00010000,B10101010,B00000000,B01010100,B00000000,B10001010,B10001000,B00010100,B01000100,B10010010,B10000000,B01010000,B00001110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01000000,B00000000,B00000000,B01000000,B00000000,B00100000,B00010100,B00010000,B10000000,B00000000,B00000000,B00010010,B00000000,B10001010,B00010010,B10000010,B10010000,B11101100,B11111110,};
const byte Desert_village[]       PROGMEM = {72,41,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,B11111111,B11111111,B00000011,B11111111,B11100111,B11111100,B00000000,B00000000,B00010001,B00010001,B00010001,B00000010,B00000000,B00100100,B00000110,B00000000,B00011000,B00011111,B11111111,B11111111,B00000010,B11111111,B10100101,B11110101,B00000000,B11101110,B00010001,B00010001,B00010001,B00000010,B10000000,B10100101,B00010110,B11000001,B01010101,B00010000,B11000000,B00000001,B00000010,B10000000,B10100101,B00010101,B01100010,B10101010,B10010000,B01010000,B00001101,B00000011,B11111111,B11100111,B11111110,B10100101,B01010101,B01010000,B01111000,B00101001,B00000010,B00000000,B00100100,B00000101,B01100110,B10101100,B11010000,B01111000,B01111001,B00000010,B10101010,B10100101,B01010110,B10100101,B01110100,B01010000,B00101000,B01111001,B00000010,B00000000,B00100100,B00000101,B01100110,B01101100,B00010000,B00101000,B01010001,B00000010,B11001100,B00100101,B10000100,B11100101,B10100100,B00010000,B00000000,B01010001,B00000010,B11001100,B00100101,B10000100,B00100000,B10100000,B00010000,B00000000,B00000001,B00000010,B11000000,B00100101,B10000100,B00100000,B10100000,B00010000,B00110011,B00000001,B00000011,B11111111,B11100111,B11111100,B00100000,B10100000,B00010000,B10100001,B01000001,B00000000,B00000000,B00000000,B00000000,B00000000,B01100000,B00010001,B11100001,B11100001,B00000011,B00000000,B00000000,B00000000,B00000000,B00000000,B00010001,B11100001,B11100001,B00011101,B11000000,B00000000,B00000000,B00000000,B00000000,B00010001,B01000000,B10100001,B00101010,B10110000,B00000000,B00000000,B00000000,B00000000,B00010001,B01000000,B10100001,B01010101,B01010000,B00000000,B00011110,B00000000,B00000000,B00010000,B00000000,B00000001,B10101010,B10101000,B10000000,B00100001,B00000000,B00000000,B00011111,B11111111,B11111111,B11010101,B10011000,B00000000,B01011110,B10000000,B00000000,B00010001,B00010001,B00010001,B10101110,B10001000,B00000000,B01011110,B10000000,B00000000,B00011111,B11111111,B11111111,B11001101,B10000000,B00000000,B01100001,B10000000,B00000000,B00010001,B00010001,B00010001,B10010100,B10000000,B00000000,B01011110,B10000000,B00000000,B00000000,B00000000,B00000000,B00010100,B00000000,B00000000,B00100001,B00000000,B00000000,B00000000,B00000000,B00000000,B00010100,B11111111,B11111110,B00011110,B00000000,B00000000,B00000000,B00000000,B00000000,B00010100,B10000000,B00000010,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001100,B10111111,B11111111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10100000,B00000001,B00000011,B11111110,B00000011,B11111110,B00000000,B11000000,B00000000,B10100000,B00000001,B00000010,B00000010,B00000010,B00000010,B00000011,B10111000,B00000000,B11111111,B11111111,B00000010,B11111011,B10001110,B11111010,B00000101,B01010100,B00000000,B10000000,B00001001,B00000010,B10001011,B01110110,B10001010,B00001010,B10101010,B00000000,B10101010,B10101111,B00000010,B10001010,B10101010,B10001010,B00010101,B01010101,B00000000,B10000000,B00001001,B00000011,B11111111,B01010111,B11111110,B00011001,B10101011,B00000000,B10110011,B00001111,B00000010,B00000010,B10101010,B00000010,B00010001,B01110101,B00000000,B10110011,B00001001,B00000010,B10101011,B01010110,B10101010,B00000001,B10110011,B00000000,B10110000,B00001111,B00000010,B00000011,B10101110,B00000010,B00000001,B00101001,B00000000,B11111111,B11111000,B00000010,B11000010,B01110010,B11000010,B00000000,B00101000,B00000000,B00000000,B00000000,B00000010,B11000010,B00000010,B11000010,B00000000,B00101000,B00000000,B00001000,B00000000,B00000010,B11000010,B00000010,B11000010,B00000000,B00101000,B00000000,B00000000,B00000000,B00000011,B11111110,B00000011,B11111110,B00000000,B00110000,};
const byte Desert_village_destr[] PROGMEM = {72,41,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000111,B11111000,B11111111,B00000000,B00000000,B00000111,B11000000,B00000000,B00000000,B00000001,B00010000,B00010001,B00000000,B10000000,B00000100,B01100000,B00000000,B00000000,B00001111,B11111100,B11111111,B00010000,B00001001,B10000101,B11100000,B00000000,B00000000,B00010001,B00010000,B00010001,B00001000,B10000001,B00100101,B01110000,B00000000,B01000000,B00010000,B00000000,B00000001,B00000000,B00000000,B00000101,B00011000,B00100000,B11100000,B00010010,B10000000,B00000001,B00110000,B00000000,B00000111,B10001100,B00100000,B01000000,B00010010,B10000000,B00101000,B00000010,B01011000,B01100100,B11101100,B00100000,B11100000,B00010011,B11000000,B00101000,B00000011,B11111111,B11111101,B01111100,B00100000,B01100001,B00010011,B11000000,B01111000,B00100110,B11000001,B01100100,B00111100,B00000000,B01100000,B00010001,B01000000,B01111000,B01100110,B00110000,B01110101,B10001100,B00100000,B11100000,B00010000,B01100000,B01010001,B00001110,B10011000,B00100101,B10000100,B00100000,B11100100,B00000000,B00000000,B11000001,B01000010,B00000000,B11100101,B10000100,B00100000,B11100010,B00010000,B00000000,B00000001,B00000111,B11111111,B11100111,B11111100,B00100000,B11100000,B00000111,B10000010,B00000000,B00010101,B00000000,B00000000,B00000000,B00000000,B01100000,B00010001,B11000011,B11000001,B00000000,B00000010,B00000000,B00000000,B00000000,B00000000,B00010111,B10000000,B11110001,B00000000,B00001001,B01100100,B00000000,B00000000,B00000000,B00010001,B11100001,B11000001,B00001000,B00000000,B00000000,B00000000,B00000000,B00000000,B00010000,B00100000,B11110001,B00001100,B00000010,B00000000,B00011110,B00000000,B00000000,B00010000,B00000000,B00000001,B00001000,B00000000,B10000000,B00100001,B00000000,B00000000,B00001111,B10011100,B00111111,B00001100,B00000000,B00000000,B01011110,B10000000,B00000000,B00000001,B01010000,B00010001,B00001100,B00000000,B00000000,B01011110,B10000000,B00000011,B00111111,B11111110,B00011111,B00011100,B00000000,B00000000,B01100001,B10000000,B00000000,B00010001,B00010001,B00010001,B00011100,B00000000,B00000000,B01011110,B10000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00000000,B00000000,B00100001,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00011100,B00011110,B00011110,B00000000,B00000000,B00000000,B00000000,B00000000,B00011100,B00100010,B00100010,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001100,B01011111,B11111011,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10100111,B11100101,B00000000,B00000000,B00000000,B00000010,B00000000,B00000000,B00000000,B10100110,B11100010,B00000000,B00000000,B00000000,B00011110,B00000000,B00000000,B00000000,B11111110,B00111100,B00000000,B00000000,B00000000,B00111110,B00000000,B00000000,B00000000,B10000011,B10001000,B00000001,B00000110,B00000000,B01100110,B00010000,B00100000,B00000000,B10100010,B10101000,B00000001,B00000000,B00000001,B11101110,B00110000,B00010000,B00001000,B10000000,B00111000,B00000000,B00000000,B00000011,B10011110,B00000000,B00110000,B00000000,B00110011,B01111110,B01110000,B00000000,B00000011,B01110010,B00000000,B01111000,B00000110,B10111011,B01111001,B01010000,B00100000,B00000011,B11001010,B00000000,B10010100,B00010000,B10110000,B11111111,B01001001,B01011000,B10011011,B10000010,B01100001,B00110010,B00000000,B11111111,B11111000,B00110001,B11101111,B00000010,B11000010,B00000000,B00111010,B00000000,B00000000,B00000000,B00000111,B11010101,B10000010,B11000010,B00011100,B00111000,B00010000,B00001000,B00000000,B00100110,B11000110,B10000010,B11000010,B00000110,B00011000,B00000000,B00000000,B00000000,B00000011,B11111111,B00000011,B11111110,B00000000,B00011000,};
const byte Forest_Village[]       PROGMEM = {72,41,B00001110,B00000000,B00000000,B00001000,B00001111,B11100000,B00000000,B00000000,B00000000,B00011011,B11000000,B00000000,B00011100,B00010101,B01010000,B00000000,B00000000,B00000000,B00010101,B01110000,B00000000,B00001000,B00101010,B10110000,B00000000,B00001001,B00100100,B00101010,B10101000,B00000000,B00001000,B00110101,B01010000,B00010100,B00000100,B10010010,B01010101,B01011000,B00000000,B00011100,B00101010,B10110000,B00001000,B00001001,B00100100,B01101010,B10101100,B00000000,B00011100,B00010101,B01010000,B00000000,B00000100,B10010010,B00110101,B01010100,B00101000,B00111110,B00001111,B11100000,B01111110,B00001001,B00100100,B00011010,B10111000,B00010000,B00111110,B00000011,B10000000,B11111111,B00000100,B10010010,B00000111,B11000000,B00000000,B01111111,B00000011,B10000001,B11111111,B10001001,B00100100,B00000011,B00000000,B00000000,B01111111,B00000011,B10000001,B11111111,B10000100,B10010010,B00000011,B00000000,B00000000,B00100010,B00000000,B00000000,B10000001,B00001001,B00100100,B00000000,B00011110,B00000000,B00100010,B00000000,B00000000,B10101101,B00000100,B10010010,B00000000,B00111111,B00000000,B00101010,B00000000,B00000000,B10101101,B00001001,B00100100,B00000000,B01110011,B10000000,B00101011,B11111100,B00000000,B10100001,B00000100,B10010010,B00000000,B01101101,B11100000,B00100011,B11111110,B00000000,B11111111,B00001001,B00100100,B00000000,B00101101,B11110000,B00100011,B11111111,B00000000,B00000000,B00000000,B00000000,B00000000,B00100000,B00100000,B00101010,B00000010,B00000000,B00000000,B00000000,B00000000,B00000000,B00101101,B10100000,B00101010,B11011010,B00000000,B00011111,B11000000,B00000000,B00000000,B00101101,B10110000,B00101010,B11011010,B00000000,B00111111,B11100000,B00000000,B00000000,B00101100,B00101000,B00101010,B00000010,B00000000,B01111111,B11110000,B00001010,B00101000,B00111111,B11110100,B00111111,B11111110,B00000000,B01111111,B11110000,B00000100,B00010000,B00000000,B00000000,B00000000,B00000000,B00000000,B00100000,B00100000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00101101,B10100000,B00000000,B00000000,B01111100,B00000000,B00000000,B00000000,B00000000,B00101101,B10111111,B10000000,B00000001,B10101010,B00000000,B00000011,B11000000,B00000000,B00100000,B00111111,B11000000,B00000001,B01010101,B10000000,B00000100,B00100000,B00101000,B00100000,B00100000,B11000000,B00000010,B10101010,B10000000,B00001011,B11010000,B00010000,B00101101,B10101110,B10000000,B00000011,B01010101,B01000000,B00001011,B11010000,B00000000,B00101101,B10101110,B10000000,B00000010,B10101010,B11000000,B00001100,B00110000,B00000000,B00101100,B00101110,B10000000,B00000011,B01010101,B01000000,B00001011,B11010000,B00000000,B00111111,B11111111,B10111000,B00000010,B10101010,B11000000,B00000100,B00100001,B11111100,B00000000,B00000000,B01010110,B00000001,B01010101,B10000000,B00000011,B11000011,B11111110,B00000000,B00000001,B10101011,B00000000,B11111111,B00000001,B01000000,B00000111,B11111111,B00000000,B00000001,B01010101,B00000000,B00111100,B00000000,B10000000,B00000111,B11111111,B00000000,B00000010,B10101011,B00000000,B00111100,B00000000,B00000000,B00000010,B00000010,B00000000,B00000011,B01010101,B00000000,B00111100,B00000000,B00000000,B00000010,B10111010,B00000000,B00000010,B10101011,B00000000,B00111110,B00000000,B00000000,B00000010,B10111010,B00000000,B00000001,B01010110,B00010100,B01010101,B00000000,B00000000,B00000010,B10000010,B00000000,B00010100,B11111100,B00001000,B00000000,B00000000,B00000000,B00000011,B11111110,B00000000,B00001000,B00110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,};
const byte Forest_Village_destr[] PROGMEM = {72,41,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001010,B00000000,B00000000,B00000000,B00000101,B00100000,B00000000,B00000000,B00000000,B00000110,B00000000,B00000000,B00000000,B00011000,B10110000,B00000000,B00001001,B00100100,B00000100,B00100000,B00000000,B00000000,B00001000,B01100000,B00010100,B00000100,B10010010,B00000100,B00010100,B00000000,B00000000,B00000110,B01000000,B00001000,B00001001,B00100100,B00100110,B01111000,B00000000,B00000000,B00000010,B11000000,B00000000,B00000101,B10010110,B00111011,B11000000,B00101000,B00000000,B00000011,B10000000,B01000000,B00001001,B00101100,B00001111,B10000000,B00010000,B00000000,B00000011,B10000000,B01000100,B00000100,B10010010,B00000011,B00000000,B00000000,B00000000,B00000011,B10000001,B01010101,B00001001,B11111100,B00000011,B00000000,B00000000,B00000000,B00000011,B10000000,B11111111,B10001101,B11111010,B00000011,B00000000,B00000000,B00000010,B00000000,B00000000,B10000001,B00001001,B00100100,B00000000,B00000000,B00000000,B00000110,B00000000,B00001100,B10101101,B00000100,B10011110,B00000000,B00000000,B00000000,B00001010,B00000000,B00000010,B10101101,B00001111,B00100110,B00000000,B00000010,B00010000,B00011010,B10101000,B00000000,B10100010,B01101100,B10010010,B00000000,B01000001,B00100000,B00010010,B10101010,B00010000,B11111100,B00001001,B00100100,B00000000,B00011001,B01011000,B00100011,B11111111,B00000110,B00000010,B00000000,B00000000,B00001001,B00000110,B00000000,B00101010,B00000010,B00100100,B10000000,B00000000,B00000000,B00000000,B10111111,B11100100,B01101010,B11011010,B00000000,B00000000,B00000000,B00000000,B00000000,B11100000,B00100000,B11101010,B11011010,B00000000,B00000000,B00000000,B00000000,B00000001,B10100100,B00110001,B10101010,B00000010,B10000000,B00000000,B00000000,B00001010,B00101000,B00111111,B11101010,B11111111,B11111110,B01000000,B00000000,B00000000,B00000100,B00010000,B01100001,B10000000,B01000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10001100,B01000110,B00010100,B00000100,B00000000,B00100000,B01100000,B00000000,B00000000,B00000101,B00010000,B10010000,B00000010,B00000000,B00110010,B01101000,B00000000,B00000000,B00010000,B10000001,B11100011,B11000000,B00000000,B00101101,B11111100,B00000000,B00000000,B00010000,B00000000,B10000100,B00100000,B00101000,B00100000,B00100010,B00001000,B00000011,B00110000,B10000000,B00001011,B11010000,B00010000,B00101101,B10101111,B00010000,B00000001,B11100100,B10000000,B00001011,B11010000,B00000000,B00101101,B10101110,B10000000,B00000001,B10000111,B10000000,B00001100,B00110000,B00000000,B00101100,B00101110,B10011100,B00000001,B11000011,B00000000,B00001011,B11010000,B00000001,B10111111,B11111111,B10000000,B00000000,B11100110,B00000000,B00000100,B00100001,B01000001,B00000000,B00000000,B00000000,B00000000,B01111110,B00000000,B00000011,B11000011,B11000000,B00000000,B10000000,B01011000,B00000000,B00111100,B00000001,B01000000,B00000111,B11100000,B00000110,B01100000,B10001010,B00000000,B00111100,B00000000,B10000000,B00000111,B11110000,B01001000,B00000010,B10000110,B00000000,B00111100,B00000000,B00000000,B00000010,B00001000,B10000000,B00000001,B10000100,B00000000,B00111100,B00000000,B00000000,B00000010,B10011110,B00000000,B00000000,B11001100,B00000000,B00111110,B00000000,B00000000,B00000001,B10101010,B00000000,B00000000,B01101000,B00010100,B01010101,B00000000,B00000000,B00100010,B10000010,B10000000,B00010100,B00111000,B00001000,B00000000,B00000000,B00000000,B01110011,B11111110,B00100000,B00001000,B00110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,};

//Ennemy
const byte Ennemy_bunker[]       PROGMEM = {32,32,B00001000,B00000000,B00000000,B00100000,B00111110,B00000000,B00000000,B11111000,B01001001,B00000000,B00000001,B00100100,B01000001,B11111111,B11111111,B00000100,B11100001,B01010101,B01010101,B00001110,B01000001,B10101010,B10101011,B00000100,B01000001,B01010101,B01010101,B00000100,B01111110,B11111111,B11111110,B11111100,B01010101,B10000000,B00000011,B01010100,B01011010,B10010001,B00010010,B10110100,B01010101,B10010001,B00010011,B01010100,B01011010,B10010001,B00010010,B10110100,B01010101,B10000000,B00000011,B01010100,B01111010,B11111111,B11111110,B10111100,B00010101,B10000000,B00000011,B01010000,B00011010,B10000000,B00000010,B10110000,B00010101,B10000000,B00000011,B01010000,B00011010,B10000000,B00000010,B10110000,B00010101,B10000000,B00000011,B01010000,B00111110,B11111111,B11111110,B11111000,B01000001,B01010101,B01010101,B00000100,B01000001,B10101010,B10101011,B00000100,B11100001,B01010101,B01010101,B00001110,B01000001,B11111111,B11111111,B00000100,B01001001,B00000000,B00000001,B00100100,B01111111,B00001111,B11100001,B11111100,B01001001,B00010111,B11010001,B00100100,B01000001,B00010111,B11010001,B00000100,B01001001,B00010111,B11010001,B00100100,B01001001,B11111111,B11111111,B00100100,B01000001,B00000000,B00000001,B00000100,B01111111,B00000000,B00000001,B11111100,};
const byte Ennemy_bunker_destr[] PROGMEM = {32,32,B00000000,B00000000,B00000000,B00000000,B00000110,B00000000,B00000000,B01010000,B00001001,B00000000,B00000010,B00010010,B00000101,B01011100,B00000001,B00000000,B00001001,B00010100,B00000000,B00000000,B01110001,B10101010,B01000000,B00001100,B01000001,B01010101,B00001010,B00100000,B01111110,B11111111,B10000001,B00000100,B01010101,B10000000,B01000000,B00010010,B01010000,B10010001,B00100000,B00000000,B01010001,B10010101,B00100001,B11100100,B01001010,B10010001,B00011010,B10111000,B01001101,B10000000,B00001101,B01010000,B01101110,B11111111,B11111010,B10111110,B00010110,B00000001,B10000111,B01010110,B01011010,B00000011,B01100010,B10111100,B10010111,B00000001,B11000001,B01010000,B00011010,B10000001,B00111010,B10110000,B00010101,B10000000,B00000011,B01010000,B00111110,B11111110,B00001110,B11111000,B00000001,B01010101,B11110101,B00000100,B00000001,B10101010,B10101011,B00100100,B00001111,B01010111,B11010101,B00010100,B00110101,B11110111,B11111111,B00101000,B01101011,B00011111,B10000001,B01001000,B11010101,B00011001,B11100001,B11100100,B10101011,B00111111,B11110001,B01011100,B11010101,B01100011,B11010001,B00100100,B01111001,B00011111,B11010001,B01000100,B01001001,B11110111,B11111111,B00100100,B11000001,B00010100,B00000001,B00010100,B01111111,B00001100,B00000001,B11111100,};
const byte Ennemy_tour[]         PROGMEM = {8,10,B01111100,B11111110,B01000100,B01111100,B01111100,B01000100,B01101100,B01010100,B01101100,B01000100,};
const byte Ennemy_tour_destr[]   PROGMEM = {8,10,B00000000,B00000000,B00000000,B00100000,B01110000,B01000100,B01101000,B11010100,B01111010,B11111110,};
const byte Ennemy_Unit[]         PROGMEM = {6,6,B11100000,B11100000,B01011100,B11110000,B11100000,B10100000,};

const byte Ennemy_Tank[]          PROGMEM = {16,14,B00001000,B00000000,B00001000,B00000000,B00001001,B10000000,B00000110,B01111111,B00001000,B00100000,B00111000,B00111100,B00111111,B11111110,B00111111,B11111110,B00111111,B11111110,B00100000,B00000010,B00010101,B01010100,B00001111,B11111000,B00000000,B00000000,B00000000,B00000000,};
const byte Ennemy_Tank_diagdown[] PROGMEM = {16,14,B00000010,B00000000,B00000010,B00000000,B00000010,B00000000,B00000011,B11100000,B11111110,B00010000,B11111100,B00001000,B10111100,B01101000,B10011110,B00111000,B11001111,B11101100,B01100111,B11110110,B00110011,B11111011,B00011001,B11111111,B00001111,B11111111,B00000011,B10001110,};
const byte Ennemy_Tank_Down[]     PROGMEM = {16,14,B00000010,B00000000,B00111111,B11111000,B00111101,B11111000,B00111100,B01111000,B00111000,B00111000,B00111000,B00111000,B00111001,B00111000,B00111101,B01111000,B00111110,B11111000,B00111110,B11111000,B00111110,B11111000,B00111110,B11111000,B00100111,B11001000,B00111100,B01111000,};
const byte Ennemy_Tank_Up[]       PROGMEM = {16,14,B00000000,B10000000,B00000000,B10000000,B00001111,B11111000,B00011111,B01111100,B00011111,B01111100,B00011110,B00111100,B00011100,B01011100,B00011100,B01011100,B00011110,B00111100,B00011111,B11111100,B00011111,B11111100,B00011111,B11111100,B00010011,B11100100,B00011110,B00111100,};
const byte Ennemy_Tank_diagup[]   PROGMEM = {16,14,B00000010,B00011000,B00000010,B00110000,B00000010,B01100000,B00000111,B11000000,B00001010,B01111110,B00010110,B00111111,B00010000,B00111101,B00010000,B01111001,B00111111,B11110011,B01111111,B11100110,B11111111,B11001100,B11111111,B10011000,B11111111,B11110000,B01110001,B11000000,};


const byte* spriteBkg[]={
  Desert_bush,    //0
  Desert_cactus,  //1
  Desert_oasis,   //2
  Desert_sand,    //3
  Desert_tree,    //4
  Desert_rock,    //5
  Forest_grass,   //6
  Forest_tree,    //7
  Forest_forest,  //8
  Forest_Tree1,   //9
  Forest_Tree2    //10
};


const byte* tank[]={
  Ennemy_Tank,          //0
  Ennemy_Tank_diagdown, //1
  Ennemy_Tank_Down,     //2
  Ennemy_Tank_Up,       //3
  Ennemy_Tank_diagup    //4
};



const byte* sprites[]={
  Friend_heliport,      //0
  Friend_basecamp,      //1
  Friend_fuel,          //2
  Friend_garage,        //3
  Desert_village,       //4
  Forest_Village,       //5
  Ennemy_bunker,        //6
  Ennemy_camp,          //7
  Ennemy_tour,          //8
  Desert_oasis,         //9
  Forest_forest         //10
};

const byte* destroy[]={
  Friend_heliport,      //0
  Friend_basecamp,      //1
  Friend_fuel,          //2
  Friend_garage,        //3
  Desert_village_destr, //4
  Forest_Village_destr, //5
  Ennemy_bunker_destr,  //6
  Ennemy_camp_destr,    //7
  Ennemy_tour_destr     //8
};

