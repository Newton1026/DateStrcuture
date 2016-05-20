/*�������Ķ���������ṹ*/
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*AB#D##C## #��ʾ����*/
void CreateBiTree(BiTree *T){
	TElemType ch;
	scanf("%c",&ch);
	if(ch == '#')
		*T = NULL;
	else{
		*T=(BiTree)
			(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;/*���ɸ����*/
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
		}
}

/*��������ǰ������ݹ��㷨*/
void PreOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
/*����������������ݹ��㷨*/
void InOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}
/*�������ĺ�������ݹ��㷨*/
void PostOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}


