//program squencial search
//Nama : Siti Fatul Zahrani
//Nim :241011401373
#include <iostream>
using namespace std;

int main(){
	char lagi;
	do{
		
	int data[]={10,2,12,4,30,100};
	int d, i, j, jml=6;
	
	cout<< "elemen data : ";
	for (int i=0 ;i<jml;i++){
		cout << data [i]<<" ";
	}
	cout<< "\n masukan nilai yang dicari: ";cin>> d;
	
	for (int i=0 ; i<6; i++){
		cout<< "cek data ["<< i << "] ="<< data [i];
		if (data [i] == d){
			cout<<" \n==> sama dengan "<< d<< "(ditemukan)"<<endl;
		} else{
			cout<< "\n==> tidak sama, lanjut ke elemen berikutnya.";
		}
	}
	for (int j=0 ; j<6; j++){
	cout<< "cek data ["<< j << "] ="<< data [j];
		if (j=-1)
		cout << "\nHasil data "<< d<< "berada pada index ke "<< j<<endl;
		else
		cout<< "\nHasil data "<< d<< "data tidak di temukan "<< j<<endl;
		cout<< "\n\nlagi?? (y/t)=" ; cin>> lagi;
	}
	while (lagi=='y');	
}
}


	
