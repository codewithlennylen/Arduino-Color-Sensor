#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequency = 0;

void setup() {
  Serial.begin(9600);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // set Output Frequency Scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

}

void loop() {
  // setting red photodiodes to be red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Get output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the frequency values to the more Readable 0-255 range.
  frequency = map(frequency, 15, 160, 255, 0);
  // Print the value on the Serial Monitor
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print(" ");
  // delay(100);

  // Set the Green photodiodes so that they can be Read.
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Get output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the frequency values to the more Readable 0-255 range.
  frequency = map(frequency, 30, 180, 255, 0);
  // Print the value on the Serial Monitor
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print(" ");
  delay(100);

  // Set the Blue photodiodes so that they can be Read.
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Read the frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the frequency values to the more Readable 0-255 range.
  frequency = map(frequency, 10, 60, 255, 0);
  // Print the value on the Serial Monitor
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println(" ");
  delay(100);
  
}
