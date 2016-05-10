################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Input/OpenCV/CameraSysteem.cpp 

OBJS += \
./src/Input/OpenCV/CameraSysteem.o 

CPP_DEPS += \
./src/Input/OpenCV/CameraSysteem.d 


# Each subdirectory must supply rules for building sources it contributes
src/Input/OpenCV/%.o: ../src/Input/OpenCV/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/home/david12/Documenten/opencv1 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o   "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


