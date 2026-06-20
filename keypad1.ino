#include <Keypad.h>
#include <LiquidCrystal.h>

// Initialize the LCD with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the Keypad layout
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9};    // Connect to the row pins of the keypad
byte colPins[COLS] = {A0, A1, A2, A3}; // Connect to the column pins of the keypad

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  lcd.print("Enter: ");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Print the key value on the LCD
    lcd.setCursor(0, 1);
    lcd.print(key);
    delay(500); // Delay for readability
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter: ");
  }
}