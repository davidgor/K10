################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Output/Display/TextScrollerShower/TSS.cpp 

OBJS += \
./src/Output/Display/TextScrollerShower/TSS.o 

CPP_DEPS += \
./src/Output/Display/TextScrollerShower/TSS.d 


# Each subdirectory must supply rules for building sources it contributes
src/Output/Display/TextScrollerShower/%.o: ../src/Output/Display/TextScrollerShower/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

