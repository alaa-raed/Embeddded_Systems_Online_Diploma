################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.c 

OBJS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/alaar/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/Inc" -I"C:/Users/alaar/STM32CubeIDE/workspace_1.4.0/Drivers/HAL/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/alaar/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/Inc" -I"C:/Users/alaar/STM32CubeIDE/workspace_1.4.0/Drivers/HAL/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

