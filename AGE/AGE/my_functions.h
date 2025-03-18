#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

// Прототипы функций
void get_current_date(int* year, int* month, int* day);
void calculate_age(int birth_year, int birth_month, int birth_day,
    int current_year, int current_month, int current_day,
    int* age_years, int* age_months, int* age_days);

#endif
