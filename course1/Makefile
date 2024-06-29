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

include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds

# Compiler Flags and Defines

TARGET = c1m3
CFLAGS = -Wall -Werror -g -O0 -std=c99 

ifeq ($(PLATFORM), HOST)
	SOURCES = $(addprefix src/,$(SRC))
	CC = gcc
	CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE $(INCLUDES)
	SIZE = size
else
	CC = arm-none-eabi-gcc
	CPU = cortex-m4
	ARCH = armv7e-m
	SCPECS = nosys.specs
	LD = arm-none-eabi-ld
	CFLAGS += -mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16 \
				--specs=$(SCPECS)
	SRC+= ./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	SOURCES = $(addprefix src/,$(SRC))
	
	INCLUDES+= -I ../include/CMSIS/ \
				-I ../include/msp432/
	CPPFLAGS = -DMSP432 -DCOURSE1 -DVERBOSE $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	size = arm-none-eabi-size
endif

PREP = $(SOURCES:.c=.i)
DEPS = $(SOURCES:.c=.d)
ASM = $(SOURCES:.c=.asm)
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

%.d: %.c
	$(CC) -M $<  $(CPPFLAGS) -o $@


compile-all: $(OBJS)

clean:
	rm -f $(PREP) $(DEPS) $(ASMS) $(OBJS) *.map $(TARGET).out



