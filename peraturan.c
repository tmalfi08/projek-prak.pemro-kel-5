
// Fungsi untuk menampilkan garis pemisah
void printLine() {
    printf("==========================================\n");
}

// Fungsi untuk menampilkan peraturan kuis
void tampilkanPeraturan() {
    clearScreen();
    printLine();
    printf("           SELAMAT DATANG DI HOLLY WINGS GAME !      \n");
    printLine();
    printf("Peraturan:\n");
    printf("1. Jawab setiap pertanyaan dengan memilih A, B, C, atau D.\n");
    printf("2. Setiap jawaban benar mendapatkan hadiah.\n");
    printf("3. Jika salah menjawab, permainan berakhir, dan hadiah Anda akan turun.\n");
    printf("4. Anda memiliki satu bantuan *50:50* untuk menghilangkan dua opsi yang salah.\n");
    printLine();
    printf("Tekan ENTER untuk memulai...\n");
    getchar();
}
