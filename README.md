# ESP8266_HX711_OLED

1. Upload calibration version first.

2. Pick an object with know weight.

3. Run Serial Monitor to write down the readings.

# Calibration Factor = Reading / Known Weight

4. Load the FIANL version.

5. Update the following line: 

- //REPLACE WITH YOUR CALIBRATION FACTOR 

- #define CALIBRATION_FACTOR xxxx.xxxx

6. Test.

7. Enjoy!


# ESP8266 Load Cell with HX711 and OLED Display

This project demonstrates how to use an ESP8266 microcontroller, an HX711 load cell amplifier, and an SSD1306 OLED display to create a simple weight scale. The project also includes a push-button for taring (zeroing) the scale. The project was developed with the assistance of an OpenAI expert, making it perfect for beginners and hobbyists who want to learn more about ESP8266 and its capabilities.

## Features

- Measure weight using an HX711 load cell amplifier
- Display the weight on an SSD1306 OLED display
- Tare (zero) the scale using a push-button
- Easy to set up and use, perfect for beginners
- Clear instructions and guidance for assembly and usage

## Required Components

- ESP8266 microcontroller (e.g., NodeMCU or Wemos D1 Mini)
- HX711 load cell amplifier
- Load cell
- SSD1306 OLED display (128x64 pixels, I2C interface)
- Push-button
- Breadboard
- Jumper wires

## Libraries

- [HX711 library by Bogdan Necula](https://github.com/bogde/HX711)
- [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)
- [Pushbutton library by Pololu](https://github.com/pololu/pushbutton-arduino)

## Pin Connections

- HX711:
  - Connect `LOADCELL_DOUT_PIN` to `D6` on the ESP8266
  - Connect `LOADCELL_SCK_PIN` to `D7` on the ESP8266
  - Connect the HX711 to the load cell according to the manufacturer's specifications
- OLED display (I2C):
  - Connect `SDA` to `D2` on the ESP8266
  - Connect `SCL` to `D1` on the ESP8266
  - Connect `VCC` to `3.3V` or `5V` on the ESP8266 (depending on your display's voltage requirements)
  - Connect `GND` to `GND` on the ESP8266
- Push-button:
  - Connect one side of the push-button to `D5` on the ESP8266
  - Connect the other side of the push-button to `GND` on the ESP8266

## Setup and Usage

1. Download and install the Arduino IDE on your computer: [Arduino IDE Download](https://www.arduino.cc/en/Main/Software)
2. Install the required libraries mentioned above using the Arduino Library Manager.
3. Set up your hardware according to the pin connections provided.
4. Connect your ESP8266 board to your computer using a USB cable.
5. Open the Arduino IDE and create a new sketch.
6. Copy and paste the provided code into the Arduino IDE.
7. Replace the `CALIBRATION_FACTOR` in the code with your own calibration factor. This value is obtained by calibrating the scale with known weights.
8. Select the appropriate board and port for your ESP8266 in the Arduino IDE under the "Tools" menu.
9. Upload the code to your ESP8266 board.

Once the code is uploaded, the OLED display should show the current weight. Press the push-button to tare (zero) the scale.

## Troubleshooting

- If the OLED display does not show any output, double-check the I2C connections and ensure that the display's voltage requirements are met (either 3.3V or 5V, depending on your specific display).

- If the weight readings are inaccurate, ensure that the load cell is connected correctly to the HX711 and that the CALIBRATION_FACTOR is properly set.

- If you encounter issues with the push-button, check its connections and ensure that it is wired correctly to the ESP8266.

- If you still face issues, try to isolate the problem by testing each component individually. For example, you can test the OLED display using example sketches provided by the Adafruit SSD1306 library, and you can test the HX711 and load cell using example sketches from the HX711 library.
# 
Feel free to ask for further assistance if you encounter any issues or have questions about the project. Good luck, and have fun exploring the capabilities of the ESP8266!
