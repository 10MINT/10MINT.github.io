int buttonPin[] = {   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  26,  13,  14,  15,  16,  17,  18,  19};
int button[]    = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int buttonOld[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int note[]     = {  66,  57,  84,  83,  82,  81,  80,  79,  78,  77,  76,  75,  74,  73,  72,  71,  70,  69};

int octaveShift = 0;

char potiPin[]     = {A10, A11};
int smoothValue[]   = {  0,   0};
int contrValue[]    = {  0,   0};
int contrValueOld[] = {  0,   0};

int selectPin[] = {0, 1, 2};
int icPin[] = {20, 21};
int bit1;
int bit2;
int bit3;

int button2[]    = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,   LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int buttonOld2[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,   LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int note2[]      = {  40,  56,  68,  67,  40,  65,  64,  63,    62,  61,  60,  59,  58,  55,  54,  53};

void setup() {
  //Serial.begin(9600); //MIDI baud rate is 31250
  for (int i = 0; i < 18; i++) {
  pinMode(buttonPin[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 3; i++) {
  pinMode(selectPin[i], OUTPUT);
  }
  pinMode(icPin[0], INPUT_PULLUP);
  pinMode(icPin[1], INPUT_PULLUP);
}

void loop() {
  multiplexers();
  buttons();
  potentiometers();
  octaves();
  delay(5);
}

void multiplexers() {
  for (int i = 0; i < 8; i++) {
    bit1 = bitRead( i, 0);
    bit2 = bitRead( i, 1);
    bit3 = bitRead( i, 2);
    
    digitalWrite( selectPin[0], bit1);
    digitalWrite( selectPin[1], bit2);
    digitalWrite( selectPin[2], bit3);
    
    // read the signals
    button2[i] = digitalRead(icPin[1]);
    button2[i+8] = digitalRead(icPin[0]);
    
    // first IC4051
    if (button2[i] == LOW && buttonOld2[i] == HIGH) {
      usbMIDI.sendNoteOn(note2[i] + octaveShift, 99, 1); //Teensy MIDI Library
    }
    else if (button2[i] == HIGH && buttonOld2[i] == LOW) {
      usbMIDI.sendNoteOff(note2[i] + octaveShift, 99, 1); //Teensy MIDI Library
    }
    buttonOld2[i] = button2[i];
    
    // second IC4051
    if (button2[i+8] == LOW && buttonOld2[i+8] == HIGH) {
      if (i != 7) {
        usbMIDI.sendNoteOn(note2[i+8] + octaveShift, 99, 1); //Teensy MIDI Library
      }
      else {
        octaveShift = octaveShift - 12;
      }
    }
    else if (button2[i+8] == HIGH && buttonOld2[i+8] == LOW) {
      usbMIDI.sendNoteOff(note2[i+8] + octaveShift, 99, 1); //Teensy MIDI Library
    }
    buttonOld2[i+8] = button2[i+8];
  }
}

//check if any keys are pressed
void buttons() {
  for (int i = 0; i < 17; i++) {
  button[i] = digitalRead(buttonPin[i]);
   if (button[i] == LOW && buttonOld[i] == HIGH) {
    usbMIDI.sendNoteOn(note[i] + octaveShift, 99, 1); //Teensy MIDI Library
   }
   else if (button[i] == HIGH && buttonOld[i] == LOW) {
    usbMIDI.sendNoteOff(note[i] + octaveShift, 99, 1); //Teensy MIDI Library
   }
  buttonOld[i] = button[i]; 
 }
}

//check the potentiometer values
void potentiometers() {
  for (int i = 0; i < 2; i++) {
    smoothValue[i] = 0.6 * smoothValue[i] + 0.4 * analogRead(potiPin[i]);
    contrValue[i] = map(smoothValue[i],0,1023,0,127);
    if (contrValue[i] != contrValueOld[i]) {
     usbMIDI.sendControlChange( 80+i, contrValue[i], 1); //Teensy MIDI Library
    }
   contrValueOld[i] = contrValue[i];
  }
}

//shift the octaves
void octaves() {
  button[17] = digitalRead(buttonPin[17]);
  if (button[17] == LOW && buttonOld[17] == HIGH) {
      octaveShift = octaveShift + 12;
  }
  buttonOld[17] = button[17]; 
}
