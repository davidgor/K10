################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Input/Visual_Core/Objecten/Objecten.cpp 

OBJS += \
./src/Input/Visual_Core/Objecten/Objecten.o 

CPP_DEPS += \
./src/Input/Visual_Core/Objecten/Objecten.d 


# Each subdirectory must supply rules for building sources it contributes
src/Input/Visual_Core/Objecten/%.o: ../src/Input/Visual_Core/Objecten/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


