TARGET_EXEC ?= main

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src
INC_DIR ?= ./include

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS) $(INC_DIR))

CC = gcc
CXX = g++

DEBUG = -g -O0 -Wall
CFLAGS += $(DEBUG)

# USELIB = USE_BCM2835_LIB
USELIB = USE_WIRINGPI_LIB
DEBUG = -D $(USELIB)

OTHERLIBS = -pthread

ifeq ($(USELIB), USE_BCM2835_LIB)
    LIB = -lbcm2835 $(OTHERLIBS) -lm 
else ifeq ($(USELIB), USE_WIRINGPI_LIB)
    LIB = -lwiringPi $(OTHERLIBS) -lm 
endif

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LIB)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ $(LIB)

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(LIB)


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(TARGET_EXEC)

-include $(DEPS)

MKDIR_P ?= mkdir -p
