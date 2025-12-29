// class -> komponen, 1. data member, 2. member function/method
// berdasarkan parameter dan return, maka -> method terdiri
//1. method tanpa parameter dan tanpa return, void display()
//2. method tanpa parameter dan dengan return
//3. method dengan parameter dan tanpa return
//4. method dengan parameter dan dengan return

#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
	public:
		string nama;
		string NIM;
		float UTS;
	mahasiswa (string inputnama, string inputNIM, float inputUTS){
		mahasiswa::nama = inputnama;
		mahasiswa::NIM = inputNIM;
		mahasiswa::UTS = inputUTS;	
	}
	//1. method tanpa parameter dan tanpa return
	void show(){
		cout<<"Nama	: "<<nama<<endl;
		cout<<"NIM	: "<<NIM<<endl;
		cout<<"UTS	: "<<UTS<<endl<<endl;
	}
	//2. method tanpa parameter dan dengan return 
	string tampilannama (){
		return nama;
	}
	float tampilkanUTS (){
		return UTS;
	}
	//3. method dengan parameter dan tanpa return
	void ubahnama( string namabaru ){
		mahasiswa :: nama = namabaru;
	}
	void ubahUTS (float UTSbaru){
		mahasiswa :: UTS = UTSbaru;
	}
	//4. method dengan parameter dan dengan retun
	float koreksiUTS (float koreksi){
		return UTS = UTS + koreksi;
	}
		
};
int main (){
	mahasiswa mhs1 = mahasiswa("Siti Fatul Zahrani", "241011401373", 100); //constructor
	mahasiswa mhs2 ("Tu Baroah", "241011401356", 99); //constructor lebih mudah
	mahasiswa mhs3 ("Nabila Nazwa", "241011401010", 88);
	mhs1.show();
	mhs2.show();
	mhs3.show();
	
	cout<< "Nama Mahasiwa1 : "<< mhs1.tampilannama()<<endl;
	cout<< "UTS Mahasiswa2 : "<< mhs2.tampilkanUTS()<<endl<<endl;
	
	mhs1.ubahnama("Keysha Nisrina");
	mhs1.ubahUTS(78);
	mhs1.show();
	
	mhs3.koreksiUTS(10);
	mhs3.show();
		return 0;
}










