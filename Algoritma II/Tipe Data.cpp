#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel dengan berbagai tipe data
    int angka;           
    char huruf;          
    float pecahan;       
    double pecahan_ganda;
    bool benar_salah;       

    // Input dari pengguna
    cout << "Masukkan bilangan bulat: ";
    cin >> angka;
    
    cout << "Masukkan huruf: ";
    cin >> huruf;
    
    cout << "Masukkan bilangan pecahan: ";
    cin >> pecahan;
    
    cout << "Masukkan sebuah pecahan ganda : ";
    cin >> pecahan_ganda;
    
    cout << "Masukkan 1 untuk benar atau 0 untuk salah (bool): ";
    cin >> benar_salah;

    // Output nilai yang dimasukkan
    cout << "\nNilai yang Anda masukkan:" << endl;
    cout << "Int: " << angka << endl;
    cout << "Char: " << huruf << endl;
    cout << "Float: " << pecahan << endl;
    cout << "Double: " << pecahan_ganda << endl;
    cout << "Bool: " << (benar_salah ? "true" : "false") << endl;

    return 0;
}
