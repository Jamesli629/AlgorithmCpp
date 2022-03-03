#include<iostream>
using namespace std;
int* createArray(int & num)
{
	int length;
	cout<<"请输入数组的长度："<<endl;
	cin>>length;
	num=length;
	int* array=new int[length];
	for(int i=0;i<length;++i){
		cout<<"输入数组的第"<<i<<"个数"<<endl;
		cin>>array[i];
	}
	return array;
}
void printArray1(int* arr,int num)
{
	for(int i=0;i<num;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void printArray2(int* arr,int num)
{
	for(int i=0;i<num;++i)
		cout<<*(arr+i)<<" ";
	cout<<endl;
}
void deleteArray(int* arr)
{
	delete[] arr;
}
int main()
{
	int* test;
	int n;
	test=createArray(n);
	printArray1(test,n);
	printArray2(test,n);
	deleteArray(test);
	printArray1(test,n);
	return 0;
}