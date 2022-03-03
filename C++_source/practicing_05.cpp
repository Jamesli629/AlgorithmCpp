#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

typedef struct{//�����������ṹ 
	int weight;
	int parent,lch,rch;
}HTNode,*HuffmanTree;

//��̬��ά���飬�洢����������
typedef char ** HuffmanCode;

void Select(HuffmanTree HT, int end, int &s1, int &s2)
{
    int min1, min2;
    //���������ʼ�±�Ϊ 1
    int i = 1;
    //�ҵ���û�������Ľ��
    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    min1 = HT[i].weight;
    s1 = i;
   
    i++;
    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    //���ҵ����������Ƚϴ�С��min2Ϊ��ģ�min1ΪС��
    if(HT[i].weight < min1){
        min2 = min1;
        s2 = s1;
        min1 = HT[i].weight;
        s1 = i;
    }else{
        min2 = HT[i].weight;
        s2 = i;
    }
    //�������ͺ���������δ���������Ľ�����Ƚ�
    for(int j=i+1; j <= end; j++)
    {
        //����и���㣬ֱ��������������һ��
        if(HT[j].parent != 0){
            continue;
        }
        //�������С�Ļ�С����min2=min1��min1��ֵ�µĽ����±�
        if(HT[j].weight < min1){
            min2 = min1;
            min1 = HT[j].weight;
            s2 = s1;
            s1 = j;
        }
        //�����������֮�䣬min2��ֵΪ�µĽ���λ���±�
        else if(HT[j].weight >= min1 && HT[j].weight < min2){
            min2 = HT[j].weight;
            s2 = j;
        }
    }
}

void CreateHuffmanTree(HuffmanTree &HT,int *w, int n)
{
	int i;
    if(n<=1) return; // ���ֻ��һ��������൱��0
    int m = 2*n-1; // ���������ܽڵ�����n����Ҷ�ӽ��
    HT = new HTNode[m+1]; // 0��λ�ò���
    HuffmanTree p = HT;
    
    //��ʼ��
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
    //������������
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
    char *cd = new char[n+1]; //��Ž�������������ַ�������
    cd[n-1] = '\0';//�ַ����Ľ�����
   
    for(int i=1; i<=n; i++){
        //��Ҷ�ӽ��������õ��Ĺ���������������ģ���Ҫ���ַ���������������
        int start = n-1;
        //��ǰ����������е�λ��
        int c = i;
        //��ǰ���ĸ�����������е�λ��
        int j = HT[i].parent;
        // һֱѰ�ҵ������
        while(j != 0){
            // ����ý���Ǹ������������Ӧ·������Ϊ0������Ϊ�Һ��ӱ���Ϊ1
            if(HT[j].lch == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            //�Ը����Ϊ���ӽ�㣬�����������ķ������
            c = j;
            j = HT[j].parent;
        }
        //����ѭ����cd�����д��±� start ��ʼ����ŵľ��Ǹý��Ĺ���������
        HC[i] = new char[n-start];
        strcpy(HC[i], &cd[start]);
    }
    //delete�ͷ��ڴ� 
    delete (cd);
}
//��ӡ����������ĺ���
void PrintHuffmanCode(HuffmanCode htable,int n)
{
    printf("Huffman code : \n");
    for(int i = 1; i <= n; i++)
        printf(" code = %s\n", htable[i]);
}

void Menu()
{
	cout<<"----------�˵�----------"<<endl;
	cout<<"--------I:��ʼ��--------"<<endl; 
	cout<<"---------E:����---------"<<endl; 
	cout<<"---------D:����---------"<<endl; 
	cout<<"-----P:��ӡ�����ļ�-----"<<endl; 
	cout<<"-----T:��ӡ��������-----"<<endl;
	cout<<"---------Q:�˳�---------"<<endl;
}

void Initialization(HuffmanTree &htree,HuffmanCode &htable,int n,char* &c)
{
	int w[30];
	c=new char[n+1];
	cout<<"�������ַ�����"<<endl;
	for(int i=0;i<n;++i)
	{
		cin>>c[i];
	}
	cout<<"�������ַ�����Ӧ��Ȩֵ��"<<endl;
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
		str=c1.substr(index,num);//�ַ�����Ƭ���� 
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
void Print(){//��ӡ�����Ʊ���
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
		if(i==50){//ÿ��50������ 
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
void Treeprinting(int n,HuffmanTree htree){//��ӡ�������� 
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
				cout<<"�������ַ����Ĵ�С��"<<endl;
				cin>>n;
				Initialization(htree,htable,n,c);
				cout<<"��ʼ����ɣ�"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'E': {
				Encoding(htable,n,c);
				cout<<"������ɣ�"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'D': {
				Decoding(htable,n,c);
				cout<<"������ɣ�"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'P':{
				Print();
				cout<<"��ӡ�����ļ���ɣ�"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case'T':{
				Treeprinting(n,htree);
				cout<<"��ӡ����������ɣ�"<<endl;
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
