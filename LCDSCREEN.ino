#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("                "); // clear the display
}

void loop() {
  String text = " HI THERE! :) THIRSTY? I'M HERE TO HELP ";
  int textLength = text.length();
  int displayLength = 16;

  // slide text from right to left
  for (int i = 0; i < textLength; i++) {
    lcd.setCursor(0, 0);
    lcd.print(text.substring(i, textLength));
    delay(300); // increased delay to 300ms
    lcd.setCursor(0, 0);
    lcd.print("                "); // clear the display
  }

  // slide text from left to right
  for (int i = textLength - 1; i >= 0; i--) {
    lcd.setCursor(0, 0);
    lcd.print(text.substring(i, textLength));
    delay(300); // increased delay to 300ms
    lcd.setCursor(0, 0);
    lcd.print("                "); // clear the display
  }

  delay(2000); // increased delay to 2 seconds before repeating the animation
}