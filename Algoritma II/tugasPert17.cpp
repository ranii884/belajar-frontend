#include<iostream>
#include<string>
using namespace std;
class TanpaConstructor{
	public:
		string judul;
		string pengarang;
		int terbit;
	//ini adalah method
	void tampilkan(){
		cout<<"Judul Buku : "<<judul<<endl;
		cout<<"Nama Pengarang : "<<pengarang<<endl;
		cout<<"Tahun Terbit : "<<terbit<<endl<<endl;
	}
};
class DenganConstructor{
	public:
		string judul;
		string pengarang;
		int terbit;
	DenganConstructor(string inputjudul, string inputpengarang, int inputterbit){
		DenganConstructor::judul = inputjudul;
		DenganConstructor::pengarang = inputpengarang;
		DenganConstructor::terbit = inputterbit;
	}
	void tampilkan(){
		cout<<"Judul Buku : "<<judul<<endl;
		cout<<"Nama Pengarang : "<<pengarang<<endl;
		cout<<"Tahun Terbit : "<<terbit<<endl<<endl;
	}
			
};
int main(){
	//1. pembentukan object tanpa constructor
	TanpaConstructor buku1;
	buku1.judul ="Algoritma pemograman";
	buku1.pengarang ="ir. kussigit";
	buku1.terbit= 2025;
	buku1.tampilkan();
	
	DenganConstructor buku2= DenganConstructor("matematika","rani", 2016);
	buku2.tampilkan();
	
	DenganConstructor buku3("jarkom","rivaldo",2019);
	buku3.tampilkan();
	
	DenganConstructor *buku4 = new DenganConstructor ("struktur data","baah", 2019);
	buku4->tampilkan();
	(*buku4).tampilkan();
	
	return 0;
}