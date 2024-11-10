/* this program'S goal is to be able to measure the distance of a detected 
object between the HC-SR04. Thus, it operates on 5 volts. It uses an ultrasonic transmitter and receiver*/

#define trigPin 10 //CONNECTION TO TRIGGER ON THE ULTRASONIC
#define echoPin 13 //ECHO PIN
 
float duration, distance; //floating point variable so there can be decimals on the monitor
 
void setup() {
  Serial.begin (9600); //serial monitor to look at results
  pinMode(trigPin, OUTPUT); //sending pulses from arduino to device
  pinMode(echoPin, INPUT); //echo pin inputs back into device
}
 
void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //10 microseconds
  digitalWrite(trigPin, LOW); // creates a 10 microsecond pulse
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH); //measures duration of a pulse
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343; //distance is half of the result
  
  // Send results to Serial Monitor
 
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
     Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500); }
