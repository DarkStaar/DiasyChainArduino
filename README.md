# DiasyChainArduino
Projekat iz LPRS2

SPI Daisy Chain project

This project was to connect 3 Arduino Uno boards in SPI Daisy Chain.
The principle on which this project works is our first Arduino is 
working as Master and other 2 Arduino's are Slaves. Master is always
sending value of lowercase letters, from a-z, and upon reset turns both LEDs on. 

There is also an entry from keyboard, which
allows the user to enter a value of 1, 2 or 3, where, depending on
the value entered, a certain LED will light up on slaves:
	
	- if user enters 1 -> Slave 1 will turn LED1 on, while Slave 2 will have LED1 off
	
	- if user enters 2 -> Slave 1 will set LED1 to off, while Slave 2 turns his LED1 on
	
	- if user enters 3 -> Both slaves will set their LED1 to on.
  
When Slave 1 receives a lowercase letter, write it in Serial, 
converts it to uppercase and sends it to Slave 2. 
Slave 2 takes the given uppercase letter, write it in Serial, 
and sends it to the Master who converts it to ASCII code and writes it in Serial.

Daisy Chain configuration:

![286845647_446897987237920_6224161387439325622_n](https://user-images.githubusercontent.com/63914173/173367199-ab37648d-a2df-4e95-8a77-b66e4de169f5.png)



[Arduino Youtube Video](https://www.youtube.com/watch?v=xu2h0jQKMZc&ab_channel=MilanKapetanovic)
