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

//Define breakout pin connections to Arduino
#define Btn 2
#define Lft 3
#define Rht 4
#define Up 5
#define Dwn 6
#define WHT_LED 7
#define GRN_LED 8
#define RED_LED 9
#define BLU_LED 10

int buttonClick =0;

//int mouse_Lft;
//int mouse_Rht;
//int mouse_Up;
//int mouse_Dwn;

volatile int x_count = 0;
volatile int y_count = 0;

/*********************Setup Loop*************************/
void setup() {
  
  //Define pin functionality
  pinMode(Btn, INPUT);
  pinMode(Lft, INPUT);
  pinMode(Rht, INPUT);
  pinMode(Up, INPUT);
  pinMode(Dwn, INPUT);
  pinMode(WHT_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);
  
  digitalWrite(WHT_LED, LOW);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLU_LED, LOW);
  digitalWrite(Lft, LOW);
  digitalWrite(Rht, LOW);
  digitalWrite(Up, LOW);
  digitalWrite(Dwn, LOW);
  
  Serial.begin(9600); //Start Serial port for debugging. 
  Serial.println("Begin Trackballer Demo");
  
  Serial.println("Turn on LEDs individually");
  //Demo each LED by turning them on individually for one second. 
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
  
  attachInterrupt(digitalPinToInterrupt(Rht), mouse_Rht, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(Lft), mouse_Lft, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(Up), mouse_Up, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(Dwn), mouse_Dwn, CHANGE);
//  
}


/*********************Main Loop*************************/
void loop() {
 
//Serial.print("Trackball Position: \t X-position");  
//Serial.print(x_count);
//Serial.print(" \t Y-position");
//Serial.print(y_count);
//Serial.println();

buttonClick = digitalRead(Btn);
if (buttonClick == LOW)
  {
    Serial.println("Click");  
  }
}

void mouse_Lft()
{
  x_count = --x_count;
  Serial.println("Left");
}

void mouse_Rht()
{
  x_count = ++x_count;
  Serial.println("Right");
}

void mouse_Up()
{
  y_count = ++y_count;
  Serial.println("Up");
}

void mouse_Dwn()
{
  y_count = --y_count;
  Serial.println("Dwn");
}
