/*

 Basic Sketch To Control a 74HC595.
 Using the OE and SRCLR pins.
 http://rheingoldheavy.com/shift-register-circuit-build-102/
 
 */

// Set the pin connections from the shift register
int clearPin   = 2;
int enablePin  = 3;
int dataPin    = 4;
int latchPin   = 5;
int clockPin   = 6;

// Create a variable to hold the 8-bit pattern for the leds
byte leds      = 0;

void setup() 
{
  pinMode(latchPin,   OUTPUT);
  pinMode(dataPin,    OUTPUT);  
  pinMode(clockPin,   OUTPUT);
  pinMode(clearPin,   OUTPUT);
  pinMode(enablePin,  OUTPUT);

  digitalWrite(enablePin,  LOW);
  digitalWrite(clearPin,   HIGH);
}


void loop() 
{

  // Blink the display three times using SRCLR pin
  for (int i = 1; i < 4; i++) 
  {
    leds = 255;
    refreshShiftRegister();
    delay(250);

    clearShiftRegister();
    delay(250);
  }

  // Turn all the LEDs on so they can be faded
  leds = 255;
  refreshShiftRegister();

  // Fade the LEDs by using PWM on the OE pin
  int x = 1;
  for (int j = 0; j > -1; j = j + x)
  {
    analogWrite(enablePin, j);
    if (j == 255) x = -1; 
    delay(10);
  } 

  digitalWrite  (enablePin, LOW);

}

void refreshShiftRegister()
{
  digitalWrite  (latchPin, LOW);
  shiftOut      (dataPin, clockPin, MSBFIRST, leds);
  digitalWrite  (latchPin, HIGH);
}

void clearShiftRegister()
{
  digitalWrite  (latchPin, LOW);
  digitalWrite  (clearPin, LOW);
  digitalWrite  (latchPin, HIGH);
  digitalWrite  (clearPin, HIGH);
}

