################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Output/ArduinoCom/ArduinoCom.cpp 

OBJS += \
./src/Output/ArduinoCom/ArduinoCom.o 

CPP_DEPS += \
./src/Output/ArduinoCom/ArduinoCom.d 


# Each subdirectory must supply rules for building sources it contributes
src/Output/ArduinoCom/%.o: ../src/Output/ArduinoCom/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/local/include/opencv -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -pthread -fprofile-arcs -ftest-coverage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


