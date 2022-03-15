#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 7
#define LED5 8
#define LED6 9
#define LED7 10
#define LED8 11

int val; 
int x;
int y;
int cal;
int level;
unsigned long TIME;
unsigned long TIMEa;
int MAX;
int index;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
  pinMode(6, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  
  
 delay(10);
  CAL();
  TIMEa = millis();
}


void loop() {

  int trig = analogRead(A5)/5; //Receive sensitivity

  Serial.print(cal + trig/10);
  Serial.print(" ");
  Serial.print(cal+trig*2);
  Serial.print(" ");
   Serial.println(analogRead(A0));



  MAX = map(analogRead(A0),cal + trig/10,cal + trig*2,-1,8);
  index = constrain(MAX, 0, 8); 
  if(index > 2)analogWrite(6, 31*index); //led strip output
  else analogWrite(6, 0);
  
  if(millis()- TIME > 60000)CAL();
  //if(millis()- TIMEa > 5)LED(trig);
  LED(trig);
}


void CAL(){
   val = 0;
 for(int i = 0; i<20; i++){ //reset
  val = val + analogRead(A0);
 }
  cal = val/20; 
  
  TIME = millis();
}

void LED(int trig)
{
  
  switch(index) //led on
  {
    case 8:
      digitalWrite(LED8,HIGH);
      
    case 7:
      digitalWrite(LED7,HIGH);
      
    case 6:
      digitalWrite(LED6,HIGH);
     
    case 5:
      digitalWrite(LED5,HIGH);
      //break;
    case 4:
      digitalWrite(LED4,HIGH);
      //break;
    case 3:
      digitalWrite(LED3,HIGH);
      //break;
    case 2:
      digitalWrite(LED2,HIGH);
      //break;
    case 1:
      digitalWrite(LED1,HIGH);
  }

  switch(index) //off led
  {
    case 0:
      digitalWrite(LED1,LOW);
    case 1:
      digitalWrite(LED2,LOW);      
    case 2:
      digitalWrite(LED3,LOW);
    case 3:
      digitalWrite(LED4,LOW);;
      //break;
    case 4:
      digitalWrite(LED5,LOW);
      //break;
    case 5:
      digitalWrite(LED6,LOW);
      //break;
    case 6:
      digitalWrite(LED7,LOW);
      //break;
    case 7:
      digitalWrite(LED8,LOW);
  }
  
  TIMEa = millis();
  //delay(20);
}
