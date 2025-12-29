// Program Sequential Search
// Nama : Siti Fatul Zahrani
// NIM  : 241011401373

#include <iostream>
using namespace std;

int main() {
    char lagi;

    do {
        int data[] = {10, 2, 12, 4, 30, 100};
        int jml = 6;
        int d;
        bool ditemukan = false;
        int posisi = -1;

        cout << "Elemen data: ";
        for (int i = 0; i < jml; i++) {
            cout << data[i] << " ";
        }

        cout << "\nMasukkan nilai yang dicari: ";
        cin >> d;

        // proses pencarian
        for (int i = 0; i < jml; i++) {
            cout << "\nCek data[" << i << "] = " << data[i];
            if (data[i] == d) {
                cout << " --> Sama dengan " << d << " (Ditemukan)";
                ditemukan = true;
                posisi = i;
                break; // keluar dari loop kalau sudah ketemu
            } else {
                cout << " --> Tidak sama, lanjut ke elemen berikutnya.";
            }
        }

        // hasil pencarian
        if (ditemukan)
            cout << "\n\n==> Data " << d << " ditemukan pada indeks ke-" << posisi << endl;
        else
            cout << "\n\n==> Data " << d << " tidak ditemukan dalam array." << endl;

        cout << "\nLagi? (y/t): ";
        cin >> lagi;

    } while (lagi == 'y' || lagi == 'Y');

    cout << "\nProgram selesai.\n";
    return 0;
}

