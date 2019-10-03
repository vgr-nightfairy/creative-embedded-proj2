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
const int ledPin[] = {23, 21, 19, 18, 17, 16, 4, 15};

const int Button = 22;

const int Xaxis = 34;
const int Yaxis = 35;

//int coordX = 0;
//int coordY = 0;
//const int ctrX = 1840;
//const int ctrY = 1806;
int curr = 0;
int prev = 0;

int ButtonRead = 0;
int XRead = 0;
int YRead = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  Serial.begin(9600);
  for (int i = 0; i < 8; i ++) {
    pinMode(ledPin[i], OUTPUT);
  }
  
  pinMode(Button, INPUT_PULLUP);
  
  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);

} 
//
//int slope(int x1, int y1, int x2, int y2)
//{
//  return ((y1-y2) / (x1-x2));
//}
//
//int currLocation (int x, int y, int cx, int cy) 
//{
//  int currSlope = slope(x, y, cx, cy); 
//
//  if (x > cx)
//  {
//    if (y > cy) 
//    {
//      if (currSlope > 1) 
//        return 0;
//      else
//        return 1;    
//    }
//    else 
//    {
//      if (currSlope > -1)
//        return 2;
//      else
//        return 3;
//    }
//  }
//
//  else
//  {
//    if (y < cy) 
//    {
//      if (currSlope > 1)
//        return 4;
//      else
//        return 5;
//    }
//    else 
//    {
//      if (currSlope > -1)
//        return 6;
//      else
//        return 7;
//    }
//  }
//}


// the loop function runs over and over again forever
void loop() {
  ButtonRead = digitalRead(Button);
  
  XRead = analogRead(Xaxis);
  YRead = analogRead(Yaxis);

  double rad = atan2(YRead - 1807, XRead - 1840);

  double deg = rad * 57.295779513082320876798154814105;

//  curr = currLocation(XRead, YRead, ctrX, ctrY);

//  digitalWrite(ledPin[curr], HIGH);
//  if (curr != prev) {
//    digitalWrite(ledPin[prev], LOW);
//  }
//
//  prev = curr;

  if (XRead > 1800 && XRead < 1900 && YRead > 1750 && YRead < 1850) {
    curr = 16;
  }
  else if (deg < -45.00 && deg > -90.00) {
    curr = 0;
  }
  else if (deg < 0.00 && deg >= -45.00) {
    curr = 1;
  }
  else if (deg >= 0.00 && deg < 45.00) {
    curr = 2;
  }
  else if (deg >= 45.00 && deg < 90.00) {
    curr = 3;
  }
  else if (deg >= 90.00 && deg < 135.00) {
    curr = 4;
  }
  else if (deg >= 135.00 && deg <= 180.00) {
    curr = 5;
  }
  else if (deg >= -180.00 && deg < -135.00) {
    curr = 6;
  }
  else if (deg >= -135.00 && deg <= -90.00) {
    curr = 7; 
  }

  if (curr == 16) {
    for (int i = 0; i < 8; i ++) {
      digitalWrite(ledPin[i], LOW);
    }
  }
  else {
    digitalWrite(ledPin[curr], HIGH);
    if (curr != prev) {
      digitalWrite(ledPin[prev], LOW);
    }
  }

  prev = curr;

  Serial.println(String(ButtonRead));
  Serial.println(String(XRead));
  Serial.println(String(YRead));
  Serial.println("Angle" + String(deg));
  
//  if (ButtonRead == 0){
//    for (int i = 0; i < 8; i ++) {
//      digitalWrite(ledPin[i], HIGH);
//    }
//    delay(500);
//  }
//  else {
//    for (int i = 0; i < 8; i ++) {
//      digitalWrite(ledPin[i], LOW);
//    }
//    delay(500);
//  }
} 
