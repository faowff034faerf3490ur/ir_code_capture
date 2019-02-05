// LCD display.

void display_value ( void )
{
  static unsigned long pms, cms; cms = millis();
  if ( cms - pms < 100 ) return; else  pms = cms;

  lcd.setCursor( 0, 0 ); lcd.print( DirectSwitch );
  lcd.setCursor( 3, 0 ); lcd.print( EdgeTriggerSwitch );
  lcd.setCursor( 6, 0 ); lcd.print( "[" ); lcd.print( EventID ); lcd.print( "]" );
  lcd.setCursor( 11,0 ); lcd.print( LongPushCounter );   lcd.print( "  " );
  lcd.setCursor( 14,0 ); lcd.print( ReleaseCounter );    lcd.print( "  " );
  lcd.setCursor( 0, 1 ); lcd.print( CurrentValue,HEX);   lcd.print( "  " );
  lcd.setCursor( 8, 1 ); lcd.print( results.value,HEX ); lcd.print( "  " );
}
