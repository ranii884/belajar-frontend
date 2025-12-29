#include <iostream>
#include <iostream>
using namespace std;

class Buku{
	public:
	string judul;
	string namaPengarang;
	string TahunTerbit;
	//ini adalah konstruktor buku ---> method yang pertama kali di eksekusi
	Buku (string inputjudul, string inputnamaPengarang, string inputTahunTerbit){
	this->judul = inputjudul;
	this->namaPengarang = inputnamaPengarang;
	this->TahunTerbit = inputTahunTerbit;
	
	cout<<"Judul Buku :"<<judul<<endl;
	cout<<"Nama Pengarang : "<<namaPengarang<<endl;
	cout<<"Tahun Terbit : "<<TahunTerbit<<endl;
	cout<<"\n";
		
	}
};
int main (){
	Buku buku1 = Buku("Matematika Diskrit", "Sartika", "2016");
	Buku buku2 = Buku("Algoritma Pemrograman", "ir.Kussigit", "2020");
	return 0;
}

