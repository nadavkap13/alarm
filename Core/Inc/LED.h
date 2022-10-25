#ifndef INC_LED_H_
#define INC_LED_H_

typedef struct LED{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	int delay;

}LED;

void led_init(LED* led,GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,int num);

#endif /* INC_LED_H_ */
