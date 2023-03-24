int centimeter = 0;
int inches = 0;
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup() {
  Serial.begin(9600);
}
void loop() {
  centimeter = 0.01723 * readUltrasonicDistance(9, 6);
  inches = (centimeter / 2.54);
  Serial.print(inches);
  Serial.print(" in | ");
  Serial.print(centimeter);
  Serial.println("cm.");
  delay(1000); // Wait for 1000 millisecond(s)
}