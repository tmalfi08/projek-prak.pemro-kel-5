#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur untuk pengguna
typedef struct {
    char username[50];
    char password[50];
} User;

// Prototipe fungsi login/registrasi
void registrasiPengguna();
int loginPengguna();
void menuLogin();

// Prototipe fungsi kuis
void clearScreen();
void printLine();
void tampilkanPeraturan();
void mulaiQuiz();

// Fungsi utama
int main() {
    int pilihan;

    do {
        menuLogin();
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus karakter newline dari buffer

        switch (pilihan) {
            case 1:
                registrasiPengguna();
                break;
            case 2:
                if (loginPengguna()) {
                    printf("\nLogin berhasil! Mulai bermain kuis...\n");
                    getchar(); // Menunggu input sebelum mulai kuis
                    tampilkanPeraturan();
                    mulaiQuiz();
                } else {
                    printf("Login gagal, coba lagi!\n");
                }
                break;
            case 3:
                printf("Program selesai, terima kasih!\n");
                break;
            default:
                printf("Pilihan salah, coba lagi!\n");
        }
    } while (pilihan != 3);

    return 0;
}

// Fungsi untuk menampilkan menu login/registrasi
void menuLogin() {
    printf("\n=== Sistem Login dan Registrasi ===\n");
    printf("1. Registrasi\n");
    printf("2. Login\n");
    printf("3. Keluar\n");
}

// Fungsi untuk registrasi pengguna baru
void registrasiPengguna() {
    FILE *file = fopen("login.bin", "ab");
    if (!file) {
        perror("Gagal membuka file");
        return;
    }

    User penggunaBaru;
    printf("Masukkan username: ");
    fgets(penggunaBaru.username, sizeof(penggunaBaru.username), stdin);
    strtok(penggunaBaru.username, "\n"); // Menghapus karakter newline
    printf("Masukkan password: ");
    fgets(penggunaBaru.password, sizeof(penggunaBaru.password), stdin);
    strtok(penggunaBaru.password, "\n"); // Menghapus karakter newline

    fwrite(&penggunaBaru, sizeof(User), 1, file);
    fclose(file);

    printf("Registrasi berhasil!\n");
}

// Fungsi untuk login pengguna
int loginPengguna() {
    FILE *file = fopen("login.bin", "rb");
    if (!file) {
        perror("Gagal membuka file");
        return 0;
    }

    char username[50], password[50];
    printf("Masukkan username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // Menghapus karakter newline
    printf("Masukkan password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // Menghapus karakter newline

    User pengguna;
    while (fread(&pengguna, sizeof(User), 1, file)) {
        if (strcmp(pengguna.username, username) == 0 &&
            strcmp(pengguna.password, password) == 0) {
            fclose(file);
            return 1; // Login berhasil
        }
    }

    fclose(file);
    return 0; // Login gagal
}

// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

