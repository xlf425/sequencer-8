int step1 = 2;
int step2 = 3;
int step3 = 4;
int step4 = 5;
int step5 = 6;
int step6 = 7;
int step7 = 8;
int step8 = 9;
const int StartStop = 11;
const int Tempo = 14;
int buttonState = 0;  
boolean played = 1;
boolean justStart = 0;
boolean justStop = 0; 
int inh1 = 5;

int knobTempo = A0;
unsigned long previousTempoMillis = 0;
unsigned long currentTempoMillis = 0;
/*unsigned long currentClkMillis = 0;
unsigned long previousClkMillis = 0;*/
int Bpm = 120;
int step = 0;
int maxStep = 9;

long timeDuration = 25;
unsigned long previousLedMillis ;
//cv in
const int clockPin = 12;
boolean clockPinState =0; 
boolean clockPinStateOld =0;
const int pinTempo = 10;


//variable pour les modes
boolean forward = 1;
boolean backward = 0;
boolean randomMode  = 0;
boolean internalClk = 1;
boolean arpegiator = 0;
boolean playArp = 1;
boolean externalClk = 0;
boolean playMode=0;
boolean playing=1;

void setup() {
  Serial.begin(9600);
  //positionnement des pin en OUTPUT
  pinMode(step1, OUTPUT);
  pinMode(step2, OUTPUT);
  pinMode(step3, OUTPUT);
  pinMode(step4, OUTPUT);
  pinMode(step5, OUTPUT);
  pinMode(step6, OUTPUT);
  pinMode(step7, OUTPUT);
  pinMode(step8, OUTPUT);
  pinMode(buttonState, INPUT_PULLUP); 
}



int readTempo(){
  return Bpm = map(analogRead(knobTempo), 0, 1023, 1000, 112);
}

void ledHigh(int ledLabel, int duration){
  analogWrite(ledLabel, duration);
  digitalWrite(ledLabel, HIGH);
}
/*
void clearLeds(){
  int leds[] = {step2, step3, step4, step5, step6, step7, step8};
  for(int i = 0; i < sizeof(leds); i++){
    digitalWrite(leds[i], LOW);
  }
}
*/
void gestionTempo(int bpm) {
  int oneMinute = 60000;
  int delayTime = (oneMinute / bpm);

  

  currentTempoMillis = millis();

  Serial.println(currentTempoMillis - previousTempoMillis);
 
  if (currentTempoMillis - previousTempoMillis >= delayTime ) {
    if (internalClk) {
      analogWrite(pinTempo, 200);
      digitalWrite(pinTempo, HIGH);
      previousLedMillis = millis();
    }
    gestionStep();
    previousTempoMillis = currentTempoMillis;
  }
  unsigned long currentLedMillis = millis();
  if (currentLedMillis - previousLedMillis >= timeDuration) {
    digitalWrite(pinTempo, LOW); 
  } 
}



/*void gestionTempo() {
  //Bpm = map(analogRead(knobTempo), 0, 1023, 600, 40);
  currentTempoMillis = millis();
  //tempo
  int delayTime = (60000 / Bpm) ;
  //switch (buttonState) {
    //case  0 : Bpm = 0; 
      // break; 
     //case  1 : 
      if (currentTempoMillis - previousTempoMillis >= delayTime ) {
      if (internalClk) {
      analogWrite(pinTempo, 200);
      digitalWrite(pinTempo, HIGH);
      previousLedMillis = millis();
      }
      gestionStep();
      previousTempoMillis = currentTempoMillis;
      //Serial.print("step : ");
      //Serial.println(step);
      }
      //break;
  //}
 }
}*/

void loop() {
  int bpm = readTempo();
  Serial.println(bpm);
   
  if (bpm > 150){
    gestionTempo(bpm);
  }
    unsigned long currentLedMillis = millis();
    if (currentLedMillis - previousLedMillis >= timeDuration) {
      digitalWrite(pinTempo, LOW); 
    }
    
}
boolean startStop = HIGH;
/*void loop() {
  //digitalWrite(pinTempo, LOW);
  //gestionLenghtStep();
  //SwitchAction();
  //Serial.print("playing:");
  //Serial.println(playing);
  //Start();
  Bpm = map(analogRead(knobTempo), 0, 1023, 1000, 112);
  //Serial.println(Bpm);
        
  //Serial.println(step);  
    //delay(10) ;
    //delay(25);
    Serial.println(Bpm);
    if (Bpm > 150){
      gestionTempo();
    unsigned long currentLedMillis = millis();
    if (currentLedMillis - previousLedMillis >= timeDuration) {
      digitalWrite(pinTempo, LOW); 
    } 
     buttonState = digitalRead(StartStop);
     Serial.println("if");
    } else {
      Serial.println("else");
    }
}*/
/*
void Start() {
  if (buttonState = 0) {
     Serial.println("played");
      if (!buttonState) {
         justStop = 0;
         justStart = 1; 
       }
      if (buttonState) {
        justStart = 0;
        justStop = 1;
        
        }
  if (buttonState = 0) {
    Serial.println("stop");
    if (justStart) {
      buttonState = 0; 
      step = -1;  
         
    }
    if (justStop) {
      buttonState = 1;
      
    }
   
  }
}
}
*/
/*void gestionArp() {
  Bpm = map(analogRead(knobTempo), 0, 1023, 3000, 300);
  currentTempoMillis = millis();
  
  //trigger arp
  clockPinState = digitalRead(clockPin);
    if(clockPinState==1 && clockPinStateOld != clockPinState){
      clockPinStateOld = clockPinState; 
      playArp=1;
      step=0;
      //Serial.println("Arp");
      Serial.println(playArp);
      if(playArp==1){
        for(int i =0 ; i < maxStep - 1; i++){
        //arp tempo
        int delayTime = (60000 / Bpm) ;
        if (currentTempoMillis - previousTempoMillis >= delayTime ) {
          gestionStep();
          Serial.println("Arp");
          //Serial.println(offset);
          previousTempoMillis = currentTempoMillis;
        }
      }
      playArp=0;
      }
    }
    if(clockPinState==0 && clockPinStateOld != clockPinState){
          clockPinStateOld = clockPinState; 
    }
}*/

}
