#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

# -c  Compile and Assemble File, Do Not Link
# -o <FILE> Compile, Assemble, and Link to OUTPUT_FILE
# -g  Generate Debugging Information in Executable
# -Wall  Enable All Warning Messages
# -Werror  Treat All Warnings as Errors
# -I<DIR>  Include this <DIR> to look for header files
# -ansi -std=STANDARD  Which standard version to use (ex: c89, c99)
# -v  Verbose output form GCC

include sources.mk

# Platform Overrides
PLATFORM=HOST

# General Flags for all platforms
GEN_FLAGS = \
			      -Wall \
			      -Werror \
			      -g \
			      -O0 \
			      -std=c99

TARGET = c1m2

# Platform Dependant Variables
ifeq ($(PLATFORM),MSP432)
	# MSP432 dependant build options
	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES+= 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES+= 	-I ../include/CMSIS/ \
				-I ../include/msp432/

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	# Compiler Flags
	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)


else
	# @echo Host platform detected
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size

endif

PREP = $(SOURCES:.c=.i)	
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)	
OBJS = $(SOURCES:.c=.o)	

.PHONY: compile-all build clean

build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@
  
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@
  
compile-all: $(OBJS)

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f *.out *.map *.o *.asm *.i
