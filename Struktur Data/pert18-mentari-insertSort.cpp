#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menampilkan array dalam bentuk kotak
void tampilKotak(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {24, 10, 11, 40, 13, 73};
    int n = arr.size();
    int swiping = 0;

    cout << "Gambaran Ilustrasi Insertion Sort\n";
    cout << "Data awal:\n";
    tampilKotak(arr);
    cout << "---------------------------------------\n";

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "Menyisipkan " << key << ":\n";

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swiping++;
            tampilKotak(arr); // tampilkan kondisi array saat terjadi shifting
        }

        arr[j + 1] = key;
        tampilKotak(arr); // tampilkan setelah key ditempatkan
        cout << "---------------------------------------\n";
    }

    cout << "Hasil akhir:\n";
    tampilKotak(arr);
    cout << "Total swiping: " << swiping << endl;

    return 0;
}
