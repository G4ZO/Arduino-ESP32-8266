
int MAX = 0;
unsigned long TIME;
unsigned long displayTIME;
void setup() {
  pinMode(A6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //Serial.begin(250000);
  analogRead(A6);
  for(int i = 2; i < 9 ; i++){
    digitalWrite(i, HIGH);
    delay(70);
 } 
   for(int i = 8; i > 1; i--){
    delay(70);
    digitalWrite(i,LOW);
 }
  TIME = millis();
  displayTIME = millis();
  delay(200);
  
}

void loop() {
 int inVAL = analogRead(A6);
 int outVAL = map(inVAL,0,100,0,7);
 //Serial.println(outVAL);
 outVAL = min(outVAL, 7);

 //turn on led
 for(int i = 2; i < outVAL + 2; i++){
    digitalWrite(i, HIGH);
    if(i > MAX)TIME = millis();
    MAX = max(MAX,i);
 }


//turn off led
 if(millis() - displayTIME > 50){
   for(int i = 2; i < 9; i++){
    if(i != MAX)digitalWrite(i,LOW);
  }
  displayTIME = millis();
 }
 

 if(millis() - TIME > 1400){
  TIME = millis();
  MAX = 0;
 }

}
