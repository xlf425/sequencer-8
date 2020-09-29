void gestionStep() {

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
  
}
