#include<fstream>
#include<iostream>
using namespace std;

int main(){
	char data[100] = "i love C++!";
//	ofstream outfile;
//	outfile.open("test.txt");
//	cout << "Writing to the file" << endl;
//    cout << "Enter your name: ";
//    cin.getline(data,100);
//    outfile<<data<<endl;
//    outfile.close();
//    
//    ifstream infile;
//    infile.open("test.txt");
//    cout << "Reading from the file" << endl;
//    infile>>data;
//    
//    cout<<data<<endl;
//    infile>>data;
//    
//    cout<<data<<endl;
//    infile.close();
//	fstream fs;
//	fs.open("test1.txt",ios::in | ios::out | ios::trunc);
//	fs.write(data,15);
//	fs.close();

	int x,sum=0;
	ifstream isf;
	isf.open("01.txt",ios::in);
	ofstream osf;
	osf.open("result.txt",ios::out);
	while(isf>>x){
		sum+=x;
		osf<<x<<"-";
	}
	osf<<"sum = "<<sum;
	cout<<"sum = "<<sum<<endl;
	isf.close();
	osf.close();
    return 0;
}
