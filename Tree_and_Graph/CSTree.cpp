//一般树的存储和创建（孩子兄弟表示法） 
#include<iostream>
using namespace std;
typedef struct CSNode{
	int data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;

void createCSTree(CSTree &Tree)
{
	int c;
	cin>>c;
	if(c!='\n'){
		if(c=='#') Tree=NULL;
		else {
			Tree=new CSNode;
			Tree>data=c;
			createCSTree(Tree->firstchild);
			createCSTree(Tree->nextsibling);
		}
	}
}
int main(){
	return 0;
}
