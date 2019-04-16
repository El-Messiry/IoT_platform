################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP/T_DataInputs.c \
../src/APP/T_Display.c \
../src/APP/T_Execute.c \
../src/APP/T_Receive.c \
../src/APP/T_TX_Handler.c \
../src/APP/T_Transmit.c \
../src/APP/main.c 

OBJS += \
./src/APP/T_DataInputs.o \
./src/APP/T_Display.o \
./src/APP/T_Execute.o \
./src/APP/T_Receive.o \
./src/APP/T_TX_Handler.o \
./src/APP/T_Transmit.o \
./src/APP/main.o 

C_DEPS += \
./src/APP/T_DataInputs.d \
./src/APP/T_Display.d \
./src/APP/T_Execute.d \
./src/APP/T_Receive.d \
./src/APP/T_TX_Handler.d \
./src/APP/T_Transmit.d \
./src/APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/APP/%.o: ../src/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS\Inc" -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/APP/main.o: ../src/APP/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS" -I"D:\eclipse_workbench\MY_RTOS_PROJ_V4\src\Service_Layer\FreeRTOS\Inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/APP/main.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


