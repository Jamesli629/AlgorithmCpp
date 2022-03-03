//福到了 

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    int store[100][100];
    int arr[100][100];
    char c;
    int n;
    cin>>c>>n;
    string str="";
    cin.ignore();                      //防止cin将后面的回车读入 
    for (int i=0;i<n;i++)              //记录下原来字符所在的位置和转换后所在的位置 
    {
        getline(cin,str);
        for(int j=0;j<n;j++)
        {
            if(str[j]=='@'){
                store[i][j]=1;
                arr[n-i-1][n-j-1]=1;
            }
            else{
                store[i][j]=0;
                arr[n-i-1][n-j-1]=0;
            }
        }
    }
    bool flag=true;
    for(int i=0;i<n;i++)                     //用来判断转换前后是否一样 
    {
        for(int j=0;j<n;j++)
        {
            if(store[i][j]!=arr[i][j])
                flag=false;
        }
    }
    if(flag)cout<<"bu yong dao le"<<endl;
    for(int i=0;i<n;i++)                   //打印出转换后的字符样式 
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)cout<<c;
            else cout<<" ";
        }
        cout<<endl;
    }
}
