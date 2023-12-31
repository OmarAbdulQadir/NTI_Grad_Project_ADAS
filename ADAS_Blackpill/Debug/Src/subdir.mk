################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/BSD_program.c \
../Src/EXTI_program.c \
../Src/GPIO_program.c \
../Src/ICU_program.c \
../Src/LCD_program.c \
../Src/LDA_program.c \
../Src/LED_program.c \
../Src/LKA_program.c \
../Src/MDC_config.c \
../Src/MDC_program.c \
../Src/NVIC_program.c \
../Src/PWM_program.c \
../Src/RCC_program.c \
../Src/UART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/BSD_program.o \
./Src/EXTI_program.o \
./Src/GPIO_program.o \
./Src/ICU_program.o \
./Src/LCD_program.o \
./Src/LDA_program.o \
./Src/LED_program.o \
./Src/LKA_program.o \
./Src/MDC_config.o \
./Src/MDC_program.o \
./Src/NVIC_program.o \
./Src/PWM_program.o \
./Src/RCC_program.o \
./Src/UART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/BSD_program.d \
./Src/EXTI_program.d \
./Src/GPIO_program.d \
./Src/ICU_program.d \
./Src/LCD_program.d \
./Src/LDA_program.d \
./Src/LED_program.d \
./Src/LKA_program.d \
./Src/MDC_config.d \
./Src/MDC_program.d \
./Src/NVIC_program.d \
./Src/PWM_program.d \
./Src/RCC_program.d \
./Src/UART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/BSD_program.cyclo ./Src/BSD_program.d ./Src/BSD_program.o ./Src/BSD_program.su ./Src/EXTI_program.cyclo ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/ICU_program.cyclo ./Src/ICU_program.d ./Src/ICU_program.o ./Src/ICU_program.su ./Src/LCD_program.cyclo ./Src/LCD_program.d ./Src/LCD_program.o ./Src/LCD_program.su ./Src/LDA_program.cyclo ./Src/LDA_program.d ./Src/LDA_program.o ./Src/LDA_program.su ./Src/LED_program.cyclo ./Src/LED_program.d ./Src/LED_program.o ./Src/LED_program.su ./Src/LKA_program.cyclo ./Src/LKA_program.d ./Src/LKA_program.o ./Src/LKA_program.su ./Src/MDC_config.cyclo ./Src/MDC_config.d ./Src/MDC_config.o ./Src/MDC_config.su ./Src/MDC_program.cyclo ./Src/MDC_program.d ./Src/MDC_program.o ./Src/MDC_program.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/PWM_program.cyclo ./Src/PWM_program.d ./Src/PWM_program.o ./Src/PWM_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/UART_program.cyclo ./Src/UART_program.d ./Src/UART_program.o ./Src/UART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

