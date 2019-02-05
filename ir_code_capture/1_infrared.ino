
//  infrared checker -----------------------------------------------

static unsigned int LongPushCounter;
static unsigned long CurrentValue;
static boolean EdgeTriggerSwitch;
static boolean InfraredFlag;
static boolean DirectSwitch;

void infrared_checker ( void )
{
  if ( irrecv.decode ( &results ) )
  {
    if ( results.decode_type == NEC )
    {
      if ( results.value == REPEAT ) LongPushCounter++;
      else CurrentValue = results.value;
    }
    InfraredFlag = true; 
    irrecv.resume();
  }
  if ( LongPushCounter ) DirectSwitch = true;
  else DirectSwitch = false;
  if ( DirectSwitch ) resets_release_timer();
  edge_trigger_switch();
}

void edge_trigger_switch( void )
{
  static bool PrevDirectSwitch;
  EdgeTriggerSwitch = DirectSwitch ^ PrevDirectSwitch & DirectSwitch;
  PrevDirectSwitch = DirectSwitch;
}

static unsigned long ReleaseCounter;
static unsigned long LongPushCounter0;
static boolean ReleaseFlag;

void release_timer ( void )
{
  static unsigned long previousMillis;
  unsigned long currentMillis = millis();
  if ( DirectSwitch == false )
  {
    if ( currentMillis - previousMillis > 20 )
    {
      previousMillis = currentMillis;
      if ( ReleaseFlag ) return;
      if ( ReleaseCounter == 1 ) LongPushCounter = 0;
      if ( ReleaseCounter ) ReleaseCounter--;
      else { ReleaseFlag = true; EventID = EVENT0; }
    }
  } else resets_release_timer();
}

void resets_release_timer ( void )
{
  ReleaseFlag = false;
  ReleaseCounter = 50;
}

void long_push_timer ( void )
{
  static unsigned long pms, cms; cms = millis();
  if ( cms - pms < 100 ) return; else pms = cms;
  if ( !InfraredFlag ) LongPushCounter = 0;
  if ( LongPushCounter >= 20 ) {
    ReleaseCounter = LongPushCounter = 0;
    software_reset();
  }
  InfraredFlag = false;
}

void software_reset() {
  lcd.clear(); delay( 1000 );
  asm volatile ("jmp 0");  
}
