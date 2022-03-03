#include<iostream>
using namespace std;
int main(){
	long year,year_copy;
	int n;
	cin>>year>>n;
	int str[4]={0,0,0,0};
	int count[10]={0,0,0,0,0,0,0,0,0,0};
	int index=3;
	int county=0;
	int flag=0;
	while(flag!=n){
		flag=0;
		year_copy=year;
		while(year_copy!=0){
			str[index]=year_copy % 10;
			year_copy = year_copy / 10;
			index--;
		}
		for(int i=0;i<4;i++){
			switch(str[i]){
				case 0:
					count[0]++;
					break;
				case 1:
					count[1]++;
					break;
				case 2:
					count[2]++;
					break;
				case 3:
					count[3]++;
					break;
				case 4:
					count[4]++;
					break;
				case 5:
					count[5]++;
					break;
				case 6:
					count[6]++;
					break;
				case 7:
					count[7]++;
					break;
				case 8:
					count[8]++;
					break;
				case 9:
					count[9]++;
					break;
			}
		}
		for(int j=0;j<10;j++){
			if(count[j]>0)flag++;
		}
		year++;
		county++;
	}
	cout<<year<<" "<<county;
	return 0;
}
