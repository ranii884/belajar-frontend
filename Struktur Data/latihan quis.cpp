// insertion sort
#include <iostream>
using namespace std;

int main() {
    int A[] = {24, 10, 11, 40, 13, 73};
    int n;

    cout << "Data sebelum diurutkan\n";
    n = sizeof(A) / sizeof(*A); // jumlah elemen array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Logika insertion sort
    cout << "\nData setelah diurutkan\n";
    for (int i = 1; i < n; i++) {
        int key = A[i];   // elemen yang akan disisipkan
        int j = i - 1;

        // Geser elemen yang lebih besar dari key
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        // Sisipkan key ke posisi yang benar
        A[j + 1] = key;

        // Print langkah (untuk melihat proses)
        cout << "i= " << i << " => ";
        for (int l = 0; l < n; l++) {
            cout << A[l] << " ";
        }
        cout << endl;
    }

    return 0;
}
