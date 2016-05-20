/*二叉数的二叉链表结点结构*/
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*AB#D##C## #表示空数*/
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
		(*T)->data = ch;/*生成根结点*/
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
		}
}

/*二叉数的前序遍历递归算法*/
void PreOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
/*二叉数的中序遍历递归算法*/
void InOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}
/*二叉数的后序遍历递归算法*/
void PostOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}


