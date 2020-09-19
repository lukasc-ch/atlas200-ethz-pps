#include <SoftwareSerial.h>

SoftwareSerial btmodule(10, 11); // RX | TX

void setup() {
  Serial.begin(9600); 
  btmodule.begin(38400); //Baud Rate for command Mode. 
  //config for Arduino-side bluetooth module
  btmodule.write("AT+NAME=PPS_no_config\r\n"); // CHANGE to your group number (style: PPS_01 for group 01)
  btmodule.write("AT+UART=38400,0,0\r\n");
  btmodule.write("AT+ROLE=0\r\n");
  Serial.println("Enter AT commands for Bluetooth module:");
}

void loop() {
  // Feed any data from bluetooth to Terminal.
  while (btmodule.available())
    Serial.write(btmodule.read());
  
  // Feed all data from termial to bluetooth
  while (Serial.available())
    btmodule.write(Serial.read());
}

//With this program the UART connecting to the Arduino IDE forwards the commands to the Bluetooth module (and vice-versa)
//The bluetooth module should connect its TXD, RXD pins to pins 10, 11 on the Arduino, and 'key' to VCC for configuration/AT mode. 
//Try some commands: 
// AT         check connection
// AT+NAME?   get name
// AT+NAME=A  set name to A
// AT+ADDR    get or set MAC address
//other commands: VERSION, UART, ROLE (master or slave), RESET (soft reset and exit AT mode), ORGL (factory reset), PSWD (password)
//pattern: "AT+NAME?" to get the name, "AT+NAME=ABC" to set the name to ABC
//a (over-)complete list can be found here: https://www.itead.cc/wiki/Serial_Port_Bluetooth_Module_(Master/Slave)_:_HC-05
//
//To use the device as a serial link, remove the 'key' connection, power-cycle, and connect with your phone and send message back and forth (e.g., with 'serial bluetooth terminal' app)
