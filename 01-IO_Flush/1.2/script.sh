#!/bin/bash

# Компиляция
gcc -o main main.c
#
echo "Откомпилировать и собрать программу, запустить, как есть:"
./main
#
echo -e "\nДобвить символы '\ n' в конец строк:"
./main -n
#
echo -e "\nУбрать fflush:"
./main -f
#
echo -e "\nПеренаправить вывод (оба потока) в файл (output.log):"
./main -r
cat output.log
