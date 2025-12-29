#include<iostream>
using namespace std;

int genap(int);  
int kali(int x, int y);  
int main() {
    int a;  
    int i = 1;  
    char lagi; 
    
    do {
        cout << "Masukkan bilangan genap ke-" << i << " : ";  
        cin >> a; 
        
        cout << "Bilangan genap ke " << a << " adalah " << genap(a) << endl;  
      
        if (a > 0) {  
            cout << "\nHasil " << a << " * " << (a-1) << " adalah " << kali(a, a-1) << "\n(dihitung sebagai " << a << " ditambahkan " << (a-1) << " kali)" << endl;
        } else {
            cout << "\n Tidak bisa menghitung " << a << " * " << (a-1) << " karena a-1 negatif." << endl;
        }
        
        cout << "\nMau lanjut (y/n)=>";  
        cin >> lagi;  
        i++;  
    } while(i <= 5);  
    return 0; 
}

int genap(int n) {
    if (n == 1) return 0;  
    return (genap(n - 1) + 2);  
}
// Definisi fungsi kali: Menghitung x * y dengan penambahan berulang
int kali(int x, int y) {
    int hasil = 0;  
    for(int i = 0; i < y; i++) {  
        hasil += x;  
    }
    return hasil;  
}
