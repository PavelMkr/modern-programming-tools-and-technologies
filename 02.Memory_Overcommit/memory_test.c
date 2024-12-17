#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Максимальный размер массива
#define MAX_ARRAY_SIZE 9999994294967296UL // 4 ГБ + шесть "9" в начале, чтобы заставить программу перезаполнять память

// Глобальный одномерный массив
char *memory = NULL;

void usage(const char *prog_name) {
    printf("Usage: %s <memory_size_in_kb> <read|write>\n", prog_name);
    printf("Example: %s 102400 write\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    // Размер памяти из аргументов командной строки
    size_t memory_size_kb = strtoul(argv[1], NULL, 10);
    if (memory_size_kb == 0 || memory_size_kb * 1024 > MAX_ARRAY_SIZE) {
        fprintf(stderr, "Error: Invalid memory size. Maximum is %lu KiB.\n", MAX_ARRAY_SIZE / 1024);
        usage(argv[0]);
    }

    // write or read
    int is_write = 0;
    if (strcmp(argv[2], "write") == 0) {
        is_write = 1;
    } else if (strcmp(argv[2], "read") != 0) {
        fprintf(stderr, "Error: Invalid operation. Use 'read' or 'write'.\n");
        usage(argv[0]);
    }

    // Объем памяти в байтах
    size_t memory_size_bytes = memory_size_kb * 1024;

    // Память для глобального массива
    memory = malloc(memory_size_bytes);
    if (!memory) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Allocated %zu KiB of memory.\n", memory_size_kb);

    // Заполнение памяти для предотвращения lazy allocation
    if (is_write) {
        printf("Initializing memory with dummy data...\n");
        for (size_t i = 0; i < memory_size_bytes; i += 4096) {
            memory[i] = 0;
        }
    }

    printf("Starting %s operations...\n", is_write ? "write" : "read");

    // Основной цикл чтения/записи с паузами
    size_t accesses_per_pause = 1000;  
    useconds_t pause_duration = 100000; // vscode не определяет useconds_t

    for (size_t i = 0; i < memory_size_bytes; i += 4096) {
        if (is_write) {
            memory[i] = (char)(i % 256); // Запись
        } else {
            volatile char data = memory[i]; // Чтение
            (void)data; // Предотвращение оптимизации
        }

        // Пауза через каждые `accesses_per_pause` обращений
        if (i / 4096 % accesses_per_pause == 0) {
            usleep(pause_duration);  // Увеличение паузы между обращениями
        }
    }

    printf("Finished %s operations.\n", is_write ? "write" : "read");

    // Чистка памяти
    free(memory);

    return 0;
}
