################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Input/d/cJoystick1.cpp 

OBJS += \
./src/Input/d/cJoystick1.o 

CPP_DEPS += \
./src/Input/d/cJoystick1.d 


# Each subdirectory must supply rules for building sources it contributes
src/Input/d/%.o: ../src/Input/d/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


