#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, A1);

const int led_green = 13;
const int led_red = 12;
const int startButton = 2; 
const int clickButton = 3; 

unsigned long waitTime = 0;
unsigned long startTime = 0;
unsigned long reactionTime = 0;

// Define states
enum State {IDLE, WAITING, GREEN_ON, DONE};
State currentState = IDLE;

void setup() {
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(clickButton, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Reaction Timer");
  lcd.setCursor(0,1);
  lcd.print("Press Start");
  
  randomSeed(analogRead(A0));
}

void loop() {  
  switch(currentState) {
    case IDLE:
      // Wait for start button to begin
      if (digitalRead(startButton) == LOW) {
        lcd.setCursor(0,1);
        lcd.print("Get Ready...   ");
        digitalWrite(led_red, HIGH);
        waitTime = random(1000, 5000); // 1-5 sec
        startTime = millis();
        currentState = WAITING;
        delay(50); // debounce
      }
      break;

    case WAITING:
      if(digitalRead(led_red) == HIGH && digitalRead(clickButton) == LOW){
        digitalWrite(led_red, LOW);
        lcd.setCursor(0,1);
        lcd.print("Too Early!     ");
        currentState = DONE;
        delay(200);
      }
      if (millis() - startTime >= waitTime) {
        digitalWrite(led_red, LOW);
        digitalWrite(led_green, HIGH); // stays on until click
        lcd.setCursor(0,1);
        lcd.print("Click!         ");
        startTime = millis(); // start measuring reaction
        currentState = GREEN_ON;
      }
      break;

    case GREEN_ON:
      // Wait until user presses click button
      if (digitalRead(clickButton) == LOW) {
        reactionTime = millis() - startTime;
        lcd.setCursor(0,1);
        lcd.print("Time: ");
        lcd.print(reactionTime);
        lcd.print(" ms   ");
        digitalWrite(led_green, LOW);
        currentState = DONE;
        delay(200); // debounce
      }
      break;

    case DONE:
      // Wait for user to press start to reset
      if (digitalRead(startButton) == LOW) {
        lcd.setCursor(0,1);
        lcd.print("Press Start    ");
        digitalWrite(led_red, LOW);
        digitalWrite(led_green, LOW);
        currentState = IDLE;
        delay(200); // debounce
      }
      break;
  }
}
