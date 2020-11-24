// Arduino stepper motor control code

#include <Stepper.h> // Include the header file
#include <Servo.h>

// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 6, 8, 7, 9);
Stepper stepper2(STEPS, 2, 4, 3, 5);
Stepper stepper3(STEPS, 10, 12, 11, 13);

Servo servo;





int val = 0;
int va = 0;

int s =500;


// Arduino pin numbers
const int SW_pin = 0; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

//upper body control joystick 
const int X2_pin = A3; // analog pin connected to X output
const int Y2_pin = A2; // analog pin connected to Y output


int y = 0; 
int u = 0; 
int uv= 0;
int x = 0;
int SW = 0;
int t = 0;
int tr = 0;
int x2= 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  //Serial.begin(9600);

  stepper.setSpeed(s);
  stepper2.setSpeed(s);
  stepper3.setSpeed(s);

  servo.attach(1);



}

void loop() {

  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  //
  Serial.print("\n");
  Serial.print("X2-axis: ");
  Serial.print(analogRead(X2_pin));
  Serial.print("\n");
  Serial.print("Y2-axis: ");
  Serial.println(analogRead(Y2_pin));
  Serial.print("\n\n");
  delay(0);


//Code for Motor1
  y= analogRead(Y_pin);
  
  if (y >= 510 && y<=530)
  {
    stepper.step(0);
  }
  else if (y >518)
  {
    val++;
    stepper.step(val); 
    Serial.print('1');
  }
  else 
  {
    va--;
    stepper.step(va); 
    Serial.print('1');
  }

  // Motor 2 
  x= analogRead(X_pin);
  
  if ( x>= 500 && x<=520 )
  {
    stepper2.step(0);
  }
  else if ( x>510)
  {
    u++;
    stepper2.step(u); 
    Serial.print('1');
  }
  else 
  {
    uv--;
    stepper2.step(uv);
    Serial.print('1');
  }


//Motor 3 

  x2= analogRead(X2_pin);
  
  if ( x2 >= 500 && x2 <= 543)
  {
    stepper3.step(0);
  }
  else if ( x2>526)
  {
    t++;
    stepper3.step(t); 
    Serial.print('1');
  }
  else 
  {
    tr--;
    stepper3.step(tr);
    Serial.print('1');
  }


//Motor 4 525

void stepper4(int xw){
  for (int x=0;x<xw;x++){
switch(Steps1){
   case 0:
     stepper1val=8;    
   break; 
   case 1:
     stepper1val=12;
   break; 
   case 2:
     stepper1val=4;
   break; 
   case 3:
     stepper1val=6;
   break; 
   case 4:
     stepper1val=2;
   break; 
   case 5:
     stepper1val=3;
   break; 
     case 6:
     stepper1val=1;
   break; 
   case 7:
     stepper1val=9;
   break; 
   default:
     stepper1val=0;
   break; 
}



//This is for claw 
SW = digitalRead(SW_pin);
  if (SW ==1)
  {
    servo.write(0);
    delay(5);
  }
  else
  {
    servo.write(90);
    delay(5);
  }





//  if (Serial.available()>0)
//  {
//    u = Serial.parseInt();
//    stepper.step(u);
//    Serial.println(u); //for debugging
//  }
// 
  
}
