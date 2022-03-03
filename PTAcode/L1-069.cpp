#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int round[4],lev,minus;
    for(int i=0;i<4;i++){
        scanf("%d",&round[i]);
    }
    cin>>lev>>minus;
    int count=0,locate;
    sort(round,round+4,cmp);
    int max_r=round[0];
    for(int i=0;i<4;i++){
        if(max_r-round[i]>lev || round[i]<minus){
            count++;
            locate=i;
        }
    }
    if(count=0){
        cout<<"Normal\n";
    }
    else if(count==1){
        printf("Warning: please check #%d!\n",locate);
    }
    else{
        printf("Warning: please check all the tires!\n");
    }
    return 0;
}