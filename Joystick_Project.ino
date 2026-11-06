int TT = 500;
const int RedLightX1 = 9;
const int RedLightX2 = 12;
const int RedLightY1 = 11;
const int RedLightY2 = 10;
const int YellowLight = 13;
int VY; // Voltage Y
int VX; //Voltage X
const int Button = 7;

void setup() {
  Serial.begin(9600);
  pinMode(VY, INPUT);
  pinMode(VX, INPUT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(RedLightX1, OUTPUT);
  pinMode(RedLightX2, OUTPUT);
  pinMode(RedLightY1, OUTPUT);
  pinMode(RedLightY2, OUTPUT);
  pinMode(YellowLight, OUTPUT);
 
  // put your setup code here, to run once:

}

void loop() {
  VY = analogRead(A0); // Check again
  VX = analogRead(A5);
  int ButtonState = digitalRead(Button);
  Serial.print("X Value: ");
  Serial.println(VX);
  Serial.print("Y Value: ");
  Serial.println(VY);
  Serial.print("ButtonState: ");
  if (ButtonState == HIGH) {
    Serial.println("0");
  }
  if (ButtonState == LOW) {
    Serial.println("1");
  }
  
  if (VX < 768 && VX > 256 && VY < 768 && VY > 256) {
    digitalWrite(RedLightX1, LOW);
    digitalWrite(RedLightX2, LOW);
    digitalWrite(RedLightY1, LOW);
    digitalWrite(RedLightY2, LOW);
  }
  if (VX > 768) {
    digitalWrite(RedLightX1, LOW);
    digitalWrite(RedLightX2, HIGH);
  }
  if (VX < 256) {
    digitalWrite(RedLightX1, HIGH);
    digitalWrite(RedLightX2, LOW);
  }

   if (VY > 768) {
    digitalWrite(RedLightY1, HIGH);
    digitalWrite(RedLightY2, LOW);
  }
  if (VY < 256) {
    digitalWrite(RedLightY1, LOW);
    digitalWrite(RedLightY2, HIGH);
  }

  if (ButtonState == LOW) {
    digitalWrite(YellowLight, HIGH);
  }
  else {
    digitalWrite(YellowLight, LOW);
  }


  // put your main code here, to run repeatedly:

}
