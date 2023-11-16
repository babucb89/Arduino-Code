const int analogPin = A0;    // Analog pin number 14 for LM35 temperature sensor
const int ledPin = 13;       // Onboard LED pin

void setup() 
{
  pinMode(ledPin, OUTPUT);    //function that you create at the top of each program
  Serial.begin(9600);         //exchange messages with the Serial Monitor at a data rate of 9600 bits per second.
}

void loop() 
{
  int sensorValue = analogRead(analogPin);//Reads the value from the specified analog pin
  float temperatureCelsius = (sensorValue * 0.00488) * 100; // LM35 voltage to Celsius conversion

  if (temperatureCelsius < 30) 
  {
    blinkLED(250);  // Blink every 250 milliseconds
  } 
  else 
  {
    blinkLED(500);  // Blink every 500 milliseconds
  }

 
}

void blinkLED(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}
