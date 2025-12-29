#include <iostream>
using namespace std;

void swapData(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi partition
int partitionData(int A[], int low, int high) {
    int pivot = A[high];  // pivot ambil elemen paling kanan
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            swapData(A[i], A[j]);
        }
    }
    swapData(A[i + 1], A[high]);
    return i + 1;
}

// Quick Sort rekursif
void quickSort(int A[], int low, int high, int n) {
    if (low < high) {
        int pi = partitionData(A, low, high);

        // Print langkah
        cout << "Pivot: " << A[pi] << " => ";
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        quickSort(A, low, pi - 1, n);
        quickSort(A, pi + 1, high, n);
    }
}

int main() {
    int A[] = {24, 10, 11, 40, 13, 73};
    int n;

    cout << "Data sebelum diurutkan\n";
    n = sizeof(A) / sizeof(*A);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "\nData setelah diurutkan (dengan langkah-langkah)\n";
    quickSort(A, 0, n - 1, n);

    return 0;
}
