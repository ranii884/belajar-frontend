// Program Pencarian Bagi Dua (Binary Search) & Sequential Search
// 15 November 2025
// Nama : Siti Fatul Zahrani
// Nim : 241011401373

#include <iostream>
using namespace std;

// Deklarasi fungsi
void sequentialSearch(int data[], int d);
void binarySearch(int data[], int d);

// MAIN PROGRAM
int main() {
    int data[] = {10, 11, 12, 24, 30, 100};
    int d;

    cout << "data[] = ";
    for (int i = 0; i <= 5; i++) {
        cout << data[i] << "   ";
    }

    cout << "\nData yang dicari = ";
    cin >> d;

    cout << "\n=== Sequential Search ===\n";
    sequentialSearch(data, d);

    cout << "\n=== Binary Search ===\n";
    binarySearch(data, d);

    return 0;
}

// FUNGSI SEQUENTIAL SEARCH
void sequentialSearch(int data[], int d) {
    for (int i = 0; i <= 5; i++) {
        if (data[i] == d) {
            cout << "Data ditemukan pada index ke: " << i << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan" << endl;
}

// FUNGSI BINARY SEARCH
void binarySearch(int data[], int d) {
    int awal = 0, akhir = 5, c;

    while (awal <= akhir) {
        c = (awal + akhir) / 2;

        if (data[c] == d) {
            cout << "Data ditemukan pada index ke: " << c << endl;
            return;
        }
        else if (data[c] > d) {
            akhir = c - 1;
        }
        else {
            awal = c + 1;
        }
    }

    cout << "Data tidak ditemukan" << endl;
}
