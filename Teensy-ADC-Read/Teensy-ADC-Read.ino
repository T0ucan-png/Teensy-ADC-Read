#include <avr/io.h>
#include <avr/interrupt.h>
#include <ADC.h>

void setup() {
//Start the serial communications
  Serial.begin(38400);
  while(!Serial){
    delay(1); //Wait for serial to connect
  }
//Setup ADC for operation
  ADCSetup();
}

void loop() {
//Read Ducer through ADC
  x = analogeRead(A24); //These mfers taking all the fun out of coding
//Output result through Serial
  Serial.write(x, length(x));
  delay(10);
}

void ADCSetup(){
  ADC1_CFG |= 32792;
  ADC1_GC  |= (1 << 7);
  do{
    delay(1);
  }while(ADC1_GC && 128);

}
