# Отчёт по 02.Memory_Overcommit
## Задание

## Конфигурация ПК
1) Ubuntu
- Система: Ubuntu 24.04.1 LTS;
- Компилятор: gcc 13.2.0;
2) Windows 11
- Система: Windows 11;
- Компилятор: gcc ;
## Ход работы
### Ubuntu:

Изначально занято 2.56 Гб из 15.0 Гб:
![Рисунок vscode_without_test](.pics/vscode_without_test.png)

При записи 5 Гб, загрузка доходит до 7.66 Гб:
![Рисунок vscode_5gb](.pics/vscode_5gb.png)

При записи 10 Гб, загрузка доходит до 12.7 Гб, справится за n-ное количество времени:
![Рисунок vscode_5gb](.pics/vscode_10gb.png)

При записи 14 Гб, загрузка доходит до 14.1 Гб, после vscode вылетает с ошибкой:
![Рисунок terminal_14gb](.pics/terminal_14gb.png)

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

# Результат
