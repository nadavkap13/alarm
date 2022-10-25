#ifndef INC_MYMAIN_H_
#define INC_MYMAIN_H_
#include "main.h"

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim3;
extern int song[];
extern int length[];
extern I2C_HandleTypeDef hi2c1;


int _write(int fd, char* ptr, int len);
int mymaininit();
void main_menu();
void create_alarm(char param[30]);
void edit_alarm();
void delete_alarm();
void flashtoarry();
#endif /* INC_MYMAIN_H_ */
