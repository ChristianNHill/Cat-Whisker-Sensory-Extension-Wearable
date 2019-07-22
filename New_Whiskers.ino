/******************************************************************************

Flex_Sensor_Tactile_Display_Combined
By Nick Gonyea
Code derived from SparkFun's Flex_Sensor_Example.ino 
(Jim Linblom; April 28, 2016)
 

Create a voltage divider circuit combining a flex sensor with a 10k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.

******************************************************************************/
// measure the voltage at 3.3V and the actual resistance of your
// 47k resistor, and enter them below:

#define VIB 3
#define VIB1 9
#define VIB2 10 
#define VIB3 11


const int FLEX_PIN = A0; // Pin connected to voltage divider output
const int FLEX_PIN1 = A1; // Pin connected to voltage divider output
const int FLEX_PIN2 = A2; // Pin connected to voltage divider output
const int FLEX_PIN3 = A3; // Pin connected to voltage divider output

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(VIB, OUTPUT);
  pinMode(VIB1, OUTPUT);
  pinMode(VIB2, OUTPUT);
  pinMode(VIB3, OUTPUT);


}

void loop() 
{
  analogWrite(VIB,0);
  analogWrite(VIB1,0);
  analogWrite(VIB2,0);
  analogWrite(VIB3,0);
  
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);
  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  
  if(angle >= 100){ // Set thresholds for whisker 1 (Tweak the number value to your whisker)
      analogWrite(VIB, 100); //Sets vibration motor intensity
  }
   if(angle >= 200){
      analogWrite(VIB, 150);
  }
   if(angle >= 300){
      analogWrite(VIB, 200);
  }
  Serial.println("Bend: " + String(angle) + " degrees"); // Prints value of the angle
  Serial.println();

  // Read the ADC for pin 1, and calculate voltage and resistance from it
  int flexADC1 = analogRead(FLEX_PIN1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  
  if(angle1 >= 100){ //Set thresholds for whisker 2
      analogWrite(VIB1, 100); //Sets vibration motor intensity (Tweak the number value to your whisker)
  }
   if(angle1 >= 200){
      analogWrite(VIB1, 150);
  }
   if(angle1 >= 300){
      analogWrite(VIB1, 200);
  }
  Serial.println("Bend1: " + String(angle1) + " degrees"); // Prints value of the angle
  Serial.println();

// Read the ADC for pin 2, and calculate voltage and resistance from it
  int flexADC2 = analogRead(FLEX_PIN2);
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  
  if(angle2 >= 100){ //Set thresholds for whisker 3
      analogWrite(VIB2, 100); //Sets vibration motor intensity (Tweak the number value to your whisker)
  }
   if(angle2 >= 200){
      analogWrite(VIB2, 150);
  }
   if(angle2 >= 300){
      analogWrite(VIB2, 200);
  }

  Serial.println("Bend2: " + String(angle2) + " degrees"); // Prints value of the angle
  Serial.println();


  // Read the ADC pin 3, and calculate voltage and resistance from it
  int flexADC3 = analogRead(FLEX_PIN3);
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  
  if(angle3 >= 100){ //Set thresholds for whisker 4
      analogWrite(VIB3, 100); //Sets vibration motor intensity (Tweak the number value to your whisker)
  }
   if(angle3 >= 200){
      analogWrite(VIB3, 150);
  }
   if(angle3 >= 300){
      analogWrite(VIB3, 200);
  }
  Serial.println("Bend3: " + String(angle3) + " degrees"); // Prints value of the angle
  Serial.println();

  delay(100);
}
