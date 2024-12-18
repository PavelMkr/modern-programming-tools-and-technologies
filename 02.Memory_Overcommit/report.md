# Отчёт по 02.Memory_Overcommit
## Задание

- Выделить заведомо сликом большое количество памяти при помощи malloc (предпочтительно) или объявления глобального массива. Количество памяти задать параметром командной строки.
- С шагом в 4 КиБ (вероятно минимальный размер страницы на вашем компьютере) обращаться к этой памяти на чтение или на запись. Для того, чтобы задать, идёт обращение на чтение или на запись, использовать параметр командной строки.
- Чтобы процесс был управляемым, раз в неколько тысяч (или десятков, или сотен тысяч, решите сами) обращений делайте паузу на несколько десятков или сотен (тоже решите сами) миллисекунд. Чтобы ОС превращалась в тыкву управлямо.
- Пронаблюдайте за потреблением памяти при помощи системных инструментов. В каких случаях оно будет расти, в каких — нет.
- Если у вас есть возможность, попробуйте испытать программу под разными ОС.

## Конфигурация ПК

- Processor: AMD64 Family 23 Model 104 Stepping 1 AuthenticAMD ~2100 Mhz;
- Total Physical Memory:     15 707 MB;
- Virtual Memory: Max Size:  23 068 MB;

1) Ubuntu
- Система: Ubuntu 24.04.1 LTS;
- Компилятор: gcc 13.2.0;
- Мониторинг процессов: htop.
2) Windows 11
- Система: Windows 11 version 10.0.22631 N/A Build 22631;
- Компилятор: gcc 14.2.0;
- Мониторинг процессов: ntop.
## Ход работы

Была написана программа `memory_test.c`
1) `memory_test` принимает 2 параметра: размер памяти в Кб и тип операции (для замеров использовался `write`);
2) Введённый размер памяти преобразуется в `size_t` и проверяется, что результат меньше  значения`MAX_ARRAY_SIZE` (число увеличено от изначально запланированного для получения более интересных результатов);
3) С помощью `malloc` память выделяется для массива `memory`;
4) Память заполняется данными по 1 байту (значение `(char)(i%256)`) каждые 4 Кб памяти. Для избежания слишком высокой нагрузки через каждые `accesses_per_pause` операций выполняется пауза;
5) При завершении работы программа освобождает память с помощью `free`.

### Ubuntu:

Изначально занято 2.56 Гб из 15.0 Гб:
![Рисунок vscode_without_test](.pics/vscode_without_test.png)

При записи 5 Гб, загрузка доходит до 7.66 Гб:
![Рисунок vscode_5gb](.pics/vscode_5gb.png)

При записи 10 Гб, загрузка доходит до 12.7 Гб:
![Рисунок vscode_5gb](.pics/vscode_10gb.png)

При записи 14 Гб, загрузка доходит до 14.1 Гб, после vscode вылетает с ошибкой:
![Рисунок vscode_14gb](.pics/vscode_14gb.png)

Итог запуска записи 14 Гб через vscode:
![Рисунок vscode_clean-exit](.pics/vscode_clean-exit.png)

Перезапуск vscode, если использовать reopen:
![Рисунок vscode_launch-failed](.pics/vscode_launch-failed.png)

Результат запуска записи 14 Гб через встроенный Terminal:
![Рисунок terminal_14gb](.pics/terminal_14gb.png)

Загрузка через htop при записи 14 Гб через встроенный Terminal:
![Рисунок terminal_14gb_htop](.pics/terminal_14gb_htop.png)

Результат при записи 20 Гб, вылет из-за нехватки памяти:
![Рисунок vscode_20gb](.pics/vscode_20gb.png)

### Windows:

Изначально занято 24.5% (~3.68 Гб) из 15.0 Гб:
![Рисунок ntop_without_test_windows](.pics/ntop_without_test_windows.bmp)

При записи 5 Гб, загрузка доходит до 59.4% (~8.91 Гб):
![Рисунок vscode_5gb_windows](.pics/vscode_5gb_windows.bmp)

При записи 10 Гб, загрузка доходит до 90.9% (~13.64 Гб):
![Рисунок vscode_10gb_windows](.pics/vscode_10gb_windows.bmp)

При записи 14 Гб, загрузка доходит до 97.5% (~14.63 Гб):
![Рисунок vscode_14gb_windows](.pics/vscode_14gb_windows.bmp)

При записи 20 Гб, загрузка доходит до 98.7% (~14.8 Гб):
![Рисунок vscode_20gb_windows](.pics/vscode_20gb_windows.bmp)

В случае записи большого объема (например 255 Гб), ошибка malloc о нехватке места:
![Рисунок vscode_255gb_windows](.pics/vscode_255gb_windows.bmp)

# Результат

При примерно равной нагрузке как на Windows, так и на Ubuntu, с большим объемом записи успешно справляется Windows. В Ubuntu это приводит либо к вылету (vscode), либо к принудительной остановке (Terminal)