################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/sbus/sbus.c 

OBJS += \
./Core/lib/sbus/sbus.o 

C_DEPS += \
./Core/lib/sbus/sbus.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/sbus/%.o Core/lib/sbus/%.su Core/lib/sbus/%.cyclo: ../Core/lib/sbus/%.c Core/lib/sbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"F:/Workspace/Elektronika/Projects/WheelWirelessReceiver_F303RE/Core/lib/nRF24" -I"F:/Workspace/Elektronika/Projects/WheelWirelessReceiver_F303RE/Core/lib/sbus" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lib-2f-sbus

clean-Core-2f-lib-2f-sbus:
	-$(RM) ./Core/lib/sbus/sbus.cyclo ./Core/lib/sbus/sbus.d ./Core/lib/sbus/sbus.o ./Core/lib/sbus/sbus.su

.PHONY: clean-Core-2f-lib-2f-sbus

