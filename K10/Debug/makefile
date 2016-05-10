################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Output/Sound/subdir.mk
-include src/Output/Display/TextScrollerShower/subdir.mk
-include src/Output/Display/subdir.mk
-include src/Output/ArduinoCom/subdir.mk
-include src/Loger/subdir.mk
-include src/Input/d/subdir.mk
-include src/Input/Visual_Core/Objecten/subdir.mk
-include src/Input/Visual_Core/ObjHerkening/subdir.mk
-include src/Input/Visual_Core/subdir.mk
-include src/Input/Sensors/subdir.mk
-include src/Input/Joystick/subdir.mk
-include src/Functions/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: K9u

# Tool invocations
K9u: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	arm-linux-gnueabihf-g++  -o "K9u" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) K9u
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
