#ifndef INC_COMTASK_H_
#define INC_COMTASK_H_
#include <stdint.h>

typedef void (*HandlerFunc)(void*,char*);
typedef struct _function{
	char* CommandName;
	HandlerFunc Func;
	void* obj;
}Function;
extern Function arry[100];

int commTask();
void handleCommand();

#endif /* INC_COMTASK_H_ */
