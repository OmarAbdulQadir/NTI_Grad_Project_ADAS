################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_program.c \
../Src/DIO_program.c \
../Src/EXTI_program.c \
../Src/LCD_program.c \
../Src/TIMER_program.c \
../Src/UART_program.c \
../Src/main.c 

OBJS += \
./Src/ADC_program.o \
./Src/DIO_program.o \
./Src/EXTI_program.o \
./Src/LCD_program.o \
./Src/TIMER_program.o \
./Src/UART_program.o \
./Src/main.o 

C_DEPS += \
./Src/ADC_program.d \
./Src/DIO_program.d \
./Src/EXTI_program.d \
./Src/LCD_program.d \
./Src/TIMER_program.d \
./Src/UART_program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


