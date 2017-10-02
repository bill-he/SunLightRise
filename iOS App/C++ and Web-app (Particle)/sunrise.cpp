// This #include statement was automatically added by the Particle IDE.
#include <SparkJson.h>
#include <neopixel.h>
#include <string>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 80
#define PIXEL_PIN D0
#define PIXEL_TYPE SK6812RGBW
#define OFFSET 12

// GRBW

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// int led1 = D0;
// int led2 = D7;
String logger;
String command;
bool hasChanged;
float brightness = 100.00;
// long milliseconds;

int a[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
  10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
  17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
  37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
  51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
  69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
  90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255};

void setup()
{
    // // milliseconds = millis();
    strip.begin();
    strip.show();
    Particle.function("led", changeMode);
    Particle.variable("logger", &logger, STRING);
    Particle.function("brightness", changeBrightness);

    // pinMode(led1, OUTPUT);
    // pinMode(led2, OUTPUT);
    // digitalWrite(led1, LOW);
    // digitalWrite(D7, LOW);
    
    // logger = Time.timeStr();
    Time.zone(-4);
}

int changeBrightness(String arg) {
    brightness = arg.toFloat();
}

// function that the particle calls to change mode
int changeMode(String arg)
{
    // change mode (if you call update time multiple times, it doesn't change)
    if (command == "updatetime" && arg == "settime") {
        command = "updatetime";
    } else if (command != arg) {
        hasChanged = true;
        command = arg;
    }

    // flash D7 (onboard Photon LED) to indicate completion
    // digitalWrite(led1, HIGH);
    // digitalWrite(led2, HIGH);
    delay(90);
    // digitalWrite(led1, LOW);
    // digitalWrite(led2, LOW);

    return 1;
}

// loop of all the states (evoking the appropriate ones)
void loop()
{
    if (command == "settime") {
        time(true);
        if (hasChanged) { hasChanged = false; return;}
        command = "updatetime";
    }
    else if (command == "updatetime") {
        time(false);
        if (hasChanged) { hasChanged = false; return;}
    }
    else if (command == "hour") {
        hour(); // Red
    }
    else if (command == "minute") {
        minute(); // Red
    }
    else if (command == "green") {
        colorWipe(strip.Color(255, 0, 0), 50); // Green
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "red") {
        colorWipe(strip.Color(0, 255, 0), 50); // Red
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "blue") {
        colorWipe(strip.Color(0, 0, 255), 50); // Blue
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "white") {
        colorWipe(strip.Color(0, 0, 0, 255), 50); // White
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "whitecolor") {
        whiteOverRainbow(20, 75, 5);
        if (hasChanged) { hasChanged = false; return;}
        rainbowCycle(5);
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "pulse") {
        pulseWhite(5);
        if (hasChanged) { hasChanged = false; return;}
        command = "updatetime";
    }
    else if (command == "sunrise") {
        sunrise(50);
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "fullWhite") {
        fullWhite();
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "rainbowfade") {
        rainbowFade2White(3, 3, 1);
        if (hasChanged) { hasChanged = false; return;}
        command = "settime";
    }
    else if (command == "rainbowcycle") {
        rainbowCycle(5);
        if (hasChanged) { hasChanged = false; return;}
        command = "updatetime";
    }
    else if (command == "demo") 
    {
        // Some example procedures showing how to display to the pixels:
        colorWipe(strip.Color(255, 0, 0), 50); // Green
        if (hasChanged) { hasChanged = false; return;}
        colorWipe(strip.Color(0, 255, 0), 50); // Red
        if (hasChanged) { hasChanged = false; return;}
        colorWipe(strip.Color(0, 0, 255), 50); // Blue
        if (hasChanged) { hasChanged = false; return;}
        colorWipe(strip.Color(0, 0, 0, 255), 50); // White
        if (hasChanged) { hasChanged = false; return;}
        whiteOverRainbow(20, 75, 5);
        if (hasChanged) { hasChanged = false; return;}
        pulseWhite(5);
        if (hasChanged) { hasChanged = false; return;}
        rainbowFade2White(3, 3, 1);
        if (hasChanged) { hasChanged = false; return;}
        command = "updatetime";
    } else {
        command = "updatetime";
    }
}

// setting/updating the time
void time(bool isSet) {
    double hour = (double) Time.hour();
    double minute = (double) Time.minute();
    double second = (double) Time.second();
    double ms = (double) Time.second();
    
    if (hour >= 12) hour = hour - 12;
    
    int hourHand = (int) ((hour +  ((double) minute / 60))/12 * strip.numPixels()) + OFFSET;
    if (hourHand >= strip.numPixels()) hourHand -= strip.numPixels();
    
    int minuteHand = (int) (((double) minute/60) * strip.numPixels()) + OFFSET;
    if (minuteHand >= strip.numPixels()) minuteHand -= strip.numPixels();
    
    int secondHand = (int) (((double) second/60) * strip.numPixels());
    if (secondHand >= strip.numPixels()) secondHand -= strip.numPixels();
    
    for (int j = hourHand-1; j < hourHand+2; j++) {
        int i = j;
        if (i >= strip.numPixels()) i -= strip.numPixels();
        strip.setPixelColor(i, strip.Color((int) ((255 *brightness)/100), (int) ((255 *brightness)/100), (int) ((255 *brightness)/100), (int) ((255 *brightness)/100)));
        if (isSet) delay(30);
        if (isSet) strip.show();
        if (hasChanged) return;
    }
    
    uint32_t color = strip.Color(0, 0, (int) ((255 *brightness)/100), 0);
    for (int j = hourHand+2; j < strip.numPixels() + hourHand-1; j++) {
        int i = j;
        if (i >= strip.numPixels()) i = i - strip.numPixels();
        strip.setPixelColor(i, color);
        if (isSet) strip.show();
        if (isSet) delay(30);
        if (i == minuteHand) color = strip.Color(0, (int) ((255 *brightness)/100), 0, 0);
        if (hasChanged) return;
    }
    
    
    strip.setPixelColor(secondHand + 0, strip.Color((int) ((255 *brightness)/100), 0, 0, 0));
    
    strip.show();
}

// getting the hour
void hour()
{
    int hour = Time.hour();
    for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(0, 0, 0, 0));
    }
    
    for (int j = 40; j < hour+40; j++) {
        if (j >= strip.numPixels()) {
            j -= strip.numPixels();
        }
        strip.setPixelColor(j, strip.Color((int) ((255 *brightness)/100), 0, 0, 0));
    }
    strip.show();
}

// get the minute
void minute()
{
    int minute = Time.minute();
    for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(0, 0, 0, 0));
    }
    
    for (int j = 40; j < minute+40; j++) {
        if (j >= strip.numPixels()) {
            j -= strip.numPixels();
        }
        strip.setPixelColor(j, strip.Color((int) ((255 *brightness)/100), 0, 0, 0));
    }
    strip.show();
}

// pulse a full white brightness
void pulseWhite(uint8_t wait)
{
    for (int j = 0; j < 256; j++) {
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0, 0, 0, (int) ((a[j] *brightness)/100)));
        }
        if (hasChanged) return;
        delay(wait);
        strip.show();
    }

    for (int j = 255; j >= 0; j--) {
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0, 0, 0, (int) ((a[j] *brightness)/100)));
        }
        if (hasChanged) return;
        delay(wait);
        strip.show();
    }
}

// simulate sunrise (so far the same code as pulseWhite)
void sunrise(uint8_t wait)
{
    for (int j = 0; j < 256; j++) {
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color((int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100)));
        }
        
        if (hasChanged) return;
        delay(wait);
        strip.show();
    }
    
    for (int j = 0; j < 20000; j++) {
        if (hasChanged) return;
        delay(10);
    }

    for (int j = 255; j >= 0; j--) {
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color((int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100), (int) ((a[j] *brightness)/100)));
        }
        if (hasChanged) return;
        delay(wait);
        strip.show();
    }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait)
{
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        if (hasChanged) return;
        strip.show();
        delay(wait);
    }
}

// create white strips over rainbow patterns
void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength)
{

    if (whiteLength >= strip.numPixels())
        whiteLength = strip.numPixels() - 1;

    int head = whiteLength - 1;
    int tail = 0;

    int loops = 3;
    int loopNum = 0;

    static unsigned long lastTime = 0;

    while (true) {
        for (int j = 0; j < 256; j++) {
            for (uint16_t i = 0; i < strip.numPixels(); i++) {
                if ((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head)) {
                    strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
                }
                else {
                    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
                }
                
            }

            if (millis() - lastTime > whiteSpeed) {
                head++;
                tail++;
                if (head == strip.numPixels()) {
                    loopNum++;
                }
                lastTime = millis();
            }

            if (loopNum == loops)
                return;

            head %= strip.numPixels();
            tail %= strip.numPixels();
            if (hasChanged) return;
            strip.show();
            delay(wait);
        }
    }
}

//rainbow fades to white
void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops)
{
    float fadeMax = 100.0;
    int fadeVal = 0;
    uint32_t wheelVal;
    int redVal, greenVal, blueVal;

    for (int k = 0; k < rainbowLoops; k++) {

        for (int j = 0; j < 256; j++) { // 5 cycles of all colors on wheel

            for (int i = 0; i < strip.numPixels(); i++) {

                wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);

                redVal = red(wheelVal) * float(fadeVal / fadeMax);
                greenVal = green(wheelVal) * float(fadeVal / fadeMax);
                blueVal = blue(wheelVal) * float(fadeVal / fadeMax);

                strip.setPixelColor(i, strip.Color((int) ((redVal *brightness)/100), (int) ((greenVal *brightness)/100), (int) ((blueVal *brightness)/100)));
            }

            //First loop, fade in!
            if (k == 0 && fadeVal < fadeMax - 1) {
                fadeVal++;
            }

            //Last loop, fade out!
            else if (k == rainbowLoops - 1 && j > 255 - fadeMax) {
                fadeVal--;
            }

            if (hasChanged) return;
            strip.show();
            delay(wait);
        }
    }

    for (int j = 0; j < 10; j++) {
            delay(50);
            if (hasChanged) return;
        }

    for (int k = 0; k < whiteLoops; k++) {

        for (int j = 0; j < 256; j++) {

            for (uint16_t i = 0; i < strip.numPixels(); i++) {
                strip.setPixelColor(i, strip.Color(0, 0, 0, (int) ((a[j] *brightness)/100)));
            }
            if (hasChanged) return;
            strip.show();
        }

        for (int j = 0; j < 40; j++) {
            delay(50);
            if (hasChanged) return;
        }
        for (int j = 255; j >= 0; j--) {

            for (uint16_t i = 0; i < strip.numPixels(); i++) {
                strip.setPixelColor(i, strip.Color(0, 0, 0, (int) ((a[j] *brightness)/100)));
            }
            if (hasChanged) return;
            strip.show();
        }
    }

    delay(500);
}

// show full white
void fullWhite()
{

    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0, (int) ((255 *brightness)/100)));
    }
    if (hasChanged) return;
    strip.show();
}

// still need to TEST
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
        for (i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & ((int) ((255 *brightness)/100))));
        }
        if (hasChanged) return;
        strip.show();
        delay(wait);
    }
}

void rainbow(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256; j++) {
        for (i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel((i + j) & ((int) ((255 *brightness)/100))));
        }
        if (hasChanged) return;
        strip.show();
        delay(wait);
    }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
    }
    if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

uint8_t red(uint32_t c)
{
    return (c >> 8);
}
uint8_t green(uint32_t c)
{
    return (c >> 16);
}
uint8_t blue(uint32_t c)
{
    return (c);
}
