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
	g++ -std=c++0x -I/usr/local/include/opencv -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -pthread -fprofile-arcs -ftest-coverage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


