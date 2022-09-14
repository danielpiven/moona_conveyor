/* This example Arduino Sketch controls the complete rotation of
 *  SG995 Servo motor by using its PWM and Pulse width modulation technique
 */

#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM 3 // A descriptive name for D3 pin of Arduino to provide PWM signal
Servo MG995_Servo;                      // Define an instance of of Servo with the name of "MG995_Servo"


void setup() {
  Serial.begin(9600);                   // Initialize UART with 9600 Baud rate
  MG995_Servo.attach(Servo_PWM);        // Connect D3 of Arduino with PWM signal pin of servo motor
}

void loop() {
  int pos;
  for (pos = 0; pos <= 90; pos += 1){  //90 is the center. He need to go to the center if you want to change 
                                       //the direction after. From 0 to 90, he turns clockwise.
       Serial.println(pos);            //You can display on the serial the signal value
       MG995_Servo.write(pos);
       delay(100);
       MG995_Servo.detach();           //Stop. Detach "cuts" the signal of the PWM entering the servo. 
       delay(300);                     //Give the motor some pause before next position. The delay here is 
                                       //equivalent to how much time the motor will wait to start moving again.
       MG995_Servo.attach(Servo_PWM);  //Always use attach function after detach to re-connect the servo with the board
  }
  for (pos = 90; pos <= 180; pos += 1){ //90 is the center. He need to go to the center if you want to change 
                                        //the direction after. From 0 to 90, he turns clockwise.
       Serial.println(pos);             // You can display on the serial the signal value
       MG995_Servo.write(pos);
       delay(100);     
       MG995_Servo.detach();            //Stop. Detach "cuts" the signal of the PWM entering the servo. 
       delay(300);                      //Give the motor some pause before next position. The delay here is 
                                        //equivalent to how much time the motor will wait to start moving again.
       MG995_Servo.attach(Servo_PWM);   //Always use attach function after detach to re-connect your servo with the board
  }
}
