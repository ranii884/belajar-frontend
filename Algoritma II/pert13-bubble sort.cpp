// Program Bubble Sort + Sequential Search + Binary Search
// Nama    : Siti Fatul Zahrani
// NIM     : 241011401373
// Tanggal : 12 November 2025

#include <iostream>
using namespace std;

// Deklarasi fungsi
void sequentialSearch(int data[], int n, int d);
void binarySearch(int data[], int n, int d);

int main() {
    int i, j, temp;
    int A[] = {9, 7, 8, 5, 6, 3, 4, 1, 2};
    int n = 9;
    int cari;

    cout << "Data sebelum diurutkan = ";
    for (i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\n\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    cout << "\n=== Sequential Search (sebelum diurutkan) ===\n";
    sequentialSearch(A, n, cari);

    // Proses Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    cout << "\nData setelah diurutkan = ";
    for (i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\n\n=== Sequential Search (setelah diurutkan) ===\n";
    sequentialSearch(A, n, cari);

    cout << "\n=== Binary Search (setelah diurutkan) ===\n";
    binarySearch(A, n, cari);

    return 0;
}

// Fungsi Sequential Search
void sequentialSearch(int data[], int n, int d) {
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (data[i] == d) {
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan\n";
}

// Fungsi Binary Search
void binarySearch(int data[], int n, int d) {
    int awal = 0, akhir = n - 1, tengah;
    bool ketemu = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;

        if (data[tengah] == d) {
            cout << "Data ditemukan pada indeks ke-" << tengah << endl;
            ketemu = true;
            break;
        }
        else if (data[tengah] > d) {
            akhir = tengah - 1;
        }
        else {
            awal = tengah + 1;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan\n";
}
