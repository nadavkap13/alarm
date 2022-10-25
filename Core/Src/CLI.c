#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "CLI.h"
#include "mybuzzer.h"
#include "new_button.h"
#include "LED.h"
#include "comtask.h"
#include "mymain.h"
#include "main.h"
#include "Alarm.h"

extern LED led;
extern BUZZER buzzer;
extern int length[];
extern int song[];
//extern ALARM ALARMS[32];
void cmdAlarm_Name(void* obj,char* params)
{
	ALARM* alarm = (ALARM*)obj;
	Alarm_Name(alarm, params);
}

void initCLI()
{
//	RegisterCommand("name",cmdAlarm_Name,);
//	RegisterCommand("Repetition",cmdLedon,&ledblue);
//	RegisterCommand("Tone",cmdLedon,&ledblue);
//	RegisterCommand("Snooze",cmdLedon,&ledblue);


}

