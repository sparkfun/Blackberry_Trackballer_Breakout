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
#define Lft 4
#define Rht 5
#define Up 6
#define Dwn 7
#define Btn 3
#define WHT_LED 8
#define GRN_LED 9
#define RED_LED 10
#define BLU_LED 11

int buttonClick =0;
volatile int x_count = 0;
volatile int y_count = 0;
int scroll_Up =0;
int scroll_Dwn =0;
int scroll_Rht =0;
int scroll_Lft =0;
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
  
  attachInterrupt(digitalPinToInterrupt(2), tracking, CHANGE);
}


/*********************Main Loop*************************/
void loop() {
  
 
  buttonClick = digitalRead(Btn);
  if (buttonClick == LOW)
    {
      Serial.println("Click");  
    }
    scroll_Up = digitalRead(Up);
    scroll_Dwn = digitalRead(Dwn);
    scroll_Rht = digitalRead(Rht);
    scroll_Lft = digitalRead(Lft);
}

void tracking()
{
  if(scroll_Up == HIGH)
  {
    y_count= ++y_count;
  }
  else if(scroll_Dwn == HIGH)
  {
    y_count= --y_count;
  }
  else if (scroll_Rht == HIGH)
  {
    x_count = ++x_count;
  }
  else
  {
    x_count = --x_count;
  }
  Serial.print("X-count: ");
  Serial.print(x_count);
  Serial.print("\t Y-count: ");
  Serial.println(y_count);
}
