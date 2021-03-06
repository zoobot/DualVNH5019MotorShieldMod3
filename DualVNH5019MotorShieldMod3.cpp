#include "DualVNH5019MotorShieldMod3.h"

// Constructors ////////////////////////////////////////////////////////////////
//all default pins function (note: motor sheild 2 is "custom")
DualVNH5019MotorShieldMod3::DualVNH5019MotorShieldMod3()
{
  //default Pin map motor sheild 1
  _INA1 = 2;
  _INB1 = 4;
  _EN1DIAG1 = 6;
  _CS1 = A0; //analog 0 pin
  _INA2 = 7;
  _INB2 = 8;
  _EN2DIAG2 = 12;
  _CS2 = A1; //analog 1 pin
 //default Pin map motor sheild 2
  _INA3 = 24;
  _INB3 = 26;
  _EN3DIAG3 = 22;
  _CS3 = A8; // analog 8 pin
  _INA4 = 25;
  _INB4 = 27;
  _EN4DIAG4 = 23;
  _CS4 = 9; //analog 9 pin

  //default pwm motor sheild 1
  _PWM1 = 9;
  _PWM2 = 10;
  //default pwm motor sheild 2
  _PWM3 = 45;
  _PWM4 = 46;  
}
//default pins for motor shield 1, custom pins for motor shield 2
DualVNH5019MotorShieldMod3::DualVNH5019MotorShieldMod3(unsigned char INA3, unsigned char INB3, unsigned char EN3DIAG3, unsigned char CS3, unsigned char PWM3, unsigned char INA4, unsigned char INB4, unsigned char EN4DIAG4, unsigned char CS4, unsigned char PWM4)
{
  //default Pin map motor sheild 1
  _INA1 = 2;
  _INB1 = 4;
  _EN1DIAG1 = 6;
  _CS1 = A0; //analog 0 pin
  _INA2 = 7;
  _INB2 = 8;
  _EN2DIAG2 = 12;
  _CS2 = A1; //analog 1 pin
 //Custom Pin map motor sheild 2
  _INA3 = INA3;
  _INB3 = INB3;
  _EN3DIAG3 = EN3DIAG3;
  _CS3 = CS3; 
  _INA4 = INA4;
  _INB4 = INB4;
  _EN4DIAG4 = EN4DIAG4;
  _CS4 = CS4;

  //default pwm motor sheild 1
  _PWM1 = 9;
  _PWM2 = 10;
  //default pwm motor sheild 2 
  _PWM3 = PWM3;
  _PWM4 = PWM4;  
}

//custom pins setup (note: assumes PWM pins are not remapped)
DualVNH5019MotorShieldMod3::DualVNH5019MotorShieldMod3(unsigned char INA1, unsigned char INB1, unsigned char EN1DIAG1, unsigned char CS1, unsigned char INA2, unsigned char INB2, unsigned char EN2DIAG2, unsigned char CS2, unsigned char INA3, unsigned char INB3, unsigned char EN3DIAG3, unsigned char CS3, unsigned char INA4, unsigned char INB4, unsigned char EN4DIAG4, unsigned char CS4)
{
  //Pin map
  //PWM1 and PWM2 cannot be remapped because the library assumes PWM is on timer1
  //PWM3 and PWM4 cannot be remapped because the library assumes PWM is on timer for pins 45,46
  //motor sheild 1
  _INA1 = INA1;
  _INB1 = INB1;
  _EN1DIAG1 = EN1DIAG1;
  _CS1 = CS1;
  _INA2 = INA2;
  _INB2 = INB2;
  _EN2DIAG2 = EN2DIAG2;
  _CS2 = CS2;
  //motor sheild 2
  _INA3 = INA3;
  _INB3 = INB3;
  _EN3DIAG3 = EN3DIAG3;
  _CS3 = CS3; 
  _INA4 = INA4;
  _INB4 = INB4;
  _EN4DIAG4 = EN4DIAG4;
  _CS4 = CS4;

  //motor sheild 1
  _PWM1 = 9;
  _PWM2 = 10;
  //motor sheild 2
  _PWM3 = 45;
  _PWM4 = 46;    
}
//all custom pin settings
DualVNH5019MotorShieldMod3::DualVNH5019MotorShieldMod3(unsigned char INA1, unsigned char INB1, unsigned char EN1DIAG1, unsigned char CS1, unsigned char INA2, unsigned char INB2, unsigned char EN2DIAG2, unsigned char CS2, unsigned char INA3, unsigned char INB3, unsigned char EN3DIAG3, unsigned char CS3, unsigned char INA4, unsigned char INB4, unsigned char EN4DIAG4, unsigned char CS4, unsigned char PWM1, unsigned char PWM2, unsigned char PWM3, unsigned char PWM4)
{
  //Custom Pin map Motor sheild 1
  _INA1 = INA1;
  _INB1 = INB1;
  _EN1DIAG1 = EN1DIAG1;
  _CS1 = CS1;
  _INA2 = INA2;
  _INB2 = INB2;
  _EN2DIAG2 = EN2DIAG2;
  _CS2 = CS2;
  //Custom Pin map Motor sheild 2
  _INA3 = INA3;
  _INB3 = INB3;
  _EN3DIAG3 = EN3DIAG3;
  _CS3 = CS3; 
  _INA4 = INA4;
  _INB4 = INB4;
  _EN4DIAG4 = EN4DIAG4;
  _CS4 = CS4;
 
 //Custom Pin map PWM Motor sheild 1
  _PWM1 = PWM1;
  _PWM2 = PWM2;
 //Custom Pin map Motor sheild 2
  _PWM3 = PWM3;
  _PWM4 = PWM4;  
}
// Public Methods //////////////////////////////////////////////////////////////
void DualVNH5019MotorShieldMod3::init()
{
// Define pinMode for the pins motor shield 1 and set the frequency for timer1.
//  TCCR1A |= COM1A1; _PWM1 = &OCR1A; // PWM frequency calculation // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
//  TCCR1A |= COM1B1; _PWM2 = &OCR1B; // PWM frequency calculation // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz

  pinMode(_INA1,OUTPUT);
  pinMode(_INB1,OUTPUT);
  pinMode(_PWM1,OUTPUT);
  pinMode(_EN1DIAG1,INPUT);
  pinMode(_CS1,INPUT);
  pinMode(_INA2,OUTPUT);
  pinMode(_INB2,OUTPUT);
  pinMode(_PWM2,OUTPUT);
  pinMode(_EN2DIAG2,INPUT);
  pinMode(_CS2,INPUT);
  // Define pinMode for the pins motor shield2 and set the frequency for timer 5.
//  TCCR5A |= COM5B1; _PWM3 = &OCR5B; // PWM frequency calculation // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
//  TCCR5A |= COM5A1; _PWM4 = &OCR5A; // PWM frequency calculation // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz

  pinMode(_INA3,OUTPUT);
  pinMode(_INB3,OUTPUT);
  pinMode(_PWM3,OUTPUT);
  pinMode(_EN3DIAG3,INPUT);
  pinMode(_CS3,INPUT);
  pinMode(_INA4,OUTPUT);
  pinMode(_INB4,OUTPUT);
  pinMode(_PWM4,OUTPUT);
  pinMode(_EN4DIAG4,INPUT);
  pinMode(_CS4,INPUT);
}
// Set speed for motor 1, speed is a number betwenn -400 and 400
void DualVNH5019MotorShieldMod3::setM1Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  analogWrite(_PWM1,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  if (speed == 0)
  {
    digitalWrite(_INA1,LOW);   // Make the motor coast no
    digitalWrite(_INB1,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA1,LOW);
    digitalWrite(_INB1,HIGH);
  }
  else
  {
    digitalWrite(_INA1,HIGH);
    digitalWrite(_INB1,LOW);
  }
}

// Set speed for motor 2, speed is a number betwenn -400 and 400
void DualVNH5019MotorShieldMod3::setM2Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // make speed a positive quantity
    reverse = 1;  // preserve the direction
  }
  if (speed > 400)  // Max 
    speed = 400;
  analogWrite(_PWM2,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  if (speed == 0)
  {
    digitalWrite(_INA2,LOW);   // Make the motor coast no
    digitalWrite(_INB2,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA2,LOW);
    digitalWrite(_INB2,HIGH);
  }
  else
  {
    digitalWrite(_INA2,HIGH);
    digitalWrite(_INB2,LOW);
  }
}

// Set speed for motor 3, speed is a number betwenn -400 and 400
void DualVNH5019MotorShieldMod3::setM3Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  analogWrite(_PWM3,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  if (speed == 0)
  {
    digitalWrite(_INA3,LOW);   // Make the motor coast no
    digitalWrite(_INB3,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA3,LOW);
    digitalWrite(_INB3,HIGH);
  }
  else
  {
    digitalWrite(_INA3,HIGH);
    digitalWrite(_INB3,LOW);
  }
}

// Set speed for motor 4, speed is a number betwenn -400 and 400
void DualVNH5019MotorShieldMod3::setM4Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // make speed a positive quantity
    reverse = 1;  // preserve the direction
  }
  if (speed > 400)  // Max 
    speed = 400;
  analogWrite(_PWM4,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  if (speed == 0)
  {
    digitalWrite(_INA4,LOW);   // Make the motor coast no
    digitalWrite(_INB4,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA4,LOW);
    digitalWrite(_INB4,HIGH);
  }
  else
  {
    digitalWrite(_INA4,HIGH);
    digitalWrite(_INB4,LOW);
  }
}

// Set speed for motor 1, 2, 3, and 4
void DualVNH5019MotorShieldMod3::setSpeeds(int m1Speed, int m2Speed,int m3Speed, int m4Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
  setM3Speed(m3Speed);
  setM4Speed(m4Speed);
}

// Brake motor 1, brake is a number between 0 and 400
void DualVNH5019MotorShieldMod3::setM1Brake(int brake)
{
  // normalize brake
  if (brake < 0)
  {
    brake = -brake;
  }
  if (brake > 400)  // Max brake
    brake = 400;
  digitalWrite(_INA1, LOW);
  digitalWrite(_INB1, LOW);
  analogWrite(_PWM1,brake * 51 / 80); // default to using analogWrite, mapping 400 to 255
}

// Brake motor 2, brake is a number between 0 and 400
void DualVNH5019MotorShieldMod3::setM2Brake(int brake)
{
  // normalize brake
  if (brake < 0)
  {
    brake = -brake;
  }
  if (brake > 400)  // Max brake
    brake = 400;
  digitalWrite(_INA2, LOW);
  digitalWrite(_INB2, LOW);
  analogWrite(_PWM2,brake * 51 / 80); // default to using analogWrite, mapping 400 to 255
}

// Brake motor 3, brake is a number between 0 and 400
void DualVNH5019MotorShieldMod3::setM3Brake(int brake)
{
  // normalize brake
  if (brake < 0)
  {
    brake = -brake;
  }
  if (brake > 400)  // Max brake
    brake = 400;
  digitalWrite(_INA3, LOW);
  digitalWrite(_INB3, LOW);
  analogWrite(_PWM3,brake * 51 / 80); // default to using analogWrite, mapping 400 to 255
}

// Brake motor 4, brake is a number between 0 and 400
void DualVNH5019MotorShieldMod3::setM4Brake(int brake)
{
  // normalize brake
  if (brake < 0)
  {
    brake = -brake;
  }
  if (brake > 400)  // Max brake
    brake = 400;
  digitalWrite(_INA4, LOW);
  digitalWrite(_INB4, LOW);
  analogWrite(_PWM4,brake * 51 / 80); // default to using analogWrite, mapping 400 to 255
}

// Brake motor 1, 2, 3, and 4, brake is a number between 0 and 400
void DualVNH5019MotorShieldMod3::setBrakes(int m1Brake, int m2Brake, int m3Brake, int m4Brake)
{
  setM1Brake(m1Brake);
  setM2Brake(m2Brake);
  setM3Brake(m3Brake);
  setM4Brake(m4Brake);
}

// Return motor 1 current value in milliamps.
unsigned int DualVNH5019MotorShieldMod3::getM1CurrentMilliamps()
{
  // extra insurance for the analog read function, must be an input
  pinMode(_CS1,INPUT);
  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
  return analogRead(_CS1) * 34;
}

// Return motor 2 current value in milliamps.
unsigned int DualVNH5019MotorShieldMod3::getM2CurrentMilliamps()
{
  // extra insurance for the analog read function, must be an input
  pinMode(_CS2,INPUT);
  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
  return analogRead(_CS2) * 34;
}

// Return motor 3 current value in milliamps.
unsigned int DualVNH5019MotorShieldMod3::getM3CurrentMilliamps()
{
  // extra insurance for the analog read function, must be an input
  pinMode(_CS3,INPUT);
  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
  return analogRead(_CS3) * 34;
}

// Return motor 4 current value in milliamps.
unsigned int DualVNH5019MotorShieldMod3::getM4CurrentMilliamps()
{
  // extra insurance for the analog read function, must be an input
  pinMode(_CS4,INPUT);
  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
  return analogRead(_CS4) * 34;
}

// Return error status for motor 1 
unsigned char DualVNH5019MotorShieldMod3::getM1Fault()
{
  return !digitalRead(_EN1DIAG1);
}

// Return error status for motor 2 
unsigned char DualVNH5019MotorShieldMod3::getM2Fault()
{
  return !digitalRead(_EN2DIAG2);
}

// Return error status for motor 3 
unsigned char DualVNH5019MotorShieldMod3::getM3Fault()
{
  return !digitalRead(_EN3DIAG3);
}

// Return error status for motor 4 
unsigned char DualVNH5019MotorShieldMod3::getM4Fault()
{
  return !digitalRead(_EN4DIAG4);
}
