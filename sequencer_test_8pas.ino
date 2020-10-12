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
const int ledPin = 10;


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

/*void gestionStep() {

  if (forward) {
    if  (step < maxStep - 1) {
      step++;
    } else {
      step = 0;
    }
  }

  if (backward) {
    if  (step > 0) {
      step--;
    } else {
      step = maxStep - 1;
    }
  }
  if (randomMode) {
    step = random(0,maxStep );
  }
  
  clearLed();
  digitalWrite(step, HIGH);
}
void clearLed(){
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(14, LOW);
  
}
*/
void gestionTempo() {
  //Bpm = map(analogRead(knobTempo), 0, 1023, 600, 40);
  currentTempoMillis = millis();
  //tempo
  int delayTime = (60000 / Bpm) ;
  /*switch (buttonState) {
    case  0 : Bpm = 0; 
       break; 
     case  1 : */
      if (currentTempoMillis - previousTempoMillis >= delayTime ) {
      if (internalClk) {
      analogWrite(ledPin, 200);
      digitalWrite(ledPin, HIGH);
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

void loop() {
  //digitalWrite(ledPin, LOW);
  //gestionLenghtStep();
  //SwitchAction();
  //Serial.print("playing:");
  //Serial.println(playing);
  Start();
  Bpm = map(analogRead(knobTempo), 0, 1023, 1000, 112);
        //Serial.println(Bpm);
        gestionTempo();
  Serial.println(step);  
    //delay(10) ;
    //delay(25);
    unsigned long currentLedMillis = millis();
    if (currentLedMillis - previousLedMillis >= timeDuration) {
      digitalWrite(ledPin, LOW); 
    } 
     buttonState = digitalRead(StartStop);
}
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
