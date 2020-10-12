void gestionStep() {

  if (forward) {
    if  (step < maxStep - 2) {
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
  digitalWrite(step+2, HIGH);
}
void clearLed(){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
}
