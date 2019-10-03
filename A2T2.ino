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
const int ledPin = 23;
const int Button = 13;

int ButtonRead = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(Button, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  ButtonRead = digitalRead(Button);
  Serial.println(String(ButtonRead));
  if (ButtonRead == 1){
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
  }
  else {
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(500);
  }
} 
