################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Service_Layer/FreeRTOS/Src/PollQ.c \
../src/Service_Layer/FreeRTOS/Src/croutine.c \
../src/Service_Layer/FreeRTOS/Src/event_groups.c \
../src/Service_Layer/FreeRTOS/Src/heap_1.c \
../src/Service_Layer/FreeRTOS/Src/integer.c \
../src/Service_Layer/FreeRTOS/Src/list.c \
../src/Service_Layer/FreeRTOS/Src/port.c \
../src/Service_Layer/FreeRTOS/Src/queue.c \
../src/Service_Layer/FreeRTOS/Src/tasks.c 

OBJS += \
./src/Service_Layer/FreeRTOS/Src/PollQ.o \
./src/Service_Layer/FreeRTOS/Src/croutine.o \
./src/Service_Layer/FreeRTOS/Src/event_groups.o \
./src/Service_Layer/FreeRTOS/Src/heap_1.o \
./src/Service_Layer/FreeRTOS/Src/integer.o \
./src/Service_Layer/FreeRTOS/Src/list.o \
./src/Service_Layer/FreeRTOS/Src/port.o \
./src/Service_Layer/FreeRTOS/Src/queue.o \
./src/Service_Layer/FreeRTOS/Src/tasks.o 

C_DEPS += \
./src/Service_Layer/FreeRTOS/Src/PollQ.d \
./src/Service_Layer/FreeRTOS/Src/croutine.d \
./src/Service_Layer/FreeRTOS/Src/event_groups.d \
./src/Service_Layer/FreeRTOS/Src/heap_1.d \
./src/Service_Layer/FreeRTOS/Src/integer.d \
./src/Service_Layer/FreeRTOS/Src/list.d \
./src/Service_Layer/FreeRTOS/Src/port.d \
./src/Service_Layer/FreeRTOS/Src/queue.d \
./src/Service_Layer/FreeRTOS/Src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
src/Service_Layer/FreeRTOS/Src/%.o: ../src/Service_Layer/FreeRTOS/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS\Inc" -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


