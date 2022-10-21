

CC             = g++
CFLAGSM        = 
CFLAGSREL      = -O2 -g -v
CFLAGSDBG      = -g3 -O0 -D_DEBUG -v
CFLAGSBUILD=$(CFLAGSREL)
CFLAGS         = -std=gnu++11 -Wall -Wextra -pedantic $(CFLAGSBUILD) $(CFLAGSM)

MKDIR_P        = mkdir -p
OBJDIR         = ./build

TARGET := TimeGetSetMainApp

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


all: clearbuild $(TARGET) copy clear
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ 
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clearbuild:
	rm -rf ./build/*.o
	rm -rf ./build/TimeGetSetMainApp
copy:
	cp *.*o ./build
	cp TimeGetSetMainApp ./build

clear:
	rm -rf $(TARGET) *.o
	rm -rf TimeGetSetMainApp
	
.PHONY: all clean
