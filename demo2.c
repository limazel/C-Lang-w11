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

Date dateTransform(int day, int year) {
    Date d;
    int month = 1;
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(artikYear(year)) {
        months[2] = 29;
    }
    while(day > months[month]) {
        day -= months[month];
        month++;
    }
    d.day = day;
    d.month = month;
    d.year = year;
    return d;
}

void printDate(Date date) {
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}

int main() {
    Date date= {1, 10, 2000};
    printf("Day number: %d\n", dayTransform(date));
    int day, year;
    printf("Enter day number and year: ");
    scanf("%d %d", &day, &year);
    Date d = dateTransform(day, year);
    printf("Date: ");
    printDate(d);
    return 0;
}