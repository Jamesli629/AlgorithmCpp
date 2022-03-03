#include<iostream>
using namespace std;
int main()
{
	int* array;
	array=new int[10];
	for(int i=0;i<10;++i)
		cin>>array[i];
	for(int j=0;j<10;++j)
		cout<<array[j]<<" ";
	cout<<endl;
	delete[] array;
	return 0;
}