#include <stdio.h>
#include "Alarm.h"
#include "Rtc.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Flash.h"

#define ALARM_MAX 32
ALARM ALARMS[ALARM_MAX];
int alarmcount = 0;

void Alarm_Create(char name[20] , DateTime * datetime)
{
	if(alarmcount == 0){
		strcpy(ALARMS[alarmcount].name ,name);
		ALARMS[alarmcount].datetime.sec = 0;
		ALARMS[alarmcount].datetime.min = datetime->min;
		ALARMS[alarmcount].datetime.hours = datetime->hours;
		ALARMS[alarmcount].datetime.weekDay =0;
		ALARMS[alarmcount].datetime.day = datetime->day;
		ALARMS[alarmcount].datetime.month = datetime->month;
		ALARMS[alarmcount].datetime.year = datetime->year;
		ALARMS[alarmcount].isfull=0;
		alarmcount++;
		pageErase ();
		pageProgram ();
		return;
	}

	 if (alarmcount == ALARM_MAX){
		 printf("Cant add anymore alarms pls try again later \r\n");
		 return;
	 }


//	for(int i=0;i<sizeof(ALARMS);i++){
//	   	if (Alarm_Time_Compare(i,datetime) == 1){
//	   		for(int j=sizeof(ALARMS);j>i+1;j--){
//	   			ALARMS[j] = ALARMS[j--];
//	   		}
//	   	}
			strcpy(ALARMS[alarmcount].name ,name);
			ALARMS[alarmcount].datetime.min = datetime->min;
			ALARMS[alarmcount].datetime.hours = datetime->hours;
			ALARMS[alarmcount].datetime.weekDay = datetime->weekDay;
			ALARMS[alarmcount].datetime.day = datetime->day;
			ALARMS[alarmcount].datetime.month = datetime->month;
			ALARMS[alarmcount].datetime.year = datetime->year;
			ALARMS[alarmcount].isfull++;
			alarmcount++;
//			break;
//		}
	 pageErase ();
	 pageProgram ();
}
void Alarm_Name(ALARM * alarm, char name[20])
{
	strcpy(ALARMS[alarmcount].name ,name);
	pageErase ();
	pageProgram ();
}
void Alarm_Datetime( ALARM * alarm, DateTime * datetime)
{
    alarm->datetime.min = datetime->min;
    alarm->datetime.hours = datetime->hours;
    alarm->datetime.weekDay = datetime->weekDay;
    alarm->datetime.day = datetime->day;
    alarm->datetime.month = datetime->month;
    alarm->datetime.year = datetime->year;
    pageErase ();
    pageProgram ();
}
void Alarm_Repetition(ALARM * alarm,int Repetition){
	alarm->Repetition = Repetition;
	pageErase ();
	pageProgram ();
}
void Alarm_Tone(ALARM * alarm,int Tone)
{
	alarm->Tone = Tone;
	pageErase ();
	pageProgram ();
}
void Alarm_Snooze_count(ALARM * alarm,int Snooze_count )
{
	alarm->Snooze_count = Snooze_count;
	pageErase ();
	pageProgram ();
}

int Alarm_Time_Compare(int location ,DateTime * datetime)
{
	if (ALARMS[location].datetime.min < datetime->min){
		if (ALARMS[location].datetime.hours < datetime->hours){
			if (ALARMS[location].datetime.weekDay < datetime->weekDay){
				if (ALARMS[location].datetime.day < datetime->day){
					if (ALARMS[location].datetime.month < datetime->month){
						if (ALARMS[location].datetime.year < datetime->year)
							return 1;
					}
				}
			}
		}
	}
	return 0;
}
void Alarm_Delete(char name[20])
{
	for(int i=0;i<sizeof(ALARMS);i++){
		if(strcmp(ALARMS[i].name , name)==0){
			for(int j=i;i<sizeof(ALARMS);i++){
				ALARMS[j] = ALARMS[j++];
			}
				alarmcount--;
				break;
		}
		 printf("ther is no alarm with the name: %s \r\n", name);
	}

	pageErase ();
	pageProgram ();

}
void Alarm_Delete_All()
{
	pageErase ();
}
void Alarm_List()
{
	for(int i=0;i<alarmcount;i++){
		printf("alarm name is %s",ALARMS[i].name);
	}
}
