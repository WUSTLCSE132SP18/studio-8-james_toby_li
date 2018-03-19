#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library

MMA8452Q accel;


void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");
  

  accel.init();
 
}


void loop()
{
  
  if (accel.available())
  {
   
    accel.read();
    
    
    printCalculatedAccels();
    
    printOrientation();
    
    Serial.println(); // Print new line every time.
  }
}


void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
 
  }


void printCalculatedAccels()
{ 
//  Serial.print(accel.cx, 3);
//  Serial.print("\t");
//  Serial.print(accel.cy, 3);
//  Serial.print("\t");
//  Serial.print(accel.cz, 3);
//  Serial.print("\t");
  Serial.print(accel.cx);
  Serial.print(',');
  Serial.print(accel.cy);
  Serial.print(',');
  Serial.print(accel.cz);
  Serial.println();
}


void printOrientation()
{
  
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
