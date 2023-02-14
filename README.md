# ESP8266_HX711_OLED
Scale with ESP8266_HX711_OLED

Upload calibration version first.
Pick an object with know weight.
Run Serial Monitor to write down the readings.
Calibration Factor = Reading / Known Weight
Load the FIANL version.
Update the following line: //REPLACE WITH YOUR CALIBRATION FACTOR #define CALIBRATION_FACTOR xxxx.xxxx
Test.
Enjoy!
