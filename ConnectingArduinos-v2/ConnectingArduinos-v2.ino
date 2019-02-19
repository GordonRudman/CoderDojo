/*
  DigitalReadSerial
 Reads a digital input on pin 1, prints the result to the serial monitor. Then sends an output to pin 10.

 Connect pin 10 to ground with a pulldown resistor (eg. 10k ohm). http://playground.arduino.cc/CommonTopics/PullUpDownResistor

 connect the pins of the arduinos together from pin 1 on the sender to pin 10 on the receiver.

 connect the grounds of the connected arduinos together.

 The first arduino in the chain will also need a button connected from 5V to pin 1.


 If you are interested in connecting arduinos there a nice exmple of writing to an I2C/TWI slave device on the arduino site https://www.arduino.cc/en/Tutorial/MasterWriter
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int receiverPin = 1;
int transmitterPin = 10;
int ledPin = 13;

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the receiver pin an input:
  pinMode(receiverPin, INPUT);

  // make the transmitter pin an output:
  pinMode(transmitterPin, OUTPUT);

  // make the ledPin pin an output:
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  // read the input pin:
  int receiverPinState = digitalRead(receiverPin); // connect a pull down resistor e.g. 10k ohm to ground from this pin
  
  // print out the state of receiverPinState:
  Serial.println(receiverPinState);
  delay(1);        // delay in between reads for stability

  if(receiverPinState == HIGH)  // if there is another arduino sending HIGH do something
  { 
    doSomethingCool();
    
    digitalWrite(ledPin, HIGH);          // e.g. setting the pin 13 ledPin to high. 
    digitalWrite(transmitterPin, HIGH);  // Then set the digital out to HIGH
  }  
  else
  { 
  // if there is no arduino connected then set the digital out to low
    digitalWrite(transmitterPin, LOW); 
    digitalWrite(ledPin, LOW); //set the pin 13 ledPin back to low. 
  }
}

void doSomethingCool()
{

}


