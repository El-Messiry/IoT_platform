################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Service_Layer/System_Diagnostic/subdir.mk
-include src/Service_Layer/My_Strings/subdir.mk
-include src/Service_Layer/MQTT_Client/subdir.mk
-include src/Service_Layer/FreeRTOS/Src/subdir.mk
-include src/MCAL/subdir.mk
-include src/HAL/subdir.mk
-include src/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MY_RTOS_PROJ_V4.lss \
MY_RTOS_PROJ_V4.lss \

FLASH_IMAGE += \
MY_RTOS_PROJ_V4.hex \
MY_RTOS_PROJ_V4.hex \

EEPROM_IMAGE += \
MY_RTOS_PROJ_V4.eep \
MY_RTOS_PROJ_V4.eep \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: MY_RTOS_PROJ_V4.elf secondary-outputs

# Tool invocations
MY_RTOS_PROJ_V4.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MY_RTOS_PROJ_V4.map -mmcu=atmega32 -o "MY_RTOS_PROJ_V4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MY_RTOS_PROJ_V4.lss: MY_RTOS_PROJ_V4.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MY_RTOS_PROJ_V4.elf  >"MY_RTOS_PROJ_V4.lss"
	@echo 'Finished building: $@'
	@echo ' '

MY_RTOS_PROJ_V4.hex: MY_RTOS_PROJ_V4.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MY_RTOS_PROJ_V4.elf  "MY_RTOS_PROJ_V4.hex"
	@echo 'Finished building: $@'
	@echo ' '

MY_RTOS_PROJ_V4.eep: MY_RTOS_PROJ_V4.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex MY_RTOS_PROJ_V4.elf  "MY_RTOS_PROJ_V4.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MY_RTOS_PROJ_V4.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MY_RTOS_PROJ_V4.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MY_RTOS_PROJ_V4.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
