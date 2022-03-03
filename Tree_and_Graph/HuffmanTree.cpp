//哈夫曼算法：
//1.构造只有根结点的森林，个数为带权值的个数
//2.选取其中两个最小的构成新树
//3.删除两小添加新人
//4.重复2，3步骤，直到森林只有一棵树，即哈夫曼树 
#include<iostream>
using namespace std;

typedef struct{
	int weight;
	int parent,lch,rch;
}HTNode,*HuffmanTree;
HuffmanTree H;//一维结构数组

void CreateHuffmanTree(HuffmanTree HT,int n)
{
	if(n<=1)return;
	int m = 2n-1;
	HT = new HTNode[m+1];
	for(int i=1;i<=m;i++)
	{
		HT[i].lch=0;
		HT[i].parent=0;
		HT[i].rch=0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>HT[i].weight;
	}
	//初始化结束，下面开始建立哈夫曼树
	
	for(int i=n+1;i<=m;++i)
	{
		int s1,s2;
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lch=s1;
		HT[i].rch=s2;
		HT[i].weight = HT[s1].weight+HT[s2].weight;
	}
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)//编码 
{
	HC = new char*[n+1];
	char *cd = new char[n];
	cd[n-1]='\0';
	for(int i=1;i<=n;++i)
	{
		int start = n-1;
		int c = i;
		int f = HT[i].parent;
		while(f!=0){
			--start;
			if(HT[f].lch==c)cd[start]='0';
			else cd[start]='1';
			c=f;
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HT[i],&cd[start]);
	}
	delete cd;
}
