#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char A[3][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','J'},
        {'K','L','M','N','O'}
    };

    char *P = &A[0][0]; // pointer ke elemen pertama array

    for (int i = 0; i < 3; i++) {       // baris
        for (int j = 0; j < 5; j++) {   // kolom
            cout << setw(2) << *P++;
        }
        cout << endl; // pindah baris
    }

    return 0;
}

