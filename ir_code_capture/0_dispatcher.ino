// event dispatcher.

#define   EVENT0        0       // _00()
#define   EVENT1        1       // _01()
#define   EVENT2        2       // _02()
#define   EVENT3        3       // _03()
#define   EVENT4        4       // _04()
#define   EVENT5        5       // _05()
#define   EVENT6        6       // _06()
#define   EVENT7        7       // _07()
#define   EVENT8        8       // _08()
#define   EVENT9        9       // _09()

static uint8_t EventID;
void ( *event[] )() = { _00,_01,_02,_03,_04,_05,_06,_07,_08,_09 };
void event_dispatcher( void ) { (*event[ EventID ])(); }

#define ON  true
#define OFF false
