#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream baca;
	string tampil;
	baca.open("data.txt");
	while (getline (baca,tampil))
	cout<<tampil<<endl;
	baca.close();
	

}