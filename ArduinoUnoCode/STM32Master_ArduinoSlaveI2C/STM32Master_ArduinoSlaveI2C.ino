#include <Wire.h>

uint8_t gelen_data = 0;
uint8_t giden_data = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(0x37); //If I write an address to here, arduino will be slave.
  Wire.onRequest(istek_geldi);
  Wire.onReceive(veri_geldi);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void veri_geldi(int data){

  while(Wire.available()){

    gelen_data = Wire.read();
    analogWrite(5,gelen_data);

    Serial.print("Gelen Data : ");
    Serial.println(gelen_data);
    
    }
  
}

void istek_geldi(){

  giden_data = map(analogRead(A0),0,1023,0,99);
  Wire.write(giden_data);
  Serial.print("Gonderilen Data: ");
  Serial.print(giden_data);
  
  }
