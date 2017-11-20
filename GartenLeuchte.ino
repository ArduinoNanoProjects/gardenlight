//BlockLED
const int blockPinLED     = 2;

//PixelLED
#include <Adafruit_NeoPixel.h>
#define BUTTON_PIN   11    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.
                          
#define PIXEL_PIN    3    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = LOW;
int showType = 0;

//ColorLED
const int whitePinLED     = 4;
const int redPinLED       = 5;
const int orangePinLED    = 6;
const int yellowPinLED    = 7;
const int greenPinLED     = 8;    
const int bluePinLED      = 9;
const int pinkPinLED      = 10;
int delayTime = 100;



void setup() {
  //button
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  //block LED
  pinMode(blockPinLED, OUTPUT);
  
  //pixel LED
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  //color LEDs
  pinMode(whitePinLED, OUTPUT);
  pinMode(yellowPinLED, OUTPUT);
  pinMode(orangePinLED, OUTPUT);
  pinMode(redPinLED, OUTPUT);
  pinMode(greenPinLED, OUTPUT);
  pinMode(bluePinLED, OUTPUT);
  pinMode(pinkPinLED, OUTPUT);
   
  //start retest
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
  colorWipe(strip.Color(255, 255, 255), 10);    // weiß
  digitalWrite(blockPinLED, HIGH);
  delay(delayTime);
  digitalWrite(whitePinLED, HIGH);
  delay(delayTime);
  digitalWrite(redPinLED, HIGH);
  delay(delayTime);
  digitalWrite(orangePinLED, HIGH);
  delay(delayTime);
  digitalWrite(yellowPinLED, HIGH);
  delay(delayTime);
  digitalWrite(greenPinLED, HIGH);
  delay(delayTime);
  digitalWrite(bluePinLED, HIGH);
  delay(delayTime);
  digitalWrite(pinkPinLED, HIGH);
  delay(delayTime);
  digitalWrite(blockPinLED, LOW);
  delay(delayTime);
  rainbowCycle(1);
  colorWipe(strip.Color(0, 0, 0), 100);    // Black/off
  digitalWrite(whitePinLED, LOW);
  delay(delayTime);
  digitalWrite(redPinLED, LOW);
  delay(delayTime);
  digitalWrite(orangePinLED, LOW);
  delay(delayTime);
  digitalWrite(yellowPinLED, LOW);
  delay(delayTime);
  digitalWrite(greenPinLED, LOW);
  delay(delayTime);
  digitalWrite(bluePinLED, LOW);
  delay(delayTime);
  digitalWrite(pinkPinLED, LOW);
  delay(delayTime);

  //standard LED on
  delay(delayTime);
  digitalWrite(whitePinLED, HIGH);
}

void loop() {
  // Get current button state.
  bool newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (newState == HIGH && oldState == LOW) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == HIGH) {
      showType++;
      if (showType > 28)
        showType=0;
      startShow(showType);
    }
  }

  // Set the last button state to the old state.
  oldState = newState;
}

void startShow(int i) {
  switch(i){
    
    //------------------------------ off ------------------------------------
    case 0:
            digitalWrite(pinkPinLED, LOW);
            delay(delayTime);
            colorWipe(strip.Color(255, 0, 0), 100);    // red
            digitalWrite(redPinLED, LOW);
            delay(delayTime);
            digitalWrite(redPinLED, HIGH);
            delay(delayTime);
            digitalWrite(orangePinLED, HIGH);
            delay(delayTime);
            digitalWrite(yellowPinLED, HIGH);
            delay(delayTime);
            digitalWrite(greenPinLED, HIGH);
            delay(delayTime);
            digitalWrite(bluePinLED, HIGH);
            delay(delayTime);
            digitalWrite(pinkPinLED, HIGH);
            delay(delayTime);
            digitalWrite(whitePinLED, HIGH);
            delay(delayTime);
            rainbowCycle(50);
            colorWipe(strip.Color(0, 0, 0), 10);    // Black/off
            digitalWrite(whitePinLED, LOW);
            delay(delayTime);
            digitalWrite(redPinLED, LOW);
            delay(delayTime);
            digitalWrite(orangePinLED, LOW);
            delay(delayTime);
            digitalWrite(yellowPinLED, LOW);
            delay(delayTime);
            digitalWrite(greenPinLED, LOW);
            delay(delayTime);
            digitalWrite(bluePinLED, LOW);
            delay(delayTime);
            digitalWrite(pinkPinLED, LOW);
            delay(delayTime);

            //standard LED on
            digitalWrite(whitePinLED, HIGH);
            delay(delayTime);
    break;

    //------------------------------ weiß -----------------------------------
    case 1: 
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
    break;
    case 2: 
        colorWipe(strip.Color(255, 255, 255), 1);  // weiß
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
    break;
    case 3: 
        colorWipe(strip.Color(255, 200, 80), 1);  // warmes weiß
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, HIGH);
    break;
    case 4: 
        colorWipe(strip.Color(255, 200, 80), 1);  // warmes weiß
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
    break;

    //-------------------------------- rot ----------------------------------
    case 5:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 0, 0), 1);  // red + weiß
        digitalWrite(redPinLED, HIGH);
    break;
    case 6:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 0), 1);  // red
        digitalWrite(redPinLED, HIGH);
    break;
    case 7:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 40, 0), 1);  // red - orange  + weiß
        digitalWrite(redPinLED, HIGH);
        digitalWrite(orangePinLED, HIGH);
    break;
    case 8:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 40, 0), 1);  // red - orange
        digitalWrite(redPinLED, HIGH);
        digitalWrite(orangePinLED, HIGH);
    break;
    
    //------------------------------ orange ---------------------------------
    case 9:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 100, 0), 1);  // orange  + weiß
        digitalWrite(redPinLED, LOW);
        digitalWrite(orangePinLED, HIGH);
    break;
    case 10:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 100, 0), 1);  // orange
        digitalWrite(redPinLED, LOW);
        digitalWrite(orangePinLED, HIGH);
    break;
    case 11:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 180, 0), 1);  // orange - yellow  + weiß
        digitalWrite(orangePinLED, HIGH);
        digitalWrite(yellowPinLED, HIGH);
    break;
    case 12:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 180, 0), 1);  // orange - yellow
        digitalWrite(orangePinLED, HIGH);
        digitalWrite(yellowPinLED, HIGH);
    break;
    
    //------------------------------ yellow ---------------------------------       
    case 13:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 200, 0), 1);  // yellow  + weiß
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, HIGH);
    break;
    case 14:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 200, 0), 1);  // yellow
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, HIGH);
    break;
    case 15:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(80, 255, 0), 1);  // yellow - green  + weiß
        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
    break;
    case 16:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(80, 255, 0), 1);  // yellow - green
        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
    break;
    
    //------------------------------ green ----------------------------------      
    case 17:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(0, 255, 0), 1);  // green + weiß
        digitalWrite(yellowPinLED, LOW);
        digitalWrite(greenPinLED, HIGH);
    break;
    case 18:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 255, 0), 1);  // green
        digitalWrite(yellowPinLED, LOW);
        digitalWrite(greenPinLED, HIGH);
    break;
    case 19:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(0, 255, 100), 1);  // green - blue / türkies  + weiß
        digitalWrite(greenPinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
    break;
    case 20:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 255, 100), 1);  // green - blue / türkies
        digitalWrite(greenPinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
    break;
    
    //------------------------------ blue -----------------------------------     
    case 21:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(0, 0, 255), 1);  // blue + weiß
        digitalWrite(greenPinLED, LOW);
        digitalWrite(bluePinLED, HIGH);            
    break;
    case 22:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 0, 255), 1);  // blue
        digitalWrite(greenPinLED, LOW);
        digitalWrite(bluePinLED, HIGH);            
    break;
    case 23: 
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(50, 0, 255), 1);  // lila + weiß
        digitalWrite(bluePinLED, HIGH);
        digitalWrite(pinkPinLED, HIGH);    
    break;
    case 24: 
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(50, 0, 255), 1);  // lila
        digitalWrite(bluePinLED, HIGH);
        digitalWrite(pinkPinLED, HIGH);    
    break;
    
    //------------------------------ pink -----------------------------------
    case 25:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 0, 255), 1);  // pink + weiß
        digitalWrite(bluePinLED, LOW);
        digitalWrite(pinkPinLED, HIGH);
    break;
    case 26:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 255), 1);  // pink
        digitalWrite(bluePinLED, LOW);
        digitalWrite(pinkPinLED, HIGH);
    break;
    case 27:
        digitalWrite(blockPinLED, HIGH);
        digitalWrite(whitePinLED, HIGH);
        colorWipe(strip.Color(255, 0, 80), 1);  // pinker + weiß
        digitalWrite(pinkPinLED, HIGH);
        digitalWrite(redPinLED, HIGH);
    break;
    case 28:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 80), 1);  // pinker
        digitalWrite(pinkPinLED, HIGH);
        digitalWrite(redPinLED, HIGH);
    break;
   
    
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  unsigned long ledMillis = 0;      // Zeit für den Blinkrythmus der LED
  int cycle = 5;

  for(j=0; j<256*cycle; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();

    if (millis() - ledMillis > wait)
    {
      ledMillis = millis();               // beginne die Zeitzählung von vorne
    }
    /*if(j == 1279 and i == 16){
      j=0;
      i=0;
    }*/
    
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
