#include<iostream>
using namespace std;

int genap(int);  // Deklarasi fungsi genap
int Fakt(int);
int kali(int x, int y);

int main() {
    int a;  
    int i = 1;  
    char lagi;
    
    do {
        cout << "Masukkan bilangan genap ke-" << i << " : ";  // Meminta input untuk iterasi ke-i
        cin >> a; 
        cout << "Bilangan genap ke " << a << " adalah " << genap(a) << endl;
        cout<<"\n Nilai faktorial ke "<<a<< "adalah "<< Fakt(a);
        cout <<"\n mau lanjut (y/n)?"; cin>> lagi;
        i++;  
    } while(i <= 5);  // Loop berjalan selama i <= 5 (total 5 iterasi)
    
    return 0; 
}

// Definisi fungsi genap ke
int genap(int n) {
    if (n == 1) return 0; 
    return (genap(n - 1) + 2);  
}

// untuk mencari faktorial
int Fakt(int n) {
    if (n == 1) return 0; 
    return (Fakt(n - 1) * 2);  
}
