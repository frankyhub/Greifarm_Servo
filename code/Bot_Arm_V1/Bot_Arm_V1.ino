/* Roboterarm Servo Ansteuerung
 *  Board NANO
 *  ATmega328P
 *  LIB: VarSpeedServo.h
 *  https://github.com/netlabtoolkit/varspeedservo
 *  
 *  V1
 *  18-10-2020 KHF
 */


#include <VarSpeedServo.h> 


VarSpeedServo Gr_servo; //Greifarm
VarSpeedServo Dr_servo; //Drehteller
VarSpeedServo Ki_servo; //Kippen
VarSpeedServo He_servo; //Heben

int Poti_Greifen = A1;    //Greifarm
int Poti_Drehen = A2;     //Drehteller
int Joystick_Kippen = A3; //Kipp
int Joystick_Heben = A4;  //Heben

int Greifarm;
int Drehteller;
int Kippen;
int Heben;

//Speed festlegen:
int SPEED = 30; //30 bei Test


void setup() {
  Gr_servo.attach(6);   //PWM#6
  Dr_servo.attach(9);   //PWM#9
  Ki_servo.attach(10);  //PWM#10
  He_servo.attach(11);  //PWM#11
} 
 
void loop() {

int Poti_Greifen = analogRead(A1);
int Poti_Drehen = analogRead(A2);
int Joystick_Kippen = analogRead(A3);
int Joystick_Heben = analogRead(A4);

  //Greifarm
  Greifarm = map(Poti_Greifen, 0, 1023, 0, 175);
  Gr_servo.write(Greifarm, SPEED);

//Drehteller
Drehteller = map(Poti_Drehen, 0, 1023, 0, 175);
Dr_servo.write(Drehteller, SPEED);

  //Kippen
  Kippen = map(Joystick_Kippen, 0, 1023, 0, 175);
  Ki_servo.write(Kippen, SPEED);

//Heben
Heben = map(Joystick_Heben, 0, 1023, 0, 150);
He_servo.write(Heben, SPEED);

    delay(100);
}
