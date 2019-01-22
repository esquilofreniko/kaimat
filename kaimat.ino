int mode = 2;
int oldmode = mode;
int count = 0;
bool key_pressed = 0;
bool oled_draw_bg = 1;

void setup(){
  Serial.begin(9600);
  midi_init(); 
  hardware_init();
}

void loop(){
  midi_read();
  hardware_read();
  if(oldmode != mode){oled_clear();}
  if(mode == 0){mainMenu();}
  if(mode == 1){hardwareTest();}
  if(mode == 2){probSeq();}
  oled_draw_bg = 0;
  oldmode = mode;
  key_pressed = 0;
  count++;
  count %= 500;
  delayMicroseconds(10);
}
