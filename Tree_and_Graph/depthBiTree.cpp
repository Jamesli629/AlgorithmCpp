//��������������
int Depth(BiTree T){//����ֵ�Ƕ���������� 
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
