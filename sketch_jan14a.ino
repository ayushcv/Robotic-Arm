#include <Servo.h>                                 // Include servo library

Servo servoLeft;                                   // Servo object instances
Servo servoRight;
Servo servoTurret;  

const int servoLeftPin = 13;                       // I/O Pin constants
const int servoRightPin = 12;
const int servoTurretPin = 11;
const int pingPin = 10;
const int piezoPin = 4;

const int msPerTurnDegree = 6;                     // For maneuvers  
const int tooCloseCm = 30;                         // For distance decisions
const int bumpedCm = 6;
int ccwLim = 1400;                                 // For turret servo control
int rtAngle = 900;
const int usTocm = 29;                             // Ping))) conversion constant

// Sequence of turret positions.
int sequence[] = {0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1};

// Declare array to store that many cm distance elements using pre-calculated
// number of elements in array.
const int elements = sizeof(sequence);
int cm[elements];

// Pre-calculate degrees per adjustment of turret servo.
const int degreesTurret = 180/(sizeof(sequence)/sizeof(int)-1);

int i = -1;                                        // Global index
int sign = 1;                                      // Sign of increments
int theta = -degreesTurret;                        // Set up initial turret angle

void setup()                                       // Built-in initialization block
{
  tone(piezoPin, 3000, 1000);                      // Play tone for 1 second
  delay(1000);                                     // Delay to finish tone
 
  Serial.begin(9600);                              // Open serial connection

  servoLeft.attach(servoLeftPin);                  // Attach left signal to pin 13
  servoRight.attach(servoRightPin);                // Attach right signal to pin 12
  servoTurret.attach(servoTurretPin);              // Attach turret signal to pin 12
  maneuver(0, 0, 1000);                            // Stay still for 1 second
  turret(0);                                       // Set turret to 0 degrees
}  
 
void loop() {
  // put your main code here, to run repeatedly:

}
