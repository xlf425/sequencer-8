/* Sequencer max steps knobs */
const int minStep = 2;
const int maxStep = 9;

const int minBpm = 60;
const int maxBpm = 400;

/* Sequencer tempo knob/pin configuration */
const int knobTempo = A0;
const int pinTempo = 10;

/* PlayMode available */
const int forward = 0;
const int backward = 1;
const int randomMode = 2;
const int pendulum = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(pinTempo, OUTPUT);
  for(int i=2; i <= maxStep; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int bpm = readTempo();

  if(isDelay(bpm)){
    digitalWrite(pinTempo, HIGH);
    blinkStepPin(bpm, forward);
  } else {
    /* LA LIGNE CI DSSOUS EST DAN-GE-REUSE, IL NE FAUT PAS LA GARDER. DIEU N'A PAS VOULU SA NAISSANCE */
    /* elle sert tout de meme avoir une led tempo qui clignotte plus longtemps */
    /* peut être réfléchir a une fonction qui renvois la valeur de l'interval entre une minute et le bpm pour avoir un temp de clignotement */
    delay(50);
    digitalWrite(pinTempo, LOW);
  }
}

/* read the current tempo from 112 to 1000 */
int readTempo(){
  return map(analogRead(knobTempo), 0, 1023, maxBpm, minBpm);
}

void blinkStepPin(int bpm, int playMode){
  static int lastMode = playMode;
  static int actualStep = minStep;

  if(playMode == forward || playMode == backward){
    lastMode = playMode;
  }
  
  switch(playMode){
      case forward : 
      if(actualStep < maxStep) actualStep++; else actualStep = minStep;
    break;
      case backward :
      if(actualStep > minStep) actualStep--; else actualStep = maxStep;
    break; 
    case randomMode : 
      actualStep = random(minStep, maxStep);
      break;
    case pendulum :
      if(actualStep - minStep >= 0)  actualStep--; else actualStep = maxStep;
  }
  stepPinOff();
      
  digitalWrite(actualStep, HIGH);
}

void stepPinOff(){
  for(int i=minStep; i<=maxStep;i++){
    digitalWrite(i, LOW);
  }
}

boolean isDelay (int bpm){
   const long minute = 60000;
   int interval = minute / bpm;
   static unsigned long previousMillis = millis();
   unsigned long currentMillis = millis();
   
   if(currentMillis - previousMillis >= interval){
      previousMillis = currentMillis;
      return true;
   } else {
      return false;
   }
}
