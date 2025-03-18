#include <stdio.h>
#include <my_functions.h>

// Функция для вывода значения порта в двоичном виде
void printBinary(unsigned char port) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (port >> i) & 1); // Извлекаем каждый бит
    }
    printf("\n");
}
// Основная логика программы
void run_shift_arifmetic() {
    unsigned char port = 0x00; // Начальное значение порта
    int choice, shift;

    // Вывод начального состояния порта
    printf("Начальное состояние порта:\n");
    printf("Двоичный вид: ");
    printBinary(port);
    printf("Шестнадцатеричный вид: 0x%02X\n", port);

    while (1) {
        // Меню выбора операции
        printf("\nВыберите операцию:\n");
        printf("1. Сдвиг влево\n");
        printf("2. Сдвиг вправо\n");
        printf("3. Установить новое значение порта\n");
        printf("4. Выход\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &choice);

        if (choice == 4) {
            printf("Программа завершена.\n");
            break;
        }

        switch (choice) {
        case 1: // Сдвиг влево
            printf("Введите количество позиций для сдвига влево (0-7): ");
            scanf_s("%d", &shift);
            if (shift < 0 || shift > 7) {
                printf("Ошибка: количество позиций должно быть в диапазоне 0-7.\n");
                break;
            }
            port = port << shift;
            printf("Результат после сдвига влево:\n");
            printf("Двоичный вид: ");
            printBinary(port);
            printf("Шестнадцатеричный вид: 0x%02X\n", port);
            break;

        case 2: // Сдвиг вправо
            printf("Введите количество позиций для сдвига вправо (0-7): ");
            scanf_s("%d", &shift);
            if (shift < 0 || shift > 7) {
                printf("Ошибка: количество позиций должно быть в диапазоне 0-7.\n");
                break;
            }
            port = port >> shift;
            printf("Результат после сдвига вправо:\n");
            printf("Двоичный вид: ");
            printBinary(port);
            printf("Шестнадцатеричный вид: 0x%02X\n", port);
            break;

        case 3: // Установить новое значение порта
            printf("Введите новое значение порта (0-255): ");
            int new_value;
            scanf_s("%d", &new_value);
            if (new_value < 0 || new_value > 255) {
                printf("Ошибка: значение должно быть в диапазоне 0-255.\n");
                break;
            }
            port = (unsigned char)new_value;
            printf("Новое состояние порта:\n");
            printf("Двоичный вид: ");
            printBinary(port);
            printf("Шестнадцатеричный вид: 0x%02X\n", port);
            break;

        default:
            printf("Ошибка: неверный выбор операции.\n");
            break;
        }
    }

}