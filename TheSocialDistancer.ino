
const int trigPinF = 9;
const int echoPinF = 10;
const int trigPinR = 8;
const int echoPinR = 7;
const int trigPinB = 6;
const int echoPinB = 5;
const int trigPinL = 4;
const int echoPinL = 3;
const int buzzer = 2;

float durationF, distanceF, durationR, distanceR, durationB, distanceB, durationL, distanceL;

void setup() {
  pinMode(trigPinF, OUTPUT);
  pinMode(echoPinF, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPinB, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  noTone(buzzer);
  
  //Front Sensor
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);
  durationF = pulseIn(echoPinF, HIGH);
  distanceF = (durationF*.0343)/2;

  //Right Sensor
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = (durationR*.0343)/2;

  //Rear Sensor
  digitalWrite(trigPinB, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  durationB = pulseIn(echoPinB, HIGH);
  distanceB = (durationB*.0343)/2;

  //Left Sensor
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = (durationL*.0343)/2;

  if (distanceF < 5 ){
  tone(buzzer, 1000);
  delay(1000);
  }
  else if (distanceR < 5){
  tone(buzzer, 1000);
  delay(1000);
  }
  else if (distanceB < 5){
  tone(buzzer, 1000);
  delay(1000);
  }
  else if (distanceL < 5){
  tone(buzzer, 1000);
  delay(1000);
  }
  else {
  Serial.println(" ");
  Serial.print("Front Distance: ");
  Serial.println(distanceF);
  Serial.print("Right Distance: ");
  Serial.println(distanceR);
  Serial.print("Back Distance: ");
  Serial.println(distanceB);
  Serial.print("Left Distance: ");
  Serial.println(distanceL);
  }
 
  delay(100);
}
