//浮点二分
//题目：
//给定一个浮点数n，求它的三次方根。
//输入格式
//共一行，包含一个浮点数n。
//输出格式
//共一行，包含一个浮点数，表示问题的解。
//注意，结果保留6位小数。
//数据范围
//−10000≤n≤10000
//输入样例：
//1000.00
//输出样例：
//10.000000

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