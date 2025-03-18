#include <time.h>
#include "my_functions.h"

// Функция для получения текущей даты
void get_current_date(int* year, int* month, int* day) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    *year = tm.tm_year + 1900; // tm.tm_year возвращает количество лет с 1900 года
    *month = tm.tm_mon + 1;    // tm.tm_mon возвращает месяц от 0 до 11
    *day = tm.tm_mday;         // tm.tm_mday — это день месяца
}

// Функция для вычисления возраста
void calculate_age(int birth_year, int birth_month, int birth_day,
    int current_year, int current_month, int current_day,
    int* age_years, int* age_months, int* age_days) {
    *age_years = current_year - birth_year;

    // Корректировка лет, если день рождения еще не наступил в этом году
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        (*age_years)--;
    }

    // Вычисление месяцев
    if (current_month >= birth_month) {
        *age_months = current_month - birth_month;
    }
    else {
        *age_months = current_month + 12 - birth_month;
    }

    // Вычисление дней
    if (current_day >= birth_day) {
        *age_days = current_day - birth_day;
    }
    else {
        int days_in_prev_month;
        if (current_month == 1) {
            days_in_prev_month = 31; // Январь
        }
        else if (current_month == 2) {
            // Проверка на високосный год
            days_in_prev_month = (current_year % 4 == 0 && (current_year % 100 != 0 || current_year % 400 == 0)) ? 29 : 28;
        }
        else if (current_month == 3 || current_month == 5 || current_month == 7 || current_month == 8 || current_month == 10 || current_month == 12) {
            days_in_prev_month = 31;
        }
        else {
            days_in_prev_month = 30;
        }
        *age_days = days_in_prev_month - birth_day + current_day;
    }
}
