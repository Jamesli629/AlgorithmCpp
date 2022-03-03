//计算二叉树的深度
int Depth(BiTree T){//返回值是二叉树的深度 
	int left,right;
	if(T==NULL){
		return 0;
	}
	else{
		left = Depth(T->lchild);
		right = Depth(T->rchild);
		if(left>right)return (left+1);
		else return (right+1);
	}
}
