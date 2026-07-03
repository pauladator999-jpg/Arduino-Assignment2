int digits[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

  int segmentPins[] = {3, 2, 6, 7, 9, 4, 5};
  int buzzerPin = 8;
  int numSegments = 7;
   // a function to show a digit on the display
void showDigit(int n){
  if(n < 0 || n > 9)  //For Safety: don't do anything if the input is outside 0-9
  return;
  for (int i = 0; i<numSegments; i++){
    digitalWrite(segmentPins[i],digits[n][i]);
  }
}

void setup() { 
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);  //setting up the buzzer
 
  
  for(int i=0; i<numSegments; i++){
    pinMode(i, OUTPUT);       //setting up each segment
  }
  
   Serial.println("====Beeping Countdown Starting===");
   int count = 9;
   while (count >=1){
    Serial.print("counting: ");
    Serial.println(count);

    showDigit(count);
    tone(buzzerPin, 100, 200);
    delay(1000);

    count = count - 1;;

   }  
   showDigit(0);
   tone(buzzerPin, 1500, 1000);

   Serial.println("===Countdown Complete==");

   }

void loop() {
  Serial.println("BEEP!");
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);

  delay(1500);
}
