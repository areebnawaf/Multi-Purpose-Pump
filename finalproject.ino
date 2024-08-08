#include <IRLib.h>
#include <Adafruit_CircuitPlayground.h>

const int pumpPin1 = A2;
const int pumpPin2 = A4;

IRrecv My_Receiver(A1); // Create an instance of the IR receiver
decode_results My_Result; // Create an instance of the decode results

void setup() {
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the IR receiver
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  digitalWrite(pumpPin1, LOW);
  digitalWrite(pumpPin2, LOW);
}

void loop() {
  if (My_Receiver.decode(&My_Result)) {
    Serial.println(My_Result.value, HEX);
    if (My_Result.value == 0xFF38C7) { // Replace with the actual IR code for "2" on your remote
      digitalWrite(pumpPin1, HIGH);
      digitalWrite(pumpPin2, HIGH);
    } else if (My_Result.value == 0xFF5AA5) { // Replace with the actual IR code for "5" on your remote
      digitalWrite(pumpPin1, LOW);
      digitalWrite(pumpPin2, LOW);
    }
    My_Receiver.resume(); // Prepare for the next IR code
  }
  delay(100);
}