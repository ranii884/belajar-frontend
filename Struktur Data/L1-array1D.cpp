#include <iostream>
using namespace std;

int main() {
    int nilai[5] = {80, 85, 90, 75, 88};

    cout << "Daftar Nilai Mahasiswa:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }
    return 0;
}

