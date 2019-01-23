int midiIn_chan = 5;
int midiOut_chan[4] = {1,2,3,4};
int mode = 2;
int oldmode = mode;
int count = 0;
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
  if(mode == 1){midiSetup();}
  if(mode == 2){probSeq();}
  oled_draw_bg = 0;
  oldmode = mode;
  count++;
  count %= 5000;
  delayMicroseconds(10);
}
