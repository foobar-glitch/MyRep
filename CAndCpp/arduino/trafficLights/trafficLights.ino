const int buttonPin = 2;
//const int ledPins[3] = {4, 7, 8};  //red, yellow, green
const int redPin = 4;
const int yellowPin = 7;
const int greenPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // button := crosstraffic
  int state = 0, nexts
  tate;
  int red, yellow, green;
  digitalWrite(13, HIGH);
  int traffic;
  while(1){
      delay(1000);
      traffic=digitalRead(buttonPin);
      switch(state){
        case 0:
         if(traffic == LOW){
           nextstate = 1;
         }else{
           nextstate = 0;
         }
         break;
        
        case 1:
          nextstate = 2;
          break;
         
        case 2:
         // while traffic low stay at green
         if(traffic == HIGH){
          nextstate = 3;
         } 
         else{
          nextstate = 2;
         }
         break;
    
        case 3:
          nextstate = 0;
          break;
      }
    
      switch(state){
        case 0: 
          red = HIGH; yellow = LOW; green = LOW;break;
        case 1:
          red = LOW; yellow = HIGH; green = LOW;break;
        case 2:
          red = LOW; yellow = LOW; green = HIGH; break;
        case 3:
          red = HIGH; yellow = HIGH; green = LOW; break;
      }
    
      digitalWrite(redPin, red);
      digitalWrite(yellowPin, yellow);
      digitalWrite(greenPin, green);
      
      
      state = nextstate;
    }
}
