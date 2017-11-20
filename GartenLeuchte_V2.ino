//BlockLED
const int blockPinLED     = 2;

//PixelLED
#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN           3    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT         10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

//Button 1
#define BUTTON1_PIN         11
bool oldState1            = 0;
int witeType              = 0;
int wState                = 0;
int wSave                 = 1;
int witeStatus =            LOW;

//Button 2
#define BUTTON2_PIN         12
bool oldState2            = 0;
int showType              = 0;
int colorType             = LOW;
int colorModus            = LOW;
int colorStatus           = LOW;

//ColorLED
const int whitePinLED     = 4;
const int redPinLED       = 5;
const int orangePinLED    = 6;
const int yellowPinLED    = 7;
const int greenPinLED     = 8;    
const int bluePinLED      = 9;
const int pinkPinLED      = 10;

//Delays
int delayTime             = 50;
int delayTime2            = 70;

/**
 * Registration
 */
void setup() {
  //button 1 + button 2
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  
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
  colorWipe(strip.Color(0, 0, 0), 0);           // Black/off
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
  digitalWrite(whitePinLED, HIGH);
  digitalWrite(redPinLED, HIGH);
}

/**
 * Programm
 */
void loop() {
  
  bool stateButton1 = digitalRead(BUTTON1_PIN);
  bool stateButton2 = digitalRead(BUTTON2_PIN);

  // Button: 1
  if (stateButton1 == HIGH && oldState1 == 0 && wState == 0) { 
    delay(20);
    stateButton1 = digitalRead(BUTTON1_PIN);
    if (stateButton1 == HIGH) {
        witeType++;
      if (witeType > 5)
         witeType=0;
         witeStatus = witeShow(witeType);
    }
  }
  oldState1 = stateButton1;



  // Button: 2
  if (stateButton2 == HIGH && oldState2 == LOW) {
    delay(10);
    if (stateButton2 == HIGH && oldState2 == LOW) { 
      delay(20);
      stateButton2 = digitalRead(BUTTON2_PIN);
      if (stateButton2 == HIGH) {
          showType++;
        if (showType > 12)
           showType=0;
           colorStatus = colorShow(showType);
      }
    }
    
    if(colorStatus == HIGH) { 
      wState = 1;
      digitalWrite(whitePinLED, colorModus);
      digitalWrite(blockPinLED, colorModus);
    } else { 
      wState = 0;
      digitalWrite(blockPinLED, LOW);
    }
  }
  oldState2 = stateButton2;


  
  // Button 2 + Button 1
  if (stateButton1 == HIGH && wState == 1 && colorType == LOW) {
    delay(30);
    colorModus = !colorModus;
    digitalWrite(whitePinLED, colorModus);
    digitalWrite(blockPinLED, colorModus);
  }
  colorType = stateButton1;
}


/**
 * Button 1: wite light
 */
int witeShow(int w){
  int wOutputLED;
  switch(w){
    
    //------------------------------ off ------------------------------------
    case 0:
        //Lamp
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        digitalWrite(pinkPinLED, HIGH);
        delay(delayTime);
        rainbowCycle(500);
        colorWipe(strip.Color(0, 0, 0), 100);    

        //LEDs
        digitalWrite(pinkPinLED, LOW);
        delay(delayTime);
        digitalWrite(bluePinLED, LOW);
        delay(delayTime);
        digitalWrite(greenPinLED, LOW);
        delay(delayTime);
        digitalWrite(yellowPinLED, LOW);
        delay(delayTime);
        digitalWrite(orangePinLED, LOW);
        delay(delayTime);
        digitalWrite(redPinLED, LOW);
        delay(delayTime);
        
        //standard LED on
        digitalWrite(redPinLED, HIGH);
        delay(delayTime);
        digitalWrite(whitePinLED, HIGH);
        delay(delayTime);
        wOutputLED = LOW;
    break;
    case 1:
        //Lamp
        colorWipe(strip.Color(0, 0, 0), 0);
        digitalWrite(blockPinLED, HIGH);              // -block
        wOutputLED = HIGH;

        //LEDs
        digitalWrite(whitePinLED, HIGH); //<--
        
        digitalWrite(redPinLED, LOW);
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, HIGH); //<--
        digitalWrite(greenPinLED, LOW);
        digitalWrite(bluePinLED, LOW);
        digitalWrite(pinkPinLED, LOW);
    break;
    case 2:
        //Lamp
        colorWipe(strip.Color(255, 255, 255), 1);  // -weiß
        digitalWrite(blockPinLED, LOW);
        wOutputLED = HIGH;

        //LEDs
        digitalWrite(whitePinLED, HIGH);
        
        digitalWrite(redPinLED, HIGH); //<--
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, LOW); 
        digitalWrite(greenPinLED, HIGH); //<--
        digitalWrite(bluePinLED, HIGH); //<--
        digitalWrite(pinkPinLED, LOW);
    break;
    case 3:
        //Lamp
        colorWipe(strip.Color(255, 255, 255), 1);  // -weiß + Block
        digitalWrite(blockPinLED, HIGH);
        wOutputLED = HIGH;

        //LEDs
        digitalWrite(whitePinLED, HIGH);
        
        digitalWrite(redPinLED, HIGH); //<--
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, HIGH); //<-- 
        digitalWrite(greenPinLED, HIGH); //<--
        digitalWrite(bluePinLED, HIGH); //<--
        digitalWrite(pinkPinLED, LOW);
    break;
    case 4:
        //Lamp
        colorWipe(strip.Color(255, 200, 80), 1);  // -warmes weiß
        digitalWrite(blockPinLED, LOW);
        wOutputLED = HIGH;

        //LEDs
        digitalWrite(whitePinLED, HIGH);
        
        digitalWrite(redPinLED, HIGH); //<--
        digitalWrite(orangePinLED, HIGH); //<--
        digitalWrite(yellowPinLED, LOW); 
        digitalWrite(greenPinLED, HIGH); //<--
        digitalWrite(bluePinLED, HIGH); //<--
        digitalWrite(pinkPinLED, LOW);
    break;
    case 5:
        //Lamp
        colorWipe(strip.Color(255, 200, 80), 1);  // -warmes weiß + block
        digitalWrite(blockPinLED, HIGH);
        wOutputLED = HIGH;

        //LEDs
        digitalWrite(whitePinLED, HIGH);
        
        digitalWrite(redPinLED, HIGH);
        digitalWrite(orangePinLED, HIGH);
        digitalWrite(yellowPinLED, HIGH); //<--
        digitalWrite(greenPinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
        digitalWrite(pinkPinLED, LOW);
    break;
  }

  return wOutputLED;
}

/**
 * Button 2: color light
 */
int colorShow(int i) {
  int statusData = HIGH;
  switch(i){
    
    //------------------------------ off ------------------------------------
    case 0:
        digitalWrite(blockPinLED, LOW);
        colorWipe(strip.Color(255, 0, 80), 10);    // pink

        //-->o<--
        digitalWrite(orangePinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
        delay(delayTime);
            
        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
        delay(delayTime);
            
        rainbowCycle(50);
        colorWipe(strip.Color(0, 0, 0), 10);    // Black/off
            
            
        //<--o-->
        digitalWrite(yellowPinLED, LOW);
        digitalWrite(greenPinLED, LOW);
        delay(delayTime2);

        digitalWrite(orangePinLED, LOW);
        digitalWrite(bluePinLED, LOW);
        delay(delayTime2);
            
        digitalWrite(redPinLED, LOW);
        digitalWrite(pinkPinLED, LOW);
        delay(delayTime2);  

        //-->o<--
        digitalWrite(redPinLED, HIGH);
        digitalWrite(pinkPinLED, HIGH);
        delay(delayTime2);
        digitalWrite(redPinLED, LOW);
        digitalWrite(pinkPinLED, LOW);
        delay(delayTime);

        digitalWrite(orangePinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
        delay(delayTime2);
        digitalWrite(bluePinLED, LOW);
        digitalWrite(orangePinLED, LOW);
        delay(delayTime);

        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
        delay(delayTime2);
        digitalWrite(yellowPinLED, LOW);
        digitalWrite(greenPinLED, LOW);
        delay(delayTime);

        // o o o o o o
        digitalWrite(pinkPinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(orangePinLED, HIGH);
        delay(delayTime);
            
        //standard LED on
        delay(delayTime);
        digitalWrite(redPinLED, HIGH);
        delay(delayTime2);
        delay(delayTime);
        digitalWrite(whitePinLED, HIGH);
        delay(delayTime2);
        delay(delayTime);
            
        //all - off
        digitalWrite(pinkPinLED, LOW);
        delay(delayTime);
        digitalWrite(bluePinLED, LOW);
        delay(delayTime);
        digitalWrite(greenPinLED, LOW);
        delay(delayTime);
        digitalWrite(yellowPinLED, LOW);
        delay(delayTime);
        digitalWrite(orangePinLED, LOW);
        delay(delayTime);

        statusData = LOW;
    break;

    //-------------------------------- rot ----------------------------------
    case 1:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 0), 1);  // red
        digitalWrite(redPinLED, HIGH);
    break;

    case 2:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 40, 0), 1);  // red - orange
        digitalWrite(redPinLED, HIGH);
        digitalWrite(orangePinLED, HIGH);
    break;
    
    //------------------------------ orange ---------------------------------

    case 3:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 80, 0), 1);  // orange
        digitalWrite(redPinLED, LOW);
        digitalWrite(orangePinLED, HIGH);
    break;

    case 4:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 130, 0), 1);  // orange - yellow
        digitalWrite(orangePinLED, HIGH);
        digitalWrite(yellowPinLED, HIGH);
    break;
    
    //------------------------------ yellow ---------------------------------       

    case 5:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 160, 0), 1);  // yellow
        digitalWrite(orangePinLED, LOW);
        digitalWrite(yellowPinLED, HIGH);
    break;

    case 6:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(80, 255, 0), 1);  // yellow - green
        digitalWrite(yellowPinLED, HIGH);
        digitalWrite(greenPinLED, HIGH);
    break;
    
    //------------------------------ green ----------------------------------      

    case 7:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 255, 0), 1);  // green
        digitalWrite(yellowPinLED, LOW);
        digitalWrite(greenPinLED, HIGH);
    break;

    case 8:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 255, 255), 1);  // green - blue / türkies
        digitalWrite(greenPinLED, HIGH);
        digitalWrite(bluePinLED, HIGH);
    break;
    
    //------------------------------ blue -----------------------------------     

    case 9:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(0, 0, 255), 1);  // blue
        digitalWrite(greenPinLED, LOW);
        digitalWrite(bluePinLED, HIGH);            
    break;

    case 10: 
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(30, 0, 255), 1);  // lila
        digitalWrite(bluePinLED, HIGH);
        digitalWrite(pinkPinLED, HIGH);    
    break;
    
    //------------------------------ pink -----------------------------------

    case 11:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 255), 1);  // pink
        digitalWrite(bluePinLED, LOW);
        digitalWrite(pinkPinLED, HIGH);
    break;

    case 12:
        digitalWrite(blockPinLED, LOW);
        digitalWrite(whitePinLED, LOW);
        colorWipe(strip.Color(255, 0, 80), 1);  // pinker
        digitalWrite(pinkPinLED, HIGH);
        digitalWrite(redPinLED, HIGH);
    break;
  }

  return statusData;
}


/**
 * Unit Pixel
 */
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

/**
 * Test Rainbow
 */
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
