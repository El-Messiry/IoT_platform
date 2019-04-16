################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/ESP8266.c \
../src/HAL/LCD.c \
../src/HAL/LDR.c \
../src/HAL/Temperature.c 

OBJS += \
./src/HAL/ESP8266.o \
./src/HAL/LCD.o \
./src/HAL/LDR.o \
./src/HAL/Temperature.o 

C_DEPS += \
./src/HAL/ESP8266.d \
./src/HAL/LCD.d \
./src/HAL/LDR.d \
./src/HAL/Temperature.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/%.o: ../src/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS\Inc" -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


