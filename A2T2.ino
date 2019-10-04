const int ledPin[] = {23, 21, 19, 18, 17, 16, 4, 15, 32, 33, 25, 26, 27, 14, 12, 13};

const int Button = 22;

const int Switch = 5;

const int Xaxis = 34;
const int Yaxis = 35;

int curr = 0;
int prev = 0;

int ButtonRead = 0;
int XRead = 0;
int YRead = 0;
int SwitchRead = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 16; i ++) {
    pinMode(ledPin[i], OUTPUT);
  }
  
  pinMode(Button, INPUT_PULLUP);
  pinMode(Switch, INPUT);
  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);

} 

// the loop function runs over and over again forever
void loop() {
  ButtonRead = digitalRead(Button);
  SwitchRead = digitalRead(Switch);
  XRead = analogRead(Xaxis);
  YRead = analogRead(Yaxis);
  

  double rad = atan2(YRead - 1807, XRead - 1840);

  double deg = rad * 57.295779513082320876798154814105;

  if (ButtonRead == 0) {
    while(1);
  }

  
  if (XRead > 1800 && XRead < 1900 && YRead > 1750 && YRead < 1850) {
    curr = 16;
  }
  else if (deg < -67.50 && deg > -90.00) {
    curr = 0;
  }
  else if (deg < -45.00 && deg >= -67.50) {
    curr = 1;
  }
  else if (deg < -22.50 && deg >= -45.00) {
    curr = 2;
  }
  else if (deg < 0.00 && deg >= -22.50) {
    curr = 3;
  }
  else if (deg >= 0.00 && deg < 22.50) {
    curr = 4;
  }
  else if (deg >= 22.50 && deg < 45.00) {
    curr = 5;
  }
  else if (deg >= 45.00 && deg < 67.50) {
    curr = 6;
  }
  else if (deg >= 67.50 && deg < 90.00) {
    curr = 7;
  }
  else if (deg >= 90.00 && deg < 112.50) {
    curr = 8;
  }
  else if (deg >= 112.50 && deg < 135.00) {
    curr = 9;
  }
  else if (deg >= 135.00 && deg < 157.50) {
    curr = 10;
  }
  else if (deg >= 157.50 && deg <= 180.00) {
    curr = 11;
  }
  else if (deg >= -180.00 && deg < -157.50) {
    curr = 12;
  }
  else if (deg >= - 157.50 && deg < -135.00) {
    curr = 13;
  }
  else if (deg >= -135.00 && deg < -112.50) {
    curr = 14; 
  }
  else if (deg >= -112.50 && deg <= -90.00) {
    curr = 15;
  }

  if (SwitchRead == 0) {
    if (curr == 16) {
      for (int i = 0; i < 16; i ++) {
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
  }
  else {
    for (int i = 0; i < 16; i ++) {
      digitalWrite(ledPin[i], HIGH);
    }
    delay(1000);
    for (int i = 0; i < 16; i ++) {
      digitalWrite(ledPin[i], LOW);
    }
    delay(1000);
  }
   

  Serial.println(String(ButtonRead));
  Serial.println(String(XRead));
  Serial.println(String(YRead));
  Serial.println(String(SwitchRead));
  Serial.println("Angle" + String(deg));

} 
