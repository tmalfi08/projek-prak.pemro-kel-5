// Evaluasi jawaban
        if (jawab == jawabanBenar[i]) {
            printf("\nJawaban benar! Anda memenangkan $%d.\n", hadiah[i]);
            hadiahAman = hadiah[i]; // Hadiah terakhir yang aman
        } else {
            printf("\nJawaban salah! Permainan berakhir.\n");
            break;
        }

        printf("Tekan ENTER untuk lanjut ke pertanyaan berikutnya...\n");
        getchar();
        getchar();
    }

    clearScreen();
    printLine();
    if (i == 5) {
        printf("Selamat! Anda memenangkan hadiah utama: $%d!\n", hadiah[4]);
    } else {
        printf("Anda membawa pulang hadiah aman sebesar: $%d\n", hadiahAman);
    }
    printLine();
    printf("Terima kasih telah bermain!\n");
}

// Fungsi utama
int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Gunakan program ini dengan:\n");
        printf("  ./program register <username> <password> -> untuk registrasi\n");
        printf("  ./program login <username> <password>    -> untuk login\n");
        return 0;
    }

    if (argc == 4) {
        if (strcmp(argv[1], "register") == 0) {
            // Registrasi pengguna baru
            registrasiPengguna(argv[2], argv[3]);
        } else if (strcmp(argv[1], "login") == 0) {
            // Login pengguna
            if (loginPengguna(argv[2], argv[3])) {
                printf("\nLogin berhasil! Mulai bermain kuis...\n");
                tampilkanPeraturan();
                mulaiQuiz();
            } else {
                printf("Login gagal, coba lagi!\n");
            }
        } else {
            printf("Perintah tidak dikenali. Gunakan 'register' atau 'login'.\n");
        }
    } else {
        printf("Format perintah salah.\n");
    }

    return 0;
}
