//Alarm system with SOUND Sensor

int sensorPin= A0;    //Microphone Sensor Pin on analog 0
int RedLed   = 2;        // voice detection led.
int greenLed = 3;
int buzzer   = 4;          // buzzer alarm.

int sensorValue= 0 ;

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
//const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
 // Serial.begin(9600);
  pinMode(RedLed, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(greenLed,OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 50) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  sensorValue = analogRead(sensorPin);         // read the value from the sensor:
Serial.print("sensorValue=");

Serial.print(sensorValue);          //The 'silence' sensor value is 800-1023
Serial.println(" ");

  if (sensorValue<250)  
  {  
    digitalWrite(RedLed,HIGH);
    Serial.println("RedLed is on");
    
    digitalWrite(buzzer,HIGH);
    tone(4,2000,500);
    Serial.println("Alarm is on...!!!");
   // delay(5000);

               // The red LEDs stay on for 2 seconds
} 
else {
    digitalWrite(RedLed,LOW);
    digitalWrite(greenLed,HIGH);
    Serial.println("grenLed is ON");
    
    digitalWrite(buzzer,LOW);
    Serial.println("Alarm is off");
    
    Serial.println("");

}
delay(1000); 
digitalWrite(RedLed,LOW);
digitalWrite(buzzer,LOW);
digitalWrite(greenLed,LOW);

}
