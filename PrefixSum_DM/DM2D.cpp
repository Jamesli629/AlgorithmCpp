//二维差分
#include<cstdio>
using namespace std;
const int N=1e3+10;
int a[N][N],b[N][N];
int n,m,q;
void insert(int x1,int y1,int x2,int y2,int c){//将二维数组（x1,y1）到（x2,y2）加c
    b[x1][y1]+=c;
    b[x1][y2+1]-=c;
    b[x2+1][y1]-=c;
    b[x2+1][y2+1]+=c;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]); 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];//构造二维差分数组
        }
    }
    int x1,x2,y1,y2,c;
    while(q--){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];//让b数组变成前缀和数组以求改变后的数组
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}