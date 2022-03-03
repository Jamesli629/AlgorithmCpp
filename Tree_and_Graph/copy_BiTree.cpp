//¸´ÖÆ¶ş²æÊ÷
int CopyBiTree(BiTree &T,BiTree &NewT){
	if(T==NULL){
		NewT = NULL;
		return 0;
	}
	else{
		NewT = new BiTNode;
		NewT->data = T->data;
		CopyBiTree(T->lchild,NewT->lchild);
		CopyBiTree(T->rchild,NewT->rchild);
	}
	return 0;
}
