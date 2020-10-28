/* tempo led and knob */
const int knobTempo = A0;
const int pinTempo = 8;

const int stepLeds = 8;

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
  return map(analogRead(knobTempo), 0, 1023, 60, 300);
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

void blinkStepLed(int playMode){
  static int actualStep = 0;
  const int forward = 0;
  const int backward = 1;
  const int random = 2;
  
  switch(playMode){
  	case forward : 
    if(actualStep < stepLeds) actualStep++; else actualStep = 0;
    break;
    case backward :
    if(actualStep > stepLeds) actualStep--; else actualStep = stepLeds;
    break; 
    case random : 
	//TODO
    break;
  }  
  stepLedsOff();
}

void stepLedsOff(){
 int i = 0;
 while(i++ < stepLeds){
 	digitalWrite(i, LOW);
 }
}
