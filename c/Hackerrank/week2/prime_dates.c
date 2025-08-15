#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}


void findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    long long lucky_count = 0;

    
    int day = d1;
    int month = m1;
    int year = y1;

    while (true) {
       
        long long num = (long long)day;
        num = num * 100 + month;
        num = num * 10000 + year;

       
        if (num % 4 == 0 || num % 7 == 0) {
            lucky_count++;
        }

        
        if (day == d2 && month == m2 && year == y2) {
            break;
        }

       
        day++;
        if (day > days_in_month(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    printf("%lld\n", lucky_count);
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d-%d-%d", &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);
    findLuckyDates(d1, m1, y1, d2, m2, y2);
    return 0;
}
