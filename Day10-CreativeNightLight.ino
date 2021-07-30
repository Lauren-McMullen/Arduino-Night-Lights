
//Code written by Lauren McMullen for the Day 10 Creative Challenge of Inventr.io's 30 Days in Space Challenge
// Interactive night light program that changes color based on how bright your room is

// RGB LED Input pins

int RED = 11;
int GREEN = 10;
int BLUE = 9;

//Photosensor and Battery Variables

int sensorPin = A0;
int sensorValue = 0;


void RGB_color(int redValue, int greenValue, int blueValue) {
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
}

void RGB_off(){
  analogWrite(RED, LOW);
  analogWrite(GREEN, LOW);
  analogWrite(BLUE, LOW);
} 


void setup() {

 //Define RGB LED OUTPUT
 pinMode(RED, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT);

//Set up serial monitor
 Serial.begin(9600);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  
  if (sensorValue >= 20) { // BRIGHT LIGHTS
    RGB_off();
  }

  else if (sensorValue <= 19 && sensorValue >= 15 ){ // DIM LIGHTS
    RGB_color(97, 244, 70); //GREEN LED
  }
  
  else if (sensorValue < 15 && sensorValue >= 5){ // VERY DIM LIGHTS
     RGB_color(244, 70, 239); // PINK LED
  }

  else {
     RGB_color(103, 252, 245); //BLUE LED // LIGHTS OFF
  }
}
