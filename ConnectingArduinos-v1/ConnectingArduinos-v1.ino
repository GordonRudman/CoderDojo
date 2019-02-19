/*
  DigitalReadSerial
 Reads a digital input on pin 1, prints the result to the serial monitor. Then sends an output to pin 10.

 Connect pin 10 to ground with a 110 ohm resistor. http://playground.arduino.cc/CommonTopics/PullUpDownResistor

 connect the pins of the arduinos together from pin 1 on the sender to pin 10 on the receiver.

 connect the grounds of the connected arduinos together.

 The first arduino in the chain will also need a button connected from 5V to pin 1.


 If you are interested in connecting arduinos there a nice exmple of writing to an I2C/TWI slave device on the arduino site https://www.arduino.cc/en/Tutorial/MasterWriter
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int Din = 1;
int Dout = 10;
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(Din, INPUT);

  // make the pushbutton's pin an output:
  pinMode(Dout, OUTPUT);

    // make the pushbutton's pin an output:
  pinMode(led, OUTPUT);


}

// the loop routine runs over and over again forever:
void loop() {

  // read the input pin:
  int DinState = digitalRead(Din); // connect a pull down resistor e.g. 110 ohm to ground from this pin
  
  // print out the state of DinState:
  Serial.println(DinState);
  delay(1);        // delay in between reads for stability

  if(DinState == HIGH){ // if there is another arduino sending HIGH do something

  //DO SOMETHING
  digitalWrite(led, HIGH); // e.g. setting the pin 13 LED to high. 
  digitalWrite(Dout, HIGH); // Then set the digital out to HIGH
  }
  
  else{ // if there is no arduino connected then set the digital out to low
  digitalWrite(Dout, LOW); 
  digitalWrite(led, LOW); //set the pin 13 LED back to low. 

  }



}



