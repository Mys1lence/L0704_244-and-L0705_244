CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic -g
TARGET = L0704_244_test
SOURCES = L0704_244.cpp test_L0704_244.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = L0704_244.hpp

$(TARGET): $(OBJECTS)
 $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
 $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
 rm -f $(TARGET) $(OBJECTS)

test: $(TARGET)
 ./$(TARGET)

release: CXXFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)

# Отладочная сборка
debug: CXXFLAGS += -DDEBUG -O0
debug: clean $(TARGET)

# Проверка стиля кода
check:
 cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(HEADERS)

archive:
 tar -czf L0704_244_project.tar.gz $(SOURCES) $(HEADERS) Makefile

.PHONY: clean test release debug check archive
