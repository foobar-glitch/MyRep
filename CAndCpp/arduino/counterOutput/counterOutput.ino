// http://www.datasheetcafe.com/5611ah-datasheet-digit-display/
enum {DP, C, D, E, B, A, F, G};
// OUTPUT 2:DP, 4:C, 6:D, 7:E, 9:B, 10:A, 11:F, 12:G
// For example : Pin 2 goes to DP
int pins[] = {2, 4, 6, 7, 9, 10, 11, 12};


void turnOnPinNumber(int number){
  digitalWrite(pins[number], HIGH);
}

void turnOffPinNumber(int number){
  digitalWrite(pins[number], LOW);
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<8; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void displayNumber(int letters[9], int finish, int turnon){
 for(int i = 0; i < 9; i++){
    if(letters[i]== finish){
      break; 
    }
    if(turnon){
      turnOnPinNumber(letters[i]);
    }else{
      turnOffPinNumber(letters[i]);
    }
 }
}


void loop() {
  // put your main code here, to run repeatedly
  // 0 1 2 3 4 5 6 7 8 9
  int finish = G+1;
  int numbers[10][9] = {
                     {A, B, C, D, E, F, finish},  
                     {B, C, finish},           
                     {A, B, G, E, D, finish},     
                     {A, B, G, C, D, finish},
                     {F, G, B, C, finish},
                     {A, F, G, C, D, finish},
                     {A, F, G, E, D, C, DP, finish},
                     {F, A, B, C, finish},
                     {A, B, C, D, E ,F, G, finish},
                     {F, A, B, G, C, D, DP, finish}
                     };


  //turnOnPinNumber(G);
  //displayNumber(numbers[0], finish, 1);
  //turnOnPinNumber(A);turnOnPinNumber(B);turnOnPinNumber(C);turnOnPinNumber(D);turnOnPinNumber(E);turnOnPinNumber(F);
  
  for(int i = 0; i < 10; i++){
        // turn on
        displayNumber(numbers[i], finish, 1);
        delay(1000);
        // turn off
        displayNumber(numbers[i], finish, 0);
        delay(1000);
    }
  
  //digitalWrite(FIRSTBIT_PIN, HIGH);
  //delay(1000);
}
