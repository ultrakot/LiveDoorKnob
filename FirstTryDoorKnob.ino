
#include <Adafruit_NeoPixel.h>

#define NEONPIXELPIN            3


#define NUMPIXELS               64


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEONPIXELPIN, NEO_GRB + NEO_KHZ800);


const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

 int HeartPixels[] = {1, 5, 8, 10, 12, 14, 16, 19, 22, 24, 30, 33, 37, 42, 44, 51};

void setup()
{
   pixels.begin(); // This initializes the NeoPixel library.
   
  //knock sensor
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
  

}

void loop() 
{
  //knock sensor 
  // read the sensor and store it in the variable sensorReading:
   sensorReading = analogRead(knockSensor);


  // if the sensor reading is greater than the threshold:
   if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
    Serial.println(sensorReading);

    //NeoPixel 
     for(int i=0;i<NUMPIXELS ;i++)
    {
       // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
         // pixels.setPixelColor(i, pixels.Color(3,15,40)); // Moderately bright green color.
        ///pixels.show(); // This sends the updated pixel color to the hardware.
       //delay(delayval);
    }
  
  }
  
  delay(100);  // delay to avoid overloading the serial port buffer

    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.show(); 
    pixels.setPixelColor(1, pixels.Color(13,0,13));
    pixels.setPixelColor(5, pixels.Color(13,0,13));
    pixels.setPixelColor(8, pixels.Color(8,0,8));
    pixels.setPixelColor(10, pixels.Color(8,0,8));
    pixels.setPixelColor(12, pixels.Color(8,0,8));
    pixels.setPixelColor(14, pixels.Color(8,0,8));
    pixels.setPixelColor(16, pixels.Color(8,0,8));
    pixels.setPixelColor(19, pixels.Color(8,0,8));
    pixels.setPixelColor(22, pixels.Color(8,0,8));
    pixels.setPixelColor(24, pixels.Color(8,0,8));
    pixels.setPixelColor(30, pixels.Color(8,0,8));
    pixels.setPixelColor(33, pixels.Color(8,0,8));
    pixels.setPixelColor(37, pixels.Color(8,0,8));
    pixels.setPixelColor(42, pixels.Color(8,0,8));
    pixels.setPixelColor(44, pixels.Color(8,0,8));
    pixels.setPixelColor(51, pixels.Color(8,0,8));

    for (int i = 0; i < sizeof(HeartPixels); i = i + 1) {
         //pixels.setPixelColor(HeartPixels[i], pixels.Color(8,0,8));
       
    }

    

    
    pixels.show(); 

}
