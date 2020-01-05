#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#define FASTLED_ESP8266_D1_PIN_ORDER

#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    4
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

CRGB leds[NUM_LEDS];

DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
  0,     0,  0,  0,   //black
128,   255,  0,  0,   //red
224,   255,255,  0,   //bright yellow
255,   255,255,255 }; //full white

CRGBPalette16 currentPalette;
boolean isBlack;
short serialData;

void setup() {
  Serial.begin (115200);
  Serial.println("Iniciando Programa");
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );  
  isBlack = true;
  currentPalette = heatmap_gp;
  serialData = 0;
}

void loop(){
  //choosePalette();
  updateLeds();
  FastLED.show();
  FastLED.delay(3000);
}

void choosePalette() {      
  serialData++;
  
  if(serialData == 9) serialData = 0;
  
  switch (serialData) {
    case 1:
      currentPalette = CloudColors_p; break;
    case 2:
      currentPalette = LavaColors_p; break;
    case 3:
      currentPalette = OceanColors_p; break;
    case 4:
      currentPalette = ForestColors_p; break;
    case 5:
      currentPalette = RainbowColors_p; break;
    case 6:
      currentPalette = RainbowStripeColors_p; break;
    case 7:
      currentPalette = PartyColors_p; break;
    case 8:
      currentPalette = HeatColors_p; break;
    default:
      currentPalette = heatmap_gp; break;
      break;
  }
  Serial.println(serialData);
}

void updateLeds() {
  uint8_t colorIndex = 1;
  /*
  if(isBlack) {
    currentPalette = heatmap_gp;
    for( int i = 0; i < NUM_LEDS; i++) {
      leds[i] = ColorFromPalette( currentPalette, 0);
    }
  } else {
    */     
     String a = "f5dd12";
     int number = (int)strtol(a.c_str(), NULL, 16);
    for( int i = 0; i < NUM_LEDS; i++) {
      leds[i] = number;
      //leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, LINEARBLEND);
      colorIndex += 3;
    }
  //}
  isBlack = !isBlack;   
}

