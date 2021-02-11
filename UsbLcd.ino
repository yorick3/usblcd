/**
 * UsbLcd v1.0
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Setup code, runs once.
  // Begin serial with baud rate 9600.
  Serial.begin(9600);
  // Init LCD display.
  lcdInit();
}

void lcdInit() {
  // Init the LCD and show splash screen.
  lcd.init();
  lcd.backlight();
  splash();
  lcd.noBacklight();
}

void splash() {
  // Show the name and version of this program.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("> UsbLcd");
  lcd.setCursor(0,1);
  lcd.print("> v1.0");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Main code, runs repeatedly.
  if(Serial.available() > 0) {
    processMessage(Serial.readString());
  }
}

void processMessage(String message) {
  // Check if messages are commands and if not displays them.
  message.trim();
  if(message == "DISP_BL_OFF") {
    // Message is backlight-off command.
    setLight(false);
  }
  else if(message == "DISP_BL_ON") {
    // Message is backlight-on command.
    setLight(true); 
  }
  else {
    // Message is not a command, display on screen.
    updateDisplay(message);
  }
}

void updateDisplay(String message) {
  // Updates the display to show a (new) message.
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(message);
  msgOK();
}

void setLight(bool value) {
  // Enables or disables the backlight.
  if(value) {
    lcd.backlight();
  } else {
    lcd.noBacklight();
  }
  // Return a "command ok" message.
  cmdOK();
}

void msgOK() {
  // Returns a "message ok" message.
  Serial.print("MSG_OK");
}

void cmdOK() {
  // Returns a "command ok" message.
  Serial.print("CMD_OK");
}
