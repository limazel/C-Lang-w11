#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

bool artikYear(int year) {
    if(year % 400 == 0) return true;
    if(year % 100 == 0) return false;
    if(year % 4 == 0) return true;
    return false;
}

int dayTransform(Date date) {
    int dayN = 0;
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(artikYear(date.year)) {
        months[2] = 29;
    }
    for(int i = 1; i < date.month; i++) {
        dayN += months[i];
    }

    dayN += date.day;
    return dayN;
}

int main() {
    Date date= {1, 10, 2000};
    printf("Day number: %d\n", dayTransform(date));
    return 0;
}