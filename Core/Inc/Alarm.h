#ifndef INC_ALARM_H_
#define INC_ALARM_H_
#include "Rtc.h"

typedef struct _ALARM{
	char name[20];
	DateTime datetime;
	int Repetition;
	int Tone;
	int Snooze_count;
	int isfull;

}ALARM;

void Alarm_Create(char name[20] , DateTime * datetime);
void Alarm_Name(ALARM * alarm, char name[20]);
void Alarm_Datetime( ALARM * alarm, DateTime * datetime);
void Alarm_Repetition(ALARM * alarm,int Repetition);
void Alarm_Tone(ALARM * alarm,int Tone);
void Alarm_Snooze_count(ALARM * alarm,int Snooze_count );
//void Alarm_Edit(ALARM * alarm);
void Alarm_Delete(char name[20]);
void Alarm_Delete_All();
void Alarm_List();
int Alarm_Time_Compare(int location,DateTime * datetime);

#endif /* INC_ALARM_H_ */
