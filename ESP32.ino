//ESP32
//cf) https://forum.arduino.cc/t/esp32-serial2-does-not-send-anything/1080745
//    (↓以下3つは補助的   ↑上のものは決定的)
//    https://akizukidenshi.com/goodsaffix/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
//    https://www.youtube.com/watch?v=7CQNLu5OfT8
//    https://www.esp32.com/viewtopic.php?t=39700
#include <HardwareSerial.h>

void setup() {
Serial.begin(115200);
Serial2.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  if (Serial2.available() > 0) {
    Serial.write(Serial2.read());
  }
  if (Serial.available() > 0) {
    Serial2.write(Serial.read());
  }
}