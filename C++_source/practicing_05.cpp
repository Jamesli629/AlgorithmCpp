#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

typedef struct{//哈夫曼树结点结构 
	int weight;
	int parent,lch,rch;
}HTNode,*HuffmanTree;

//动态二维数组，存储哈夫曼编码
typedef char ** HuffmanCode;

void Select(HuffmanTree HT, int end, int &s1, int &s2)
{
    int min1, min2;
    //遍历数组初始下标为 1
    int i = 1;
    //找到还没构建树的结点
    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    min1 = HT[i].weight;
    s1 = i;
   
    i++;
    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    //对找到的两个结点比较大小，min2为大的，min1为小的
    if(HT[i].weight < min1){
        min2 = min1;
        s2 = s1;
        min1 = HT[i].weight;
        s1 = i;
    }else{
        min2 = HT[i].weight;
        s2 = i;
    }
    //两个结点和后续的所有未构建成树的结点做比较
    for(int j=i+1; j <= end; j++)
    {
        //如果有父结点，直接跳过，进行下一个
        if(HT[j].parent != 0){
            continue;
        }
        //如果比最小的还小，将min2=min1，min1赋值新的结点的下标
        if(HT[j].weight < min1){
            min2 = min1;
            min1 = HT[j].weight;
            s2 = s1;
            s1 = j;
        }
        //如果介于两者之间，min2赋值为新的结点的位置下标
        else if(HT[j].weight >= min1 && HT[j].weight < min2){
            min2 = HT[j].weight;
            s2 = j;
        }
    }
}

void CreateHuffmanTree(HuffmanTree &HT,int *w, int n)
{
	int i;
    if(n<=1) return; // 如果只有一个编码就相当于0
    int m = 2*n-1; // 哈夫曼树总节点数，n就是叶子结点
    HT = new HTNode[m+1]; // 0号位置不用
    HuffmanTree p = HT;
    
    //初始化
	for(i = 1; i <= n; i++)
    {
        p[i].weight= *(w+i-1);
        p[i].parent = 0;
        p[i].lch = 0;
        p[i].rch = 0;
    }
    for(i = n+1; i <= m; i++)
    {
        p[i].weight = 0;
        p[i].parent = 0;
        p[i].lch = 0;
        p[i].rch = 0;
    }
    //构建哈夫曼树
    for(i = n+1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i-1, s1, s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].lch = s1;
        HT[i].rch = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC,int n){
    HC = new char*[n+1];
    char *cd = new char[n+1]; //存放结点哈夫曼编码的字符串数组
    cd[n-1] = '\0';//字符串的结束符
   
    for(int i=1; i<=n; i++){
        //从叶子结点出发，得到的哈夫曼编码是逆序的，需要在字符串数组中逆序存放
        int start = n-1;
        //当前结点在数组中的位置
        int c = i;
        //当前结点的父结点在数组中的位置
        int j = HT[i].parent;
        // 一直寻找到根结点
        while(j != 0){
            // 如果该结点是父结点的左孩子则对应路径编码为0，否则为右孩子编码为1
            if(HT[j].lch == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            //以父结点为孩子结点，继续朝树根的方向遍历
            c = j;
            j = HT[j].parent;
        }
        //跳出循环后，cd数组中从下标 start 开始，存放的就是该结点的哈夫曼编码
        HC[i] = new char[n-start];
        strcpy(HC[i], &cd[start]);
    }
    //delete释放内存 
    delete (cd);
}
//打印哈夫曼编码的函数
void PrintHuffmanCode(HuffmanCode htable,int n)
{
    printf("Huffman code : \n");
    for(int i = 1; i <= n; i++)
        printf(" code = %s\n", htable[i]);
}

void Menu()
{
	cout<<"----------菜单----------"<<endl;
	cout<<"--------I:初始化--------"<<endl; 
	cout<<"---------E:编码---------"<<endl; 
	cout<<"---------D:解码---------"<<endl; 
	cout<<"-----P:打印代码文件-----"<<endl; 
	cout<<"-----T:打印哈夫曼树-----"<<endl;
	cout<<"---------Q:退出---------"<<endl;
}

void Initialization(HuffmanTree &htree,HuffmanCode &htable,int n,char* &c)
{
	int w[30];
	c=new char[n+1];
	cout<<"请输入字符集："<<endl;
	for(int i=0;i<n;++i)
	{
		cin>>c[i];
	}
	cout<<"请输入字符集对应的权值："<<endl;
	for(int i=0;i<n;++i)
	{
		cin>>w[i];
	}
	CreateHuffmanTree(htree,w,n);
	HuffmanCoding(htree,htable,n);
	ofstream outFile;
	outFile.open("HuffmanTree.txt",ios::out);
	for(int i=1;i<=n;i++)
	{
		outFile<<c[i-1]<<' '<<htree[i].parent<<' '<<htree[i].lch<<' '<<htree[i].rch<<endl;
	} 
	for(int i=n+1;i<=2*n-1;++i)
	{
		outFile<<'-'<<' '<<htree[i].parent<<' '<<htree[i].lch<<' '<<htree[i].rch<<endl;
	}
	outFile.close();
}

int Encoding(HuffmanCode htable,int n,char *c)
{
	char c1;
	ifstream inFile;
	inFile.open("ToBeTran.txt",ios::in);
	if(!inFile){
		cout<<"Error"<<endl;
		return -1;
	}
	ofstream outFile;
	outFile.open("CodeFile.txt",ios::out);
	while(inFile>>c1){
		for(int i=0;i<n;++i){
			if(c1==c[i]) outFile<<htable[i+1];
		}		
	}
	inFile.close();
	outFile.close();
	return 0;
}
void Decoding(HuffmanCode htable,int n,char *c){
	ifstream inFile;
	inFile.open("CodeFile.txt",ios::in);
	if(!inFile){
		cout<<"Error"<<endl;
		return ;
	}
	ofstream outFile;
	outFile.open("TextFile.txt",ios::out);
	int index=0;
	int num=1;
	string c1;
	inFile>>c1;
	string str;
	while(index<=c1.size()-1){
		str=c1.substr(index,num);//字符串切片操作 
		int i=0;
		while(i<n){
			if(str==htable[i+1]){
				outFile<<c[i];
				index=index+num;				
				num=0;
				break;
			}
			i++;
		}
		num++;	
	}				
	inFile.close();
	outFile.close();
}
void Print(){//打印二进制编码
	char c;
	int i=0; 
	ifstream inFile;
	inFile.open("CodeFile.txt",ios::in);
	ofstream outFile;
	outFile.open("CodePrin.txt",ios::out);
	while(inFile>>c){
		i++;
		cout<<c;
		outFile<<c;
		if(i==50){//每行50个代码 
			cout<<endl;
			outFile<<endl;
			i=0;	
		} 	
	}
	cout<<endl;
	inFile.close();
	outFile.close();
}
void cotree(int c[100][100],int s,int &m,int j,HuffmanTree htree){
	int a,b;
	m=m+1;
	a=m;
	for(b=0;b<s;b++){
		c[a][b]=-1;
	}
	c[a][b]=htree[j].weight;
	if(htree[j].lch){
		cotree(c,s+1,m,htree[j].lch,htree);
	}
	if(htree[j].rch){
		cotree(c,s+1,m,htree[j].rch,htree);
	}
} 
void Treeprinting(int n,HuffmanTree htree){//打印哈夫曼树 
	int c[100][100]={0};
	int m=0;	
	cotree(c,0,m,2*n-1,htree);
	ofstream outFile;
	outFile.open("TreePrint.txt",ios::out);
	for(int i=1;i<=2*n-1;++i){
		for(int j=0;c[i][j]!=0;++j){
			if(c[i][j]==-1){
				cout<<' ';
				outFile<<' ';
			}
			else{
				cout<<c[i][j]<<endl;
				outFile<<c[i][j]<<endl;
				break;
			}  
		}
	}
	outFile.close();
} 


int main(){
	int n;
	char *c;
	HuffmanTree htree;
    HuffmanCode htable;
	Menu();
	char c1;
	cin>>c1;
	while(c1!='Q'){
		switch(c1){
			case'I':{
				cout<<"请输入字符集的大小："<<endl;
				cin>>n;
				Initialization(htree,htable,n,c);
				cout<<"初始化完成！"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'E': {
				Encoding(htable,n,c);
				cout<<"编码完成！"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'D': {
				Decoding(htable,n,c);
				cout<<"解码完成！"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'P':{
				Print();
				cout<<"打印代码文件完成！"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'T':{
				Treeprinting(n,htree);
				cout<<"打印哈夫曼树完成！"<<endl;
				system("pause");
				system("cls");
				break;
			}				
		}
		Menu();
		cin>>c1;
	}			
    return 0;
}
