#include "comtask.h"
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmsis_os.h"
#include "mymain.h"
#include "Rtc.h"
#include "Alarm.h"

#define MAX_BUFFER_LENGTH 100
uint8_t cmdbuffer[MAX_BUFFER_LENGTH];
int cmdcount = 0;
int cmdprint = 0;
extern  UART_HandleTypeDef huart2;
extern int alarm_on;
extern Rtc rtc;
extern DateTime dateTime2;
extern ALARM ALARMS_check[32];
int funcounter = 0;

void RegisterCommand(char *CommandName, HandlerFunc Func, void *obj) {
	arry[funcounter].Func = Func;
	arry[funcounter].CommandName = CommandName;
	arry[funcounter].obj = obj;
	funcounter++;
}

int commTask() {
	uint8_t ch;

	HAL_StatusTypeDef Status = HAL_UART_Receive(&huart2, &ch, 1, 10);
	if (Status != HAL_OK) {
		if ((huart2.Instance->ISR & USART_ISR_ORE) != 0) {
			__HAL_UART_CLEAR_OREFLAG(&huart2);
		}

		// here we have a time to print the command
		while (cmdprint < cmdcount) {
			HAL_UART_Transmit(&huart2, &cmdbuffer[cmdprint++], 1, 0xFFFF);
		}

		return 0;
	}

	if (ch != '\r' && ch != '\n') {
		//HAL_UART_Transmit(&huart2, &ch, 1, 0xFFFF);

		if (cmdcount >= MAX_BUFFER_LENGTH) {
			cmdcount = 0;
			cmdprint = 0;
		}

		cmdbuffer[cmdcount++] = ch;
		return 0;
	}

	// here we have a time to print the command
	while (cmdprint < cmdcount) {
		HAL_UART_Transmit(&huart2, &cmdbuffer[cmdprint++], 1, 0xFFFF);
	}

	HAL_UART_Transmit(&huart2, (uint8_t*) "\r\n", 2, 0xFFFF);

	cmdbuffer[cmdcount] = 0;
	cmdcount = 0;
	cmdprint = 0;
	return 1;
}

void handleCommand() {
	char cmd[20];
	char param[30];

	int params = sscanf((const char*) cmdbuffer, "%s %s", cmd, param);

		for (int j = 0; j < funcounter; j++) {
			if (strcmp(cmd, arry[j].CommandName) == 0) {
				arry[j].Func(arry[j].obj, param);
				return;
			}
		}

	if (params == 0) {
		return;
	}

	 if (strcmp(cmd, "stop") == 0)
	 {
		 alarm_on = 0;
	 }
	 else if (strcmp(cmd, "list") == 0)
		 	 {
		 ALARM *alarm = (ALARM*) (0x08080000UL );
		 ALARMS_check[0] = *alarm;
		 	 }
	 else if (strcmp(cmd, "create") == 0)
	 	 {
		 create_alarm(param);
	 	 }
	 else if (strcmp(cmd, "gettime") == 0)
	 	 	 {
		 rtcGetTime(&rtc,&dateTime2);
		 printf("date is %02d:%02d:%02d  %02d %02d/%02d/%02d \r\n ",dateTime2.hours,dateTime2.min,dateTime2.sec,dateTime2.weekDay,dateTime2.day,dateTime2.month,dateTime2.year);
	 	 	 }
	else {
		printf("Invalid command\r\n");
	}
}
