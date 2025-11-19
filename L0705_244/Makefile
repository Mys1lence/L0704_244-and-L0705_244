CXX = g++
CXXFLAGS = -std=c++14 -Wall
TARGET = L0705_244_test

all: $(TARGET)

$(TARGET): L0705_244.cpp test_simple.cpp
 $(CXX) $(CXXFLAGS) -o $(TARGET) L0705_244.cpp test_simple.cpp

run: $(TARGET)
 ./$(TARGET)

clean:
 rm -f $(TARGET)

.PHONY: all run clean
