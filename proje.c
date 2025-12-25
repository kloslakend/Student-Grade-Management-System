#include <stdio.h>
#include <string.h>

char isimler[100][50];
int ids[100];
float notlar[100];
int adet = 0;

void ekle() {
    printf("\nOgrenci ID: ");
    scanf("%d", &ids[adet]);
    getchar();

    printf("Ogrenci Ad Soyad: ");
    fgets(isimler[adet], sizeof(isimler[adet]), stdin);
    isimler[adet][strcspn(isimler[adet], "\n")] = '\0';

    printf("Ogrenci Notu: ");
    scanf("%f", &notlar[adet]);

    adet++;
    printf("Kayit basarili!\n");
}

void sil() {
    int silId, bulunanIndex = -1;
    printf("\nSilinecek ID: ");
    scanf("%d", &silId);

    for (int i = 0; i < adet; i++) {
        if (ids[i] == silId) {
            bulunanIndex = i;
            break;
        }
    }

    if (bulunanIndex != -1) {
        for (int i = bulunanIndex; i < adet - 1; i++) {
            ids[i] = ids[i + 1];
            notlar[i] = notlar[i + 1];
            strcpy(isimler[i], isimler[i + 1]);
        }
        adet--;
        printf("Silindi.\n");
    } else {
        printf("Bulunamadi!\n");
    }
}

void listele() {
    if (adet == 0) {
        printf("\nListe bos!\n");
        return;
    }
    printf("\n--- MEVCUT LISTE ---\n");
    for (int i = 0; i < adet; i++) {
        printf("ID: %d | Isim: %-20s | Not: %.2f\n", ids[i], isimler[i], notlar[i]);
    }
}

int main() {
    int secim;
    while (1) {
        printf("\n1-Ekle\n2-Sil\n3-Listele\n4-Cikis\nSecim: ");

        if (scanf("%d", &secim) != 1) {
            while(getchar() != '\n');
            continue;
        }

        if (secim == 1) ekle();
        else if (secim == 2) sil();
        else if (secim == 3) listele();
        else if (secim == 4) break;
    }
    return 0;
}