#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Driver for the TFT display
#include <SPI.h>

// Define TFT display pins
/* incorrect - rely on built in pin definitions in pins_arduino.h
#define TFT_CS   6  // Chip select pin
#define TFT_DC  10  // Data/command pin
#define TFT_RST  9  // Reset pin
*/

/* correct pins from pins_arduino.h - automatically used by platformio */
// #define TFT_I2C_POWER 7
// #define TFT_CS        42
// #define TFT_RST       41
// #define TFT_DC        40
// #define TFT_BACKLITE  45


// Initialize the TFT display
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("Initializing TFT...");
  
  //TODO: turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

  // Initialize the TFT display
  tft.init(135, 240); // Initialize with width and height
  tft.setRotation(1); // Set display rotation
  tft.fillScreen(ST77XX_WHITE); // Clear the screen with black color

  // Display text on the screen
  tft.setTextColor(ST77XX_BLACK); // Set text color to white
  tft.setTextSize(2);             // Set text size
  tft.setCursor(10, 10);          // Set cursor position
  tft.println("Hello, ESP32-S3!"); // Print text to the screen
}

void loop() {
  // Nothing to do here
}