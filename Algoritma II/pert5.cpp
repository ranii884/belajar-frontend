#include <iostream>
#include <cmath> 
using namespace std;
// Deklarasi fungsi
int perkalian(int a, int b);
double pembagian(int a, int b);
int penjumlahan(int a, int b);
int pengurangan(int a, int b);
double akar(int a);

int main() {
    int x, y;
    int howmany; // jumlah perhitungan yang diinginkan

    cout << "Mau dihitung berapa kali? ";
    cin >> howmany;

    for (int i = 0; i < howmany; i++) {
        cout << "\n=== Perhitungan ke-" << i + 1 << " ===" << endl;

        cout << "Masukkan nilai x: ";
        cin >> x;
        cout << "Masukkan nilai y: ";
        cin >> y;

        cout << "\n=== HASIL PERHITUNGAN ===" << endl;
        cout << "Perkalian: " << perkalian(x, y) << endl;
        cout << "Pembagian: " << pembagian(x, y) << endl;
        cout << "Penjumlahan: " << penjumlahan(x, y) << endl;
        cout << "Pengurangan: " << pengurangan(x, y) << endl;

        cout << "\n=== HASIL AKAR KUADRAT ===" << endl;
        cout << "Akar dari " << x << " = " << akar(x) << endl;
        cout << "Akar dari " << y << " = " << akar(y) << endl;
    }
    return 0;
}

// Definisi fungsi
int perkalian(int a, int b) { return a * b; }

double pembagian(int a, int b) {
    if (b != 0) {
        return (double)a / b;
    } else {
        cout << "Error: Pembagian dengan nol tidak diperbolehkan!" << endl;
        return 0;
    }
}

int penjumlahan(int a, int b) { return a + b; }
int pengurangan(int a, int b) { return a - b; }

double akar(int a) {
    if (a < 0) {
        cout << "Error: tidak bisa menghitung akar bilangan negatif!" << endl;
        return -1;
    }
    return sqrt(a);
}

