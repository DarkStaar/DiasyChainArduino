
#define LED0 9
#define LED1 10

#include <SPI.h>
bool flag1;
char master_cnt = 'a';
char a;
char input;
char data[2];
uint8_t master_rxd;

void setup() {
	pinMode(LED0, OUTPUT);
	digitalWrite(LED0, 0);
	// UART to console.
	Serial.begin(115200);

	// Begins the SPI commnuication.
	SPI.begin();
	// Sets clock for SPI communication at 16MHz/16 = 1Mhz.
	SPI.setClockDivider(SPI_CLOCK_DIV16);
	// Setting SS (Slave Select) to inactive.
	digitalWrite(SS, HIGH);
}

void loop() {
	char master_txd = master_cnt;
  input = Serial.read();
  if(input == '1'){
    a = '1';
  } 
  else if(input == '2'){
    a = '2';
  }
  else if (input == '3')
  {
    a = '3';
  }
  
  if(master_cnt == 'z')
  {
    master_cnt = 'a';
  }
  else
  {
    master_cnt++;
  }

	// Starts SPI communication with Slave connected to Master.
	digitalWrite(SS, LOW);
	// Send the master_txd value to Slave
	// and also receives value from Slave.
  
  master_rxd = SPI.transfer(master_txd);
  
  Serial.println(master_rxd);
  if(master_rxd == 90)
  {
    digitalWrite(LED0, 1);
    digitalWrite(LED1, 1);
    delay(2000);
    digitalWrite(LED0, 0);
    digitalWrite(LED1, 0);
  }
  delay(250);
  digitalWrite(SS, HIGH);
  delay(250);
  delay(750);
  digitalWrite(SS, LOW);
  
  SPI.transfer(a);
  delay(250);
  digitalWrite(SS, HIGH);
  delay(250);
  delay(750);
	Serial.println();
}
