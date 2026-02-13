#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Driver for the TFT display
#include <SPI.h>

// Define TFT display pins
#define TFT_CS   6  // Chip select pin
#define TFT_DC  10  // Data/command pin
#define TFT_RST  9  // Reset pin

// Initialize the TFT display
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("Initializing TFT...");

  // Initialize the TFT display
  tft.init(240, 135); // Initialize with width and height
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