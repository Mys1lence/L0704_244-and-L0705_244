# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic -g
TARGET = L0704_244_test
SOURCES = L0704_244.cpp test_L0704_244.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = L0704_244.hpp

# Основная цель
$(TARGET): $(OBJECTS)
 $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Компиляция object файлов
%.o: %.cpp $(HEADERS)
 $(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
 rm -f $(TARGET) $(OBJECTS)

# Запуск тестов
test: $(TARGET)
 ./$(TARGET)

# Сборка в release режиме
release: CXXFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)

# Отладочная сборка
debug: CXXFLAGS += -DDEBUG -O0
debug: clean $(TARGET)

# Проверка стиля кода
check:
 cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(HEADERS)

# Создание архива для отправки
archive:
 tar -czf L0704_244_project.tar.gz $(SOURCES) $(HEADERS) Makefile

.PHONY: clean test release debug check archive
