#include<iostream>
using namespace std;
int main ()
{
	int x,y;
	int *px, *py;
	px= &x;
	py= &y;
	x= 4;
	y= 7;
	
cout<< "nilai x =" << x <<endl;
cout<< "nilai *px =" << *px <<endl;
cout<< "nilai px =" << px <<endl;

cout<< "nilai y =" << y <<endl;
cout<< "nilai *py =" << *py <<endl;
cout<< "nilai py =" << py <<endl;

}
