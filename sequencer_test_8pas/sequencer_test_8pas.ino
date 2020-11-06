/* tempo led and knob */
const int knobTempo = A0;
const int pinTempo = 10;
const int forward = 0;
const int backward = 1;
const int randomMode = 2;
int maxStep = 9;

const int stepPin = 9;

const long minute = 60000;

void setup()
{
  Serial.begin(9600);
  pinMode(pinTempo, OUTPUT);
}

void loop()
{
  int bpm = readTempo();
  blinkTempoLed(bpm);
}

/* read the current tempo from 112 to 1000 */
int readTempo(){
  return map(analogRead(knobTempo), 0, 1023, 1000, 112);
}

void blinkTempoLed(int bpm){
  static int ledState = LOW;
  static unsigned long previousMillis = 0;
  static unsigned long currentMillis = 0;
  int interval = minute / bpm;
  
  Serial.println(bpm);
  
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    
    ledState = !ledState;
    
    digitalWrite(pinTempo, ledState);
  }
}

void blinkStepPin(int playMode){
  static int actualStep = 0;
  switch(playMode){
    case forward : 
    if(actualStep < stepPin) actualStep++; else actualStep = 0;
    break;
    case backward :
    if(actualStep > stepPin) actualStep--; else actualStep = stepPin;
    break; 
    case randomMode : 
    actualStep = random(0, maxStep);
    break;
  }  
  stepPinOff();
}

void stepPinOff(){
 int i = 0;
 while(i++ < stepPin){
  digitalWrite(i, LOW);
 }
}
