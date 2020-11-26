#define BLUE 3
#define GREEN 5
#define RED 6

#define DELAY_TIME 10

void iterateColors(int color1, int color2){
  int colorValue1 = 255, colorValue2 = 0;

  for(int i = 0; i < 256; i++){
    analogWrite(color1, colorValue1);
    analogWrite(color2, colorValue2);
    delay(DELAY_TIME);
    colorValue1--;
    colorValue2++;
    
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  iterateColors(RED, GREEN);
  iterateColors(GREEN, BLUE);
  iterateColors(BLUE, RED);

  
}
