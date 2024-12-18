CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = task01
SOURCE = task01.c
OUTPUT = output.log

.PHONY: all clean run run-n run-f run-r

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	@echo "Запуск программы как есть:"
	./$(TARGET)

run-n: $(TARGET)
	@echo "Добавить '\ n' в конец строк:"
	./$(TARGET) | sed 's/$$/\\n/' > $(OUTPUT)
	@cat $(OUTPUT)

run-f: $(TARGET)
	@echo "Убрать fflush:"
	sed '/fflush/d' $(SOURCE) > temp.c && \
	$(CC) $(CFLAGS) -o $@ temp.c && \
	./$@
	rm temp.c

run-r: $(TARGET)
	@echo "Перенаправить вывод (оба потока) в файл:"
	./$(TARGET) > $(OUTPUT) 2>&1
	@cat $(OUTPUT)

clean:
	rm -f $(TARGET) $(OUTPUT)
