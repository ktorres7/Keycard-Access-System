For my project, I created a Keycard Access System using Teachable Machine, Python, and an Arduino Meda 2560. 

I trained an image recognition model to identify three scenarios
1) CORRECT_KEY - Green LED turns on, and the Servo rotates 90 degrees to simulate unlocking a door.
2) WRONG_KEY - Red LED turns on, the buzzer makes a short loud sound, the Servo stays locked.
3) NO_KEY - Neither LED turns on, Buzzer doesn't make a sound, and the Servo returns to the locked position.

The camera captures the image, Python then uses my trained model to identify the keycard, and the results are then sent to the Arduino. Then, based on those results, the Arduino controls the LEDs, Buzzer, and Servo. 

My Keycard Access System project combines image recognition with multiple hardware components.
