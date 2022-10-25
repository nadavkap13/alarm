################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Alarm.c \
../Core/Src/CLI.c \
../Core/Src/Flash.c \
../Core/Src/LED.c \
../Core/Src/Rtc.c \
../Core/Src/comtask.c \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/mybuzzer.c \
../Core/Src/mymain.c \
../Core/Src/new_button.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_hal_timebase_tim.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c 

OBJS += \
./Core/Src/Alarm.o \
./Core/Src/CLI.o \
./Core/Src/Flash.o \
./Core/Src/LED.o \
./Core/Src/Rtc.o \
./Core/Src/comtask.o \
./Core/Src/freertos.o \
./Core/Src/main.o \
./Core/Src/mybuzzer.o \
./Core/Src/mymain.o \
./Core/Src/new_button.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_hal_timebase_tim.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o 

C_DEPS += \
./Core/Src/Alarm.d \
./Core/Src/CLI.d \
./Core/Src/Flash.d \
./Core/Src/LED.d \
./Core/Src/Rtc.d \
./Core/Src/comtask.d \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/mybuzzer.d \
./Core/Src/mymain.d \
./Core/Src/new_button.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_hal_timebase_tim.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Alarm.d ./Core/Src/Alarm.o ./Core/Src/Alarm.su ./Core/Src/CLI.d ./Core/Src/CLI.o ./Core/Src/CLI.su ./Core/Src/Flash.d ./Core/Src/Flash.o ./Core/Src/Flash.su ./Core/Src/LED.d ./Core/Src/LED.o ./Core/Src/LED.su ./Core/Src/Rtc.d ./Core/Src/Rtc.o ./Core/Src/Rtc.su ./Core/Src/comtask.d ./Core/Src/comtask.o ./Core/Src/comtask.su ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mybuzzer.d ./Core/Src/mybuzzer.o ./Core/Src/mybuzzer.su ./Core/Src/mymain.d ./Core/Src/mymain.o ./Core/Src/mymain.su ./Core/Src/new_button.d ./Core/Src/new_button.o ./Core/Src/new_button.su ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_hal_timebase_tim.d ./Core/Src/stm32l4xx_hal_timebase_tim.o ./Core/Src/stm32l4xx_hal_timebase_tim.su ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su

.PHONY: clean-Core-2f-Src

