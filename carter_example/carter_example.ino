// https://www.adafruit.com/product/5483
#include <Adafruit_ST7789.h> 

Adafruit_ST7789 display = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
GFXcanvas16 canvas(240, 135);

void setup() {
  Serial.begin(115200);
  //while(!Serial);
  Serial.println("Feather ESP32-S3 TFT - basic TFT display example.");

  delay(500);

  // turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

  // init display
  display.init(135, 240);
  display.setRotation(1);

  // draw stuff
  canvas.setTextColor(ST77XX_WHITE);
  canvas.setTextSize(3);
  canvas.println("Hello world");
  
  // output to display
  display.drawRGBBitmap(0, 0, canvas.getBuffer(), 240, 135);
}

void loop() {
}