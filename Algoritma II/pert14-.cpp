 #include <iostream>
 using namespace std;
 
 void selection_sort(int n);
 int main ()
 {
 	int A[]= {5,6,4,7,3,8,2,9,1};
 	int n;
 	int i,k,j;
 	cout << "data sebelum diurutkan\n";
 	n= sizeof(A)/sizeof (*A);
 	for (int i=0; i<n ;i++) cout << A[i]<<" ";
 	selection_sort(n);
 	cout<<endl;
 	cout<<"\ndata setelah diurutkan\n";
 	for (int i; i<n; i++)
 	{
 		int k=i;
 		for(int j=i;j<n; j++)
 		{
 			if(A[j]>A[k]);
			k=j;
		}
		swap (A[i], A[k]);
		cout<< endl;
		cout<<"i= "<<i<<" =>";
		for (int l=0; l<n; i++)
		cout <<A[1] << " ";
	}
 
 