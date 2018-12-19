#include "FaBoMotor_DRV8830.h"

FaBoMotor faboMotor;
void setup(){
  Serial.begin(115200);
  Serial.println("TEST");  
  if(faboMotor.begin()) {
    Serial.println("Find drv8830");
  }

  faboMotor.drive(DRV8830_STANBY, 0);
  delay(30);
}

void loop(){
  for(int i = DRV_SPEED_MIN; i < DRV_SPEED_MAX;  i++) {
    faboMotor.drive(DRV8830_FORWARD, i);  
    delay(30);
  }

  for(int i = DRV_SPEED_MAX; i > DRV_SPEED_MIN;  i--) {
    faboMotor.drive(DRV8830_BACK, i);  
    delay(30);
  }
  
}
