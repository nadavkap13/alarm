#include "mymain.h"
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comtask.h"
#include "mybuzzer.h"
#include "cmsis_os.h"
#include "LED.h"
#include "Rtc.h"
#include "Flash.h"
#include "Alarm.h"

int count = 0;
BUZZER buzzer;
LED led;
Rtc rtc;
DateTime dateTime2;
Function arry[100];
int alarm_on = 0;
#define ALARM_MAX 32
extern ALARM ALARMS[ALARM_MAX];

int _write(int fd, char* ptr, int len)
{
      HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, HAL_MAX_DELAY);
      return len;
}
void main_menu()
{
	printf("Please enter one of the following Alarm commands: \r\n  "
				"1) create \r\n "
				"2) edit \r\n "
				"3) delete \r\n ");
}
void create_alarm(char param[30]){
	char datename[50];
	char temp_name[20];
	DateTime temp_datetime;
	char * token;
	char s[3] = ": -";
	printf("Please enter alarm name (no more than 20 ch) and the date in this format m:h:d:m:y \r\n");
	sscanf(param, "%s",datename);

	token = strtok(datename, s);
	strcpy(temp_name,token) ;

		token = strtok(NULL, s);
		temp_datetime.min = atoi(token);
		token = strtok(NULL, s);


		temp_datetime.hours = atoi(token);
		token = strtok(NULL, s);


		temp_datetime.day = atoi(token);
		token = strtok(NULL, s);


		temp_datetime.month = atoi(token);
		token = strtok(NULL, s);


		temp_datetime.year = atoi(token);
		token = strtok(NULL, s);

		Alarm_Create(temp_name ,&temp_datetime);
}

void edit_alarm();
void delete_alarm();

void flashtoarry()
{
	for(int i = 0; i<32; i++){
		ALARM * alarm = (ALARM *)(0x08081800UL+(sizeof(ALARM)*i));
		ALARMS[i] = *alarm;
	}


}
int mymaininit()
{
	flashtoarry();
	buzzerStartPlay(&buzzer, song, length);
	led_init(&led,LD2_GPIO_Port,LD2_Pin,500);
	rtcInit(&rtc, &hi2c1, 0xD0);
//	dateTime2.sec = 0;
//	dateTime2.min = 28;
//	dateTime2.hours = 20;
//	dateTime2.weekDay = 3;
//	dateTime2.day = 3;
//	dateTime2.month = 10;
//	dateTime2.year = 22;
//	rtcSetTime(&rtc, &dateTime2 );

	return 0;
}

void led_func(void *argument)
{
 /* USER CODE BEGIN LED_blink */
	LED *led = (LED*)(argument);
  /* Infinite loop */
  for(;;)
  {
	  if(alarm_on == 1 ){
		  HAL_GPIO_TogglePin(led->GPIOx, led->GPIO_Pin);
		  osDelay(led->delay);
	  }
  }
  /* USER CODE END LED_blink */
}
void comtask_func(void *argument)
{
  /* USER CODE BEGIN comtask_func */

  /* Infinite loop */
  for(;;)
  {

	  if (commTask()){
	  		 handleCommand();
	  	}
  }
  /* USER CODE END comtask_func */
}
void buzzer_func(void *argument)
{
	 if(alarm_on == 1 ){
	buzzer.song = song;
	buzzer.frames = length;
	__HAL_TIM_SET_AUTORELOAD(&htim3,buzzer.song[count]/2);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,((buzzer.song[count]/2)/2));
	HAL_TIM_Base_Start(&htim3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	 }
  /* Infinite loop */
  for(;;)
  {
	  if(alarm_on == 1 ){
		__HAL_TIM_SET_AUTORELOAD(&htim3,buzzer.song[count]/2);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,((buzzer.song[count]/2)/2));
		HAL_TIM_Base_Start(&htim3);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
		osDelay(buzzer.frames[count++]);
	  }
  }
  /* USER CODE END buzzer_func */
}
void alarm_func(void *argument)
{
  /* USER CODE BEGIN alarm_func */
  /* Infinite loop */
  for(;;)
  {


	  rtcGetTime(&rtc,&dateTime2);
	//  printf("date is %d:%d:%d:%d:%d:%d:%d \r\n ",dateTime2.sec,dateTime2.min,dateTime2.hours,dateTime2.weekDay,dateTime2.day,dateTime2.month,dateTime2.year);
	 if(dateTime2.min == ALARMS[0].datetime.min && dateTime2.hours == ALARMS[0].datetime.hours){

		 alarm_on = 1;
		// printf("alarm: %s is on! \r\n ", ALARMS[0].name);
	 }
    osDelay(1000);
  }
  /* USER CODE END alarm_func */
}

