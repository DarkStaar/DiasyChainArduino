//SLAVE 1
#define LED0 9
#define LED1 10

#include <SPI.h>

volatile bool received;
volatile char slave_rxd;
volatile char a;
volatile char temp;
char c = '0';
char slave_txd;
volatile bool flag;
// SPI ISR (Interrupt Service Routine).
ISR(SPI_STC_vect)
{
	// Store value received from Master.
  if(SPDR >= 97 && SPDR <= 122)
  {
    flag = false;
    slave_rxd = SPDR;
    Serial.println(slave_rxd);
    slave_txd = slave_rxd - 32;
    
  }
  
  if(SPDR > 48 && SPDR < 52)
  {
    flag = true;
    a = SPDR;
    if(a == '1')
    {
      digitalWrite(LED0, 1);
    }
    else if (a == '2')
    {
      digitalWrite(LED0, 0);
    }
    else
    {
      digitalWrite(LED0, 1);
    }
  }

  if(flag)
    {
      SPDR = a;
    }
    else
    {
      SPDR = slave_txd;
    }
	received = true;
}

void setup() {
	pinMode(LED0, OUTPUT);
	digitalWrite(LED0, 0);
	
	// UART to console.
	Serial.begin(115200);

	
	//Sets MISO as OUTPUT (Have to Send data to Master IN).
	pinMode(MISO, OUTPUT);
	// Turn on SPI in Slave Mode.
	SPCR |= 1 << SPE;
	received = false;
	// Enabling SPI ISR (Interrupt Service Routine).
	SPI.attachInterrupt();
}

void loop() {
	if(received){ // Polling something received.
    delay(500);
		received = false;
	}
}
