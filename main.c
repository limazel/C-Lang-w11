#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int h;
    int m;
    int s;
    int ms;
} Zaman;

void zamanYaz(Zaman z) {
    printf("%02d:%02d:%02d:%03d\n", z.h, z.m, z.s, z.ms);
    return;
}

int main() {
    Zaman z;
    printf("Zamani giriniz (hh:mm:ss:ms): ");
    scanf("%d:%d:%d:%d", &z.h, &z.m, &z.s, &z.ms);
    zamanYaz(z);
}
