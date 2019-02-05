// infrared Radiation Code Capture.

// 1602A Liquid Crystal Display ( https://github.com/johnrickman/LiquidCrystal_I2C )
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd( 0x27,16,2 );

// VS1838 infrared radiation receiver ( https://github.com/z3t0/Arduino-IRremote )
#include <IRremote.h>
#define RECV_PIN 12 
IRrecv irrecv( RECV_PIN );
decode_results results;

void setup( void ) {
  lcd.init();
  lcd.backlight();
  irrecv.enableIRIn();
}

void loop( void ) {
  infrared_checker();
  long_push_timer();
  release_timer();
  event_dispatcher();
  display_value();
}
