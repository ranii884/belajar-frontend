#include <iostream>
using namespace std;

// Deklarasi fungsi
int genap(int n);
int fakt(int n);
int kali(int x, int y);

int main() {
    char lagi;

    do {
        int k, x, y;

        cout << "\n=== PROGRAM REKURSIF GENAP, FAKTORIAL, DAN PERKALIAN ===\n";
        cout << "Masukkan bilangan genap ke- ";
        cin >> k;
        cout << "Masukkan bilangan x: ";
        cin >> x;
        cout << "Masukkan bilangan y: ";
        cin >> y;

        cout << "\n=== HASIL PERHITUNGAN ===";
        cout << "\nBilangan genap ke-" << k << " adalah : " << genap(k);
        cout << "\nNilai faktorial dari " << k << " adalah : " << fakt(k);
        cout << "\nHasil perkalian " << x << " x " << y << " = " << kali(x, y);

        cout << "\n\nIngin menghitung lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    cout << "\nProgram selesai.\n";
    return 0;
}

// Fungsi untuk mencari bilangan genap ke-n (rekursif)
int genap(int n) {
    if (n == 1) return 0;           // basis
    return 2 + genap(n - 1);        // rekurens
}

// Fungsi untuk menghitung faktorial (rekursif)
int fakt(int n) {
    if (n <= 1) return 1;           // basis
    return n * fakt(n - 1);         // rekurens
}

// Fungsi untuk menghitung perkalian dengan penjumlahan berulang (rekursif)
int kali(int x, int y) {
    if (y == 0) return 0;           // basis
    return x + kali(x, y - 1);      // rekurens
}

