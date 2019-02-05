
// event listener

void _00( void ) { moves(); }
void _01( void ) { moves(); }
void _02( void ) { moves(); }
void _03( void ) { moves(); }
void _04( void ) { moves(); }
void _05( void ) { moves(); }
void _06( void ) { moves(); }
void _07( void ) { moves(); }
void _08( void ) { moves(); }
void _09( void ) { moves(); }

void moves( void ) {
  if ( EdgeTriggerSwitch ) EventID++;
  if ( EventID > EVENT9 ) EventID = EVENT0;
}
