//fstream -> merupakan file header --> i/o ditampilkan di file (ifstream, ofstream)
//iostream -> input output ditampilkan dimonitor (cin, cout)

#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ofstream tulis; //deklarasi objek
	tulis.open("data.txt", ios::out);
	tulis<< "saya cantik sekali"<<endl;
	tulis<<"saya bahagia, saya sehat, saya berharga"<<endl;
	tulis.close();
	
	ifstream baca;
	string tampil;
	baca.open("data.txt");
	while (getline (baca,tampil))
	cout<<tampil<<endl;
	baca.close();
	
	return 0;
}