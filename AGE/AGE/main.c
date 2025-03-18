#include <stdio.h>
#include "my_functions.h"

int main() {
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    int age_years, age_months, age_days;

    // Get the current date
    get_current_date(&current_year, &current_month, &current_day);

    // Input the birth date
    printf_s("Enter your birth year: ");
    scanf_s("%d", &birth_year);
    printf_s("Enter your birth month: ");
    scanf_s("%d", &birth_month);
    printf_s("Enter your birth day: ");
    scanf_s("%d", &birth_day);

    // Calculate age
    calculate_age(birth_year, birth_month, birth_day, current_year, current_month, current_day,
        &age_years, &age_months, &age_days);

    // Output the result
    printf("Your age is: %d years, %d months, %d days\n", age_years, age_months, age_days);

    return 0;
}
