################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Input/Visual_Core/ObjHerkening/ObjHerkening.cpp 

OBJS += \
./src/Input/Visual_Core/ObjHerkening/ObjHerkening.o 

CPP_DEPS += \
./src/Input/Visual_Core/ObjHerkening/ObjHerkening.d 


# Each subdirectory must supply rules for building sources it contributes
src/Input/Visual_Core/ObjHerkening/%.o: ../src/Input/Visual_Core/ObjHerkening/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/home/david12/Documenten/opencv1 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o   "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


