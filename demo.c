#include <stdio.h>
#include <stdlib.h>

// Önce Zaman tipi tanımı
typedef struct {
    int h;
    int m;
    int s;
    int ms;
} Zaman;

long long milisaniye(Zaman z) {
    long long ms = (60*60*1000) * z.h + (60*1000) * z.m + (1000) * z.s + z.ms;
    return ms;
}

// Sonra fonksiyon tanımı
Zaman zamanFark(Zaman z1, Zaman z2) {
    Zaman fark;
    if(z1.ms < z2.ms) {
        z1.s--;
        z1.ms += 1000;
    }
    if(z1.s < z2.s) {
        z1.m--;
        z1.s += 60;
    }
    if(z1.m < z2.m) {
        z1.h--;
        z1.m += 60;
    }
    if(z1.h < z2.h) {
        printf("Zaman 1, Zaman 2'den daha kucuk.\n");
        exit(1);
    }
    fark.h = z1.h - z2.h;
    fark.m = z1.m - z2.m;
    fark.s = z1.s - z2.s;
    fark.ms = z1.ms - z2.ms;
    return fark;
}

int main() {
    Zaman z1, z2, fark;
    printf("Zaman 1'i giriniz (hh:mm:ss:ms): ");
    scanf("%d:%d:%d:%d", &z1.h, &z1.m, &z1.s, &z1.ms);
    // printf("Zaman 2'yi giriniz (hh:mm:ss:ms): ");
    // scanf("%d:%d:%d:%d", &z2.h, &z2.m, &z2.s, &z2.ms);
    
    // fark = zamanFark(z1, z2);
    // printf("Zaman farki: %02d:%02d:%02d:%03d\n", fark.h, fark.m, fark.s, fark.ms);
    printf("%lld misil saniye\n", milisaniye(z1));
    return 0;
}
// Bu kod, iki zaman arasındaki farkı hesaplar ve sonucu ekrana yazdırır.