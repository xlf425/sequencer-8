/* Sequencer max steps knobs */
const int maxStep = 9;

/* Sequencer tempo knob/pin configuration */
const int knobTempo = A0;
const int pinTempo = 10;

/* PlayMode available */
const int forward = 0;
const int backward = 1;
const int random = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(pinTempo, OUTPUT);
}

void loop()
{
  int bpm = readTempo();
  blinkTempoLed(bpm);
  blinkStepPin(forward);
}

/* read the current tempo from 112 to 1000 */
int readTempo(){
  return map(analogRead(knobTempo), 0, 1023, 1000, 112);
}

/* Blink the tempo led at the bpm speed */
void blinkTempoLed(int bpm){
  const long minute = 60000;
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
  static int actualStep = 2;
  switch(playMode){
    case forward : 
    if(actualStep < maxStep) actualStep++; else actualStep = 0;
    break;
    case backward :
    if(actualStep > maxStep) actualStep--; else actualStep = maxStep;
    break; 
    case random : 
    actualStep = random(0, maxStep);
    break;
  }  
  stepPinOff();
}

void stepPinOff(){
  int i = 0;
  while(i++ < maxStep){
    digitalWrite(i, LOW);
  }
}
