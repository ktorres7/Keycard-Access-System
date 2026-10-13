#include <Servo.h>

Servo lockServo;

// Hardware pins
const int GREEN_LED = 6;
const int RED_LED = 7;
const int BUZZER = 8;
const int SERVO_PIN = 9;

// Servo positions
const int LOCKED_POSITION = 0;
const int UNLOCKED_POSITION = 90;

void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lockServo.attach(SERVO_PIN);

  // Start in locked state
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);
  lockServo.write(LOCKED_POSITION);
}

void loop() {

  if (Serial.available()) {

    String message = Serial.readStringUntil('\n');
    message.trim();

    // Correct key = authorize access
    if (message == "CORRECT_KEY") {

      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(BUZZER, LOW);

      lockServo.write(UNLOCKED_POSITION);
    }

    // Wrong key = deny access
    else if (message == "WRONG_KEY") {

      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);

      lockServo.write(LOCKED_POSITION);

      // Short warning beep
      digitalWrite(BUZZER, HIGH);
      delay(400);
      digitalWrite(BUZZER, LOW);
    }

    // No key = reset to locked state: no lights on, no buzzer, lock servo
    else if (message == "NO_KEY") {

      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, LOW);
      digitalWrite(BUZZER, LOW);

      lockServo.write(LOCKED_POSITION);
    }
  }
}