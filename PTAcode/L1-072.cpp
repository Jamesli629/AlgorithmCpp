#include<bits/stdc++.h>
using namespace std;
struct loc{
	int x;
	int y;
};
int oppo[19]={10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
int main(){
	int und[3][3];
	int temp=45,x,y;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>und[i][j];
			temp-=und[i][j];
			if(und[i][j]==0){
				x=i;
				y=j;
			}
		}
	}
	und[x][y]=temp;
	loc l[3];
	for(int i=0;i<3;i++){
		cin>>l[i].x>>l[i].y;
		l[i].x--;
		l[i].y--;
		cout<<und[l[i].x][l[i].y]<<endl;
	}
	int flag;
	cin>>flag;
	int ans=0;
	switch (flag)
	{
		case 1:
			for(int i=0;i<3;i++){
				ans+=und[0][i];
			}
			break;
		case 2:
			for(int i=0;i<3;i++){
				ans+=und[1][i];
			}
			break;
		case 3:
			for(int i=0;i<3;i++){
				ans+=und[2][i];
			}
			break;
		case 4:
			for(int i=0;i<3;i++){
				ans+=und[i][0];
			}
			break;
		case 5:
			for(int i=0;i<3;i++){
				ans+=und[i][1];
			}
			break;
		case 6:
			for(int i=0;i<3;i++){
				ans+=und[i][2];
			}
			break;
		case 7:
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i==j){
						ans+=und[i][j];
					}
				}
			}
			break;
		case 8:
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i+j==2){
						ans+=und[i][j];
					}
				}
			}
			break;
	}
	cout<<oppo[ans-6]<<endl;
	return 0;
}
