//浮点二分
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
double n;
int main(){
    cin>>n;
    double l=-1e4,r=1e4;
    while(r-l>eps){
        double m=(r+l)/2;
        if(m*m*m>=n){
            r=m;
        }
        else{
            l=m;
        }
    }
    printf("%.6lf",l);
    return 0;
}