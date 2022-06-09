
#define LED0 9
#define LED1 10

#include <SPI.h>
bool flag1;
char master_cnt = 'a';
char a;
char input;
char data[2];
uint8_t master_rxd;

char transferAndWait(char slovo)
{
  char a = SPI.transfer(slovo);
  delay(50);
  return a;
}

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
    flag1 = true;
  } else if(input == '2'){
    flag1 = false;
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
  if(flag1){
    a = '1';
  } else{
    a = '2';
  }
  
  master_rxd = SPI.transfer(master_txd);
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
  //transferAndWait(a);
	// Show LSB of Rx data on LED0.
	Serial.println(master_rxd);
	Serial.println();
}
