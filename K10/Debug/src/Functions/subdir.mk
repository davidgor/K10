################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Functions/Sleeper.cpp 

OBJS += \
./src/Functions/Sleeper.o 

CPP_DEPS += \
./src/Functions/Sleeper.d 


# Each subdirectory must supply rules for building sources it contributes
src/Functions/%.o: ../src/Functions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


