
RM := rm -f
CC := gcc

SRC_DIR := src
INCLUDE_DIR := include

BUILD_DIR := build

LIBS := \
-lOpenCL

OBJ_SRCS := 
ASM_SRCS := 
C_SRCS := 
O_SRCS := 
S_UPPER_SRCS := 
EXECUTABLES := 
OBJS := 
USER_OBJS :=
C_DEPS := 

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 
SRCS += $(wildcard $(SRC_DIR)/*.c)

_OBJS += $(SRCS:.c=.o)
OBJS = $(patsubst $(SRC_DIR)/%,%,$(_OBJS))

DEPS += $(SRCS:.c=.d)

EXECUTABLES += \
./Cyclops.exe

# All Target
all: $(OBJS)
	@echo '$(OBJS)'
	@echo 'Finished building.'

Cyclops.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MinGW C Linker'
	$(CC) -o "Cyclops" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	
# Each subdirectory must supply rules for building sources it contributes
%.o: $(SRC_DIR)/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CC) -std=c99 -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Invoking: MinGW C Linker'
	$(CC) -o "$(@:.o=.exe)" "$@" $(USER_OBJS) $(LIBS)
	@echo 'Finished building: $<'
	@echo ' '


# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(DEPS)
	-@echo 'Clean build folder.'

.PHONY: all clean dependents
.SECONDARY:

