# 4x4 Keypad with LCD Display — Arduino

A project that interfaces a 4x4 matrix keypad with a 16x2 LCD display using an Arduino Uno. Each key press is detected and instantly shown on the LCD screen. Built and simulated in [Tinkercad Circuits](https://www.tinkercad.com/).

---

## 📸 Circuit Photo

<!-- Replace the path below with your actual Tinkercad screenshot -->
![Circuit Screenshot](https://github.com/user-attachments/assets/60be61b0-9f48-4273-b967-e528999d03de
)



## ⚙️ How It Works

1. The LCD initialises and displays **"Enter: "** on the first row
2. When a key is pressed on the keypad, the pressed character appears on the **second row**
3. After a short delay, the screen clears and resets — ready for the next key press

---

## 🔧 Components Used

| Component                  | Quantity |
|---------------------------|----------|
| Arduino Uno                | 1        |
| 4×4 Matrix Membrane Keypad | 1        |
| 16×2 LCD Display           | 1        |
| 220Ω Resistor (backlight)  | 1        |
| Breadboard                 | 1        |
| Jumper Wires               | Several  |

---

## 🔌 Pin Connections

### Keypad → Arduino

| Keypad Pin | Function | Arduino Pin |
|------------|----------|-------------|
| R1         | Row 1    | D6          |
| R2         | Row 2    | D7          |
| R3         | Row 3    | D8          |
| R4         | Row 4    | D9          |
| C1         | Column 1 | A0          |
| C2         | Column 2 | A1          |
| C3         | Column 3 | A2          |
| C4         | Column 4 | A3          |

### LCD → Arduino

| LCD Pin  | Function        | Arduino Pin |
|----------|-----------------|-------------|
| RS       | Register Select | D12         |
| EN       | Enable          | D11         |
| D4       | Data            | D5          |
| D5       | Data            | D4          |
| D6       | Data            | D3          |
| D7       | Data            | D2          |
| VSS      | Ground          | GND         |
| VDD      | Power           | 5V          |
| RW       | Read/Write      | GND         |
| A (LED+) | Backlight       | 5V (via 220Ω) |
| K (LED−) | Backlight GND   | GND         |

---

## 💻 Code

```cpp
#include <Keypad.h>
#include <LiquidCrystal.h>

// Initialize the LCD with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the Keypad layout
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9};     // Row pins
byte colPins[COLS] = {A0, A1, A2, A3}; // Column pins

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter: ");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(0, 1);
    lcd.print(key);
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter: ");
  }
}
```

---

## 📦 Libraries Required

Install these via **Arduino IDE → Tools → Manage Libraries**:

| Library        | Author         |
|----------------|----------------|
| `Keypad`       | Mark Stanley   |
| `LiquidCrystal`| Arduino        |

---

## ▶️ How to Run

**In Tinkercad:**
1. Open the [Tinkercad project](https://www.tinkercad.com/) *(replace with your share link)*
2. Click **Start Simulation**
3. Click any key on the keypad and watch it appear on the LCD

**On a real Arduino:**
1. Install the required libraries in the Arduino IDE
2. Open `keypad1.ino`
3. Select **Board:** Arduino Uno and the correct **Port**
4. Click **Upload**

---

## 📁 Project Structure

```
├── keypad1.ino        # Arduino source code
├── assets/
│   └── circuit.png   # Tinkercad circuit screenshot
└── README.md
```
