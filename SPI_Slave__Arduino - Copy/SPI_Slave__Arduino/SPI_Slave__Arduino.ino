//SLAVE 2
#define LED0 9
#define LED1 10

#include <SPI.h>

volatile bool received;
volatile char slave_rxd;
volatile byte a;
char slave_txd;
// SPI ISR (Interrupt Service Routine).
ISR(SPI_STC_vect)
{
  // Store value received from Master.
  if(SPDR >= 65 && SPDR <= 90)
  {
    slave_rxd = SPDR;
    slave_txd = slave_rxd;
    Serial.println(slave_rxd);
  }
  if(SPDR > 48 && SPDR < 52)
  {
    a = SPDR;
    if(a == '2')
    {
      digitalWrite(LED0, 1);
    }
    else if (a == '1')
    {
      digitalWrite(LED0, 0);
    }
    else if(a == '3')
    {
      digitalWrite(LED0, 1);
    }
  }
  SPDR = slave_txd;
  // Signal to polling in loop().
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
    received = false;
  }
}
