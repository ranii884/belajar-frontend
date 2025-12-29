#include<iostream>
using namespace std;
int main ()
{
	char huruf ='A';
	char angka = '5';
	char simbol = '#';

cout << "variabel huruf :" <<huruf << endl;
cout << "Nilai :" << angka <<endl;
cout << "Nilai ASCII :" << (int) huruf <<endl;
cout << "Alamat Memori :" << (void*) & huruf <<endl;


cout << "variabel angka :" << angka <<endl;
cout << "Nilai :" << angka<<endl;
cout << "Nilai ASCII :" << (int) huruf <<endl;
cout << "Alamat Memori :" << (void*) & huruf <<endl;

cout << "variabel simbol :" << simbol<<endl;
cout << "Nilai :" << angka<< endl;
cout << "Nilai ASCII :" << (int) huruf <<endl;
cout << "Alamat Memori :" << (void*) & huruf <<endl;

}
