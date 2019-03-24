################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MHAL/ESP8266.c \
../src/MHAL/LCD.c \
../src/MHAL/LDR.c \
../src/MHAL/Temperature.c 

OBJS += \
./src/MHAL/ESP8266.o \
./src/MHAL/LCD.o \
./src/MHAL/LDR.o \
./src/MHAL/Temperature.o 

C_DEPS += \
./src/MHAL/ESP8266.d \
./src/MHAL/LCD.d \
./src/MHAL/LDR.d \
./src/MHAL/Temperature.d 


# Each subdirectory must supply rules for building sources it contributes
src/MHAL/%.o: ../src/MHAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS\Inc" -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


