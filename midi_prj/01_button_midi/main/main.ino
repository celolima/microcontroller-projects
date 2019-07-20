#include <MIDI.h>

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

//MIDI_CREATE_DEFAULT_INSTANCE();
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonPS = 0;         // previous state
boolean analogFlag = true;

void setup() {
  //MIDI.begin();
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  readButton();
  //readAnalogPot();
  readAnalogPot2();
}

void readAnalogPot2() {
  if(outputValue == 0) {
    analogFlag = true;
  } 
  
  if(outputValue == 256) {
    analogFlag = false;
  }

  if(analogFlag) {
    outputValue++;
  } else {
    outputValue--;
  }
  analogWrite(analogOutPin, outputValue);
  delay(10);
}

void readAnalogPot() {
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);    
}

void readButton() {
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if(buttonState != buttonPS) {
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // turn LED on:
      //MIDI.sendNoteOn(60,127,1);
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      //MIDI.sendNoteOn(60,0,1);
      digitalWrite(ledPin, LOW);
    }
  }
  buttonPS = buttonState;
}

