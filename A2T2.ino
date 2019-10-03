////int sensorPin = A0;    // select the input pin for the potentiometer
////int StickX = 34;      // select the pin for the LED
////int StickY = 35;
//int Butt = 13;
////int Switch = 27;
//int LED = 23;
////
////int SensorX = 0;  // variable to store the value coming from the sensor
////int SensorY = 0;
//int SenseButt = 0;
////int SenseSwitch = 0;
////
//void setup() {
////  // put your setup code here, to run once:
//  Serial.begin(9600);
////  pinMode(StickX, INPUT);
////  pinMode(StickY, INPUT);
//  pinMode(Butt, INPUT);
////  pinMode(Switch, INPUT);
//  pinMode(LED, OUTPUT);
//}
////
//void loop() {
////  // read the value from the sensor:
////  SensorX = analogRead(StickX);
////  SensorY = analogRead(StickY);
//  SenseButt = digitalRead(Butt);
////  SenseSwitch= digitalRead(Switch);
////  
////
//  Serial.println(String(buttonState));
//  if (SenseButt == 1) {
//    digitalWrite(LED, HIGH);
//    delay(200);
//  }
//  if (SenseButt == 0) {
//    digitalWrite(LED, LOW);
//    delay(200);
//  }
////  Serial.println("JoyX " + String(SensorX)+ ", JoyY " + String(SensorY) + ", Button " + String(SenseButt) + ", Switch " + String(SenseSwitch) + ".");
////
////  digitalWrite (LED, HIGH);  
////  delay(1000);
////  digitalWrite (LED, LOW);  
//}

/*
  Blink
*/

// ledPin refers to ESP32 GPIO 23
const int ledPin1 = 23;
const int ledPin2 = 21;
const int ledPin3 = 19;
const int ledPin4 = 18;
const int ledPin5 = 17;
const int ledPin6 = 16;
const int ledPin7 = 4;
const int ledPin8 = 15;
const int Button = 22;
const int Xaxis = 34;
const int Yaxis = 35;

int ButtonRead = 0;
int XRead = 0;
int YRead = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  ButtonRead = digitalRead(Button);
  XRead = analogRead(Xaxis);
  YRead = analogRead(Yaxis);
  Serial.println(String(ButtonRead));
  Serial.println(String(XRead));
  Serial.println(String(YRead));
  
  if (ButtonRead == 0){
    digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    delay(500);
  }
  else {
    digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    delay(500);
  }
} 

