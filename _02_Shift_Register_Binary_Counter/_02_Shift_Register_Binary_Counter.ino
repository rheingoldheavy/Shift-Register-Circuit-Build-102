/*

Basic Sketch To Control a 74HC595.
The Binary Counter
http://rheingoldheavy.com/shift-register-circuit-build-102/
 
*/

// Set the pin connections from the shift register
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
}


void loop() 
{

  for (byte i = 0; i < 255; i++)        // Decimal Counter
  {
    leds                  = i;
    refreshShiftRegister  ();
    delay                 (500);
  }

  /*
  for (byte i = 0; i < B11111111; i++)  // Binary Counter
  {
    leds                  = i;
    refreshShiftRegister  ();
    delay                 (500);
  }


  for (byte i = 0; i < 0xFF; i++)       // Hexadecimal Counter
  {
    leds                  = i;
    refreshShiftRegister  ();
    delay                 (500);
  }
  */

}

void refreshShiftRegister()
{
  digitalWrite  (latchPin, LOW);
  shiftOut      (dataPin, clockPin, MSBFIRST, leds);
  digitalWrite  (latchPin, HIGH);
}

