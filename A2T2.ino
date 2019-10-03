int sensorPin = A0;    // select the input pin for the potentiometer
int StickX = 34;      // select the pin for the LED
int StickY = 35;
int Butt = 13;
int Switch = 27;
int LED = 12;

int SensorX = 0;  // variable to store the value coming from the sensor
int SensorY = 0;
int SenseButt = 0;
int SenseSwitch = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(StickX, INPUT);
  pinMode(StickY, INPUT);
  pinMode(Butt, INPUT);
  pinMode(Switch, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  SensorX = analogRead(StickX);
  SensorY = analogRead(StickY);
  SenseButt = digitalRead(Butt);
  SenseSwitch= digitalRead(Switch);
  

  Serial.println("JoyX " + String(SensorX)+ ", JoyY " + String(SensorY) + ", Button " + String(SenseButt) + ", Switch " + String(SenseSwitch) + ".");

  digitalWrite (LED, HIGH);  
  delay(1000);
  digitalWrite (LED, LOW);  
}
