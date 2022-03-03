#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	//printf 
	printf("hello,world!\n");
	//Sleep(5000);                 //暂停5秒钟 
	int n=123;
	printf("%d\n",n);
	char c='+';
	printf("%c\n",c);
	float f=0.918;
	printf("%f\n",f);//%g 不会显示后面的000
	string s="i love you!";
	char *str="i hate you!";
	printf("%s\n",s.c_str());
	printf("%s\n",str);
	int a1=100,a2=10,a3=1000;
	printf("%-10d%-10d%-10d\n",a1,a2,a3);
	double d=3.141592653;
	printf("%.3lf\n",d);//小数点后三位，多余的采用四舍五入原则 
	
	
	//scanf
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);//同时输入多个数据，中间空格隔开    &取地址符号不要忘记 
	printf("%d %d %d\n",x,y,z);
	
	char letter;
    int age;
    char url[30];
    float price;
    scanf("%c",&letter);
    scanf("%d",&age);
    scanf("%s",url);
    scanf("%f",&price);
    printf("%c %d %s %g\n",letter,age,url,price);


	return 0;
 } 
