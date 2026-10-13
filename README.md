PROJECT OVERVIEW

For my project, I created a Keycard Access System using Teachable Machine, Python, and an Arduino Meda 2560. 

I trained an image recognition model to identify three scenarios
1) CORRECT_KEY - Green LED turns on, and the Servo rotates 90 degrees to simulate unlocking a door.
2) WRONG_KEY - Red LED turns on, the buzzer makes a short loud sound, the Servo stays locked.
3) NO_KEY - Neither LED turns on, Buzzer doesn't make a sound, and the Servo returns to the locked position.

The camera captures the image, Python then uses my trained model to identify the keycard, and the results are then sent to the Arduino. Then, based on those results, the Arduino controls the LEDs, Buzzer, and Servo. 

My Keycard Access System project combines image recognition with multiple hardware components.


CHALLENEGES AND TROUBLESHOOTING

While working on my Keycard Access System, I ran into several challenges,
1) Python and Package Installation
   I had to make sure the correct Python packages were installed to run my trained model and have it communicate with the   Arduino.
   
2) Webcam Not Working
   When I first tested my Python program, my computer's webcam wouldn't open, and I continued to get an error. I was unable to get it to work, so I did some research and realized that it was due to my Teachable Machine still running in my browser - so the webcam was already in use. I fixed this by closing my Teachable Machine page, making sure the webcam wasn't in-use anywhere else and then re-ran my program. It worked!
   
3) Arduino Code Error
   While testing my green LED, I had two Arduino .ino files in the same sketch folder. Both contained the same functions, which caused an error. I fixed this by creating a separate Arduino sketch just for testing.
   
4) Identifying the Active Buzzer
   My kit included two almost identical Buzzers, and I wasn't sure which one was the active one. I tested one using the Arduino and confirmed it was the active Buzzer - which means it continuously beeped. 
   
5) Testing the Servo Without an Arm
   My Servo didn't have a plastic arm attachment, nor was there one in my kit, which made it difficult to see whether it was actually moving. I used a small piece of tape, attached it to the top of where the arm would go. This allowed me to confirm that the Servo did rotate.

TIPS AND LESSONS LEARNED
- Make sure webcam isn't trying to be used by multiple programs.
- Close windows that are not in-use. 
- Test each hardware component separately before combining everything.
- Save and test the code after each major change to make troubleshooting easier.
- Make sure all needed parts are in hardware kit.
