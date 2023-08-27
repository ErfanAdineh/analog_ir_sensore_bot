#define enA 10
#define in1 9 
#define in2 8  
#define in3 7 
#define in4 6 
#define enB 5 

#define rightSensorPin A0 
#define leftSensorPin A1 

const int threshold = 500;     // Sensor threshold for detecting the line

void setup(){ 

	pinMode(rightSensorPin, INPUT);   
	pinMode(leftSensorPin, INPUT); 

	pinMode(enA, OUTPUT); 
	pinMode(in1, OUTPUT);  
	pinMode(in2, OUTPUT); 
	pinMode(in3, OUTPUT);   
	pinMode(in4, OUTPUT); 
	pinMode(enB, OUTPUT);

	analogWrite(enA, 150); 
	analogWrite(enB, 150);

  Serial.begin(9600);

	delay(1000);
}

void loop() {
  int leftSensorValue = analogRead(leftSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);

  if (leftSensorValue > threshold && rightSensorValue > threshold) {
      Stop();
  } else if (leftSensorValue > threshold) {
      turnLeft();
  } else if (rightSensorValue > threshold) {
      turnRight();
  } else {
    forword();
  }

  delay(100);
}

void forword(){  
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);  
	digitalWrite(in3, HIGH); 
	digitalWrite(in4, LOW);
}

void turnRight(){ 
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH); 
	digitalWrite(in3, LOW); 
	digitalWrite(in4, LOW);
}

void turnLeft(){ 
	digitalWrite(in1, LOW);  
	digitalWrite(in2, LOW);  
	digitalWrite(in3, HIGH);  
	digitalWrite(in4, LOW);  
}

void Stop(){ 
	digitalWrite(in1, LOW); 
	digitalWrite(in2, LOW); 
	digitalWrite(in3, LOW); 
	digitalWrite(in4, LOW); 
}