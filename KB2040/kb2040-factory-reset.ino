#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, 17, NEO_GRB + NEO_KHZ800);
uint8_t wheelcounter = 0;

void setup() {
  Serial.begin(115200);
  //while (!Serial) delay(10);

  pixel.begin();
  pixel.setBrightness(20);
  pixel.show(); // Initialize all pixels to 'off'
}

void loop() {
  Serial.println(wheelcounter);
  pixel.setPixelColor(0, Wheel(wheelcounter++));
  pixel.show();
  delay(10);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return Adafruit_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return Adafruit_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return Adafruit_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
