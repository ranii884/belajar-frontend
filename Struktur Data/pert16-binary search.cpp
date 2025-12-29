#include <iostream>
using namespace std;

void cariNilai(int A[], int size, int N) {
    int low = 0, high = size - 1, mid, iter = 0;
    bool ketemu = false;

    cout << "\nMencari N = " << N << endl;
    cout << "Iter\tlow\thigh\tmid\tA[mid]\n";

    while (low <= high) {
        iter++;
        mid = (low + high) / 2;

        cout << iter << "\t" << low << "\t" << high << "\t"
             << mid << "\t" << A[mid] << endl;

        if (A[mid] == N) {
            ketemu = true;
            break;
        }
        else if (N > A[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (ketemu) {
        cout << "Nilai " << N << " ditemukan pada iterasi ke-" 
             << iter << ", index " << mid << endl;
    } else {
        cout << "Nilai " << N << " TIDAK ditemukan.\n";
    }
}

int main() {
    int A[10] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};

    cariNilai(A, 10, 17);   // Soal a
    cariNilai(A, 10, 22);   // Soal b

    return 0;
}
