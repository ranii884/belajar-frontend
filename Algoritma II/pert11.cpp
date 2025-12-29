//Progra, pencarian bagidua data ascending
//15 november 2025
//Nama : Siti Fatul Zahrani 
//Nim : 241011401373

#include <iostream>
using namespace std;

int data[] = {10,11,12,24,30,100};
int awal, akhir, c, d;

void binarysearch();   // deklarasi fungsi

int main (){
    cout<< "data []= ";
    for (int i=0; i<=5; i++) 
        cout << data[i] << "   ";

    cout <<"\ndata yang dicari= "; 
    cin>>d;

    binarysearch();     // pemanggilan fungsi

    return 0;
}

void binarysearch (){

    awal = 0;
    akhir = 5;

    while (awal <= akhir){
        c = (awal + akhir)/2;

        if (data[c] == d){
            cout<<"Data ditemukan pada index ke: "<<c<<endl;
            break;
        }
        else if (data[c] > d){
            akhir = c - 1;
        }
        else{
            awal = c + 1;
        }
    }

    if (data[c] != d)
        cout<<"Data tidak ditemukan"<<endl;
}
