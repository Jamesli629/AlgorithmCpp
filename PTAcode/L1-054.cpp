//������ 

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
    cin.ignore();                      //��ֹcin������Ļس����� 
    for (int i=0;i<n;i++)              //��¼��ԭ���ַ����ڵ�λ�ú�ת�������ڵ�λ�� 
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
    for(int i=0;i<n;i++)                     //�����ж�ת��ǰ���Ƿ�һ�� 
    {
        for(int j=0;j<n;j++)
        {
            if(store[i][j]!=arr[i][j])
                flag=false;
        }
    }
    if(flag)cout<<"bu yong dao le"<<endl;
    for(int i=0;i<n;i++)                   //��ӡ��ת������ַ���ʽ 
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)cout<<c;
            else cout<<" ";
        }
        cout<<endl;
    }
}
