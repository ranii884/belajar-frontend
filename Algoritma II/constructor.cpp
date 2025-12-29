#include<iostream>
#include<string>
using namespace std;
class TanpaConstructor{
	public:
		string nama;
		int umur;
};
class DenganConstructor{
	public:
		string nama;
		int umur;
	DenganConstructor(){
		cout<<"paldo jelek"<< endl;
		
	}
};
int main(){
//	DenganConstructor data;
//1. pembentukan object tanpa construktor
	TanpaConstructor data2;
	data2.nama = "rivaldo jelek banget";
	data2.umur =  60;
	cout<<"Nama	: "<<data2.nama<<endl;
	cout<<"umur	: "<<data2.umur<<endl;
	return 0;
}