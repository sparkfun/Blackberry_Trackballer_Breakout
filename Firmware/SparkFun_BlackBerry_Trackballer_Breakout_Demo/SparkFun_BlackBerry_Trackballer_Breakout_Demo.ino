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

int buttonState =0;
int Lft_HallEffect =0;
int Rht_HallEffect =0;
int Up_HallEffect =0;
int Dwn_HallEffect =0;

int  mouse_Settings[4]; 

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
  
  Serial.begin(115200); //Start Serial port for debugging. 
  Serial.println("Begin Trackballer Demo");
  
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
  
  Serial.println("Lft, Rht, Up, Dwn, Btn");
  
}


/*********************Main Loop*************************/
void loop() {
  
//  //Read button state, output to serial monitor if clicked
//  buttonState = digitalRead(Btn);
//  if (buttonState == LOW){
//    Serial.println("Button click");
//  }
//  
//   Lft_HallEffect = digitalRead(Lft);
//  if (Lft_HallEffect == LOW){
//    Serial.println("Left");
//  }
//  
//   Rht_HallEffect = digitalRead(Rht);
//  if (Rht_HallEffect == LOW){
//    Serial.println("Right");
//  }
//  
//   Up_HallEffect = digitalRead(Up);
//  if (Up_HallEffect == LOW){
//    Serial.println("Up");
//  }
//  
//   Dwn_HallEffect = digitalRead(Dwn);
//  if (Dwn_HallEffect == LOW){
//    Serial.println("Dwn");
//  }
  
// buttonState = digitalRead(Btn);
// Lft_HallEffect = digitalRead(Lft);
// Rht_HallEffect = digitalRead(Rht);
// Up_HallEffect = digitalRead(Up);
// Dwn_HallEffect = digitalRead(Dwn);
 
 mouse_Settings[0] = digitalRead(Lft);
 mouse_Settings[1] = digitalRead(Rht);
 mouse_Settings[2] = digitalRead(Up);
 mouse_Settings[3] = digitalRead(Dwn);
 mouse_Settings[4] = digitalRead(Btn);
  
Serial.println(mouse_Settings);
Serial.println();

}
