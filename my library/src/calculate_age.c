#include <stdio.h>
#include <my_functions.h>
#include <time.h>

int calculate_age(int birth_day, int birth_month, int birth_year) {
    // Получение текущей даты
    time_t now;
    time(&now);
    struct tm* current_time = localtime(&now);

    int current_day = current_time->tm_mday;
    int current_month = current_time->tm_mon + 1; // Месяцы в tm начинаются с 0
    int current_year = current_time->tm_year + 1900; // Годы в tm отсчитываются от 1900


    // Проверка корректности введённых данных
    if (birth_year < 0 || birth_year > current_year ||
        birth_month < 1 || birth_month > 12 ||
        birth_day < 1 || birth_day > 31) {
        printf("Ошибка: некорректная дата рождения.\n");
        return -1; // Возвращаем -1 в случае ошибки
    }

    // Вычисление возраста
    int age = current_year - birth_year;

    // Корректировка возраста, если день рождения ещё не наступил в этом году
    if (current_month < birth_month ||
        (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    // Дополнительная проверка на отрицательный возраст
    if (age < 0) {
        printf("Ошибка: дата рождения в будущем.\n");
        return -1;
    }

    return age;
}