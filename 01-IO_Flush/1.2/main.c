#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int add_newline = 0; // Добвить символы '\n' в конец строк
    int remove_fflush = 0; // Убрать fflush
    int redirect_output = 0; // Перенаправить вывод (оба потока) в файл
    int opt;

    // Обработка параметров
    while ((opt = getopt(argc, argv, "nfr")) != -1) {
        switch (opt) {
            case 'n': add_newline = 1; break;
            case 'f': remove_fflush = 1; break;
            case 'r': redirect_output = 1; break;
            default:
                fprintf(stderr, "Usage: %s [-n] [-f] [-r]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Создание лога при выборе параметра
    if (redirect_output) {
        freopen("output.log", "w", stdout);
        freopen("output.log", "a", stderr);
    }

    // работа с stdout
    puts("STDOUT");
    if (add_newline) {
        printf("\n");
    }
    if (!remove_fflush) {
        fflush(stdout);
    }

    // работа с stderr
    fputs("STDERR",stderr);
    if (add_newline) {
        fprintf(stderr, "\n");
    }
    if (!remove_fflush) {
        fflush(stderr);
    }

    return 0;
}
