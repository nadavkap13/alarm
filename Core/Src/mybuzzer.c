#include <stdio.h>
#include "main.h"
#include "mybuzzer.h"

extern TIM_HandleTypeDef htim3;

void buzzerStartPlay(BUZZER* buzzer,int* song, int* frames)
{
	buzzer->frames = frames;
	buzzer->song = song;

}

















