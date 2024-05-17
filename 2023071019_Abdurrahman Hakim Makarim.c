/* kode ini saya ambil referensinya dari kode bapak materi queue lalu, saya berikan input untuk jumlah data saat di-run
dan bisa push (insert) dan pop (delete) dengan struktur stack yang mirip kode queue*/

/* Abdurrahman Hakim Makarim
    2023071019
    INF-A*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

int top = -1, *tumpukan, ukuran;

void push(int x);
int pop();
void tampilkanTumpukan();

int main() {
    int nilai;

    printf("Masukkan jumlah data: ");
    scanf("%d", &ukuran);

    tumpukan = (int*)malloc(ukuran * sizeof(int));

    for (int i = 0; i < ukuran; i++) {
        printf("\nMasukkan angka untuk indeks %d: ", i);
        scanf("%d", &nilai);
        push(nilai);
        system("cls"); 
        tampilkanTumpukan();
    }

    printf("\nTumpukan penuh. Tekan sembarang tombol untuk mulai menghapus elemen dari tumpukan...\n");
    getch(); 

    while (top != -1) {
        getch(); 
        system("cls"); 
        printf("Menghapus angka dari indeks %d: %d\n", top, pop());
        printf("Isi tumpukan sekarang:\n");
        tampilkanTumpukan();
        if (top != -1) {
            printf("\nTekan sembarang tombol untuk menghapus elemen berikutnya...\n");
        } else {
            printf("Tumpukan kosong.\n");
        }
    }

    free(tumpukan);
    return 0;
}

void push(int x) {
    if (top == ukuran - 1) {
        printf("\nOverflow!!");
    } else {
        tumpukan[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("\nUnderflow!!");
        return -1;
    } else {
        return tumpukan[top--];
    }
}

void tampilkanTumpukan() {
    if (top == -1) {
        printf("Tumpukan kosong.\n");
    } else {
        for (int i = top; i >= 0; i--) {
            if (i == top) {
                printf("indeks %d : %d (teratas)\n", i, tumpukan[i]);
            } else if (i == 0) {
                printf("indeks %d : %d (terbawah)\n", i, tumpukan[i]);
            } else {
                printf("indeks %d : %d\n", i, tumpukan[i]);
            }
        }
    }
}
