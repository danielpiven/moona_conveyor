#include <Servo.h>                      // include library related to servo motors
#define door_control 8                  // Naming the control of the door
#define Servo_control 3                 // Naming the pin of Arduino that will produce PWM signal
Servo MG995_Servo;                      // Define the Servo named "MG995_Servo"

void setup() {
  Serial.begin(9600);                   // Initialize serial port with 9600 baud rate
  MG995_Servo.attach(Servo_control);    // Connect PWM signal pin of servo motor with Digital 3 of Arduino

}

void door_open(){  
  int pos;
  for (pos = 0; pos <= 90; pos += 5){  //90 is the center. He need to go to the center if you want to change 
                                       //the direction after. From 0 to 90, he turns clockwise.
       Serial.println(pos);            //You can display on the serial the signal value
       MG995_Servo.write(pos);
       delay(100);
       MG995_Servo.detach();           //Stop. Detach "cuts" the signal of the PWM entering the servo. 
       delay(300);                     //Give the motor some pause before next position. The delay here is 
                                       //equivalent to how much time the motor will wait to start moving again.
       MG995_Servo.attach(Servo_control);  //Always use attach function after detach to re-connect the servo with the board
  }
}

void door_close(){
  int pos;
  for (pos = 90; pos <= 180; pos += 5){ //90 is the center. He need to go to the center if you want to change 
                                        //the direction after. From 0 to 90, he turns clockwise.
       Serial.println(pos);             // You can display on the serial the signal value
       MG995_Servo.write(pos);
       delay(100);     
       MG995_Servo.detach();            //Stop. Detach "cuts" the signal of the PWM entering the servo. 
       delay(300);                      //Give the motor some pause before next position. The delay here is 
                                        //equivalent to how much time the motor will wait to start moving again.
       MG995_Servo.attach(Servo_control);   //Always use attach function after detach to re-connect your servo with the board
  }  
  MG995_Servo.detach();
  delay(1000);
}


void loop() {
  pinMode(door_control, INPUT);
  if (digitalRead(door_control) == HIGH) {
     door_open();
     MG995_Servo.detach();           
     delay(1000);                                              
     MG995_Servo.attach(Servo_control); 
     door_close();

  }
  }
