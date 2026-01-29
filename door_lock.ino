#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {13,10,A0,A1};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password
String password = "1234";
String input = "";

void setup() {
  lcd.begin(16,2);
  lcd.print("Enter Password");
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // Enter key
      lcd.clear();
      if (input == password) {
        lcd.print("Access Granted");
        Serial.println("Door Unlocked");
      } else {
        lcd.print("Access Denied");
        Serial.println("Wrong Password");
      }
      input = "";
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
    } 
    else {
      input += key;
      lcd.setCursor(0,1);
      lcd.print(input);
    }
  }
}
