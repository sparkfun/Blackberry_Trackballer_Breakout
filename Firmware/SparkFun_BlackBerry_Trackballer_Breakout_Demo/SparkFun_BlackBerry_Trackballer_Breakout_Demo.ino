/**************************************************************************
SparkFun BlackBerry Trackballer Breakout Demo
Toni Klopfenstein @ SparkFun Electronics
March 2015
https://github.com/sparkfun/Blackberry_Trackballer_Breakout
This demo shows all the basic functionality of the SparkFun BlackBerry Trackballer Breakout (https://www.sparkfun.com/products/13169).
Development environment specifics:
Developed in Arduino 1.6.0
This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
***************************************************************************/

//Define Trackballer Breakout pin connections to Arduino
#define Btn 2
#define Lft 3
#define Rht 4
#define Up 5
#define Dwn 6
#define WHT_LED 7
#define GRN_LED 8
#define RED_LED 9
#define BLU_LED 10

//Define variables used in sketch
int buttonClick;
unsigned long mouse_Lft;
unsigned long mouse_Rht;
unsigned long mouse_Up;
unsigned long mouse_Dwn;
int x_position;
int y_position;

/*********************Setup Loop*************************/
void setup() {
  
  //Define pin functionality on the Arduino
  pinMode(Btn, INPUT);
  pinMode(Lft, INPUT);
  pinMode(Rht, INPUT);
  pinMode(Up, INPUT);
  pinMode(Dwn, INPUT);
  pinMode(WHT_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);
  
  //Pull LED pins low to prevent flickering
  digitalWrite(WHT_LED, LOW);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLU_LED, LOW);
  
  //Start Serial port for debugging. 
  Serial.begin(9600); 
  Serial.println("Begin Trackballer Demo");
 
  //Demo each LED by turning them on individually for one second. 
  Serial.println("Turn on LEDs individually");
  digitalWrite(WHT_LED, HIGH);
  delay(1000);
  digitalWrite(WHT_LED, LOW);
  
  digitalWrite(GRN_LED, HIGH);
  delay(1000);
  digitalWrite(GRN_LED, LOW);
  
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  
  digitalWrite(BLU_LED, HIGH);
  delay(1000);
  digitalWrite(BLU_LED, LOW);
  
  Serial.println("Begin Trackball tracking");
}


/*********************Main Loop*************************/
void loop() {
  
  //Wait for 2ms on each direction pin for movement.
  //Pins are driven HIGH by the breakout board.
  //pulseIn measures the length of each pulse in microseconds. 
  mouse_Lft = pulseIn(Lft, HIGH, 20000);
  mouse_Rht = pulseIn(Rht, HIGH, 20000);
  mouse_Up = pulseIn(Up, HIGH, 20000);
  mouse_Dwn = pulseIn(Dwn, HIGH, 20000);
  
  //Determine if there was movement in any direction. 
  //If movement occurred, adjust x/y coordinates based on movements.
  //Directionality is based off of an x/y plane (i.e., Up 1 unit and Right 1 unit = (1,1))
  if (mouse_Lft > 0)
  {
    x_position= --x_position;
  }
  if (mouse_Rht > 0)
  {
    x_position= ++x_position;
  }
  if (mouse_Up > 0)
  {
    y_position= ++y_position;
  }
  if (mouse_Dwn > 0)
  {
    y_position= --y_position;
  }
  
  //Output x/y coordinates to Serial terminal
  Serial.print("Trackball Position: \t X-Position= ");  
  Serial.print(x_position);
  Serial.print(" \t Y-position= ");
  Serial.print(y_position);
  Serial.println();
  
  //Check for button click. If present, print to Serial monitor.
  buttonClick = digitalRead(Btn);
  if (buttonClick == LOW)
  {
    Serial.println("Click");  
  }
}
