typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode{/*二叉线索存储结点结构*/
	TElemType data;
	struct BiThrNode *lchild,*rchild;/*左右孩子指针*/
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre;
/*中序遍历进行中序线索化*/
void InThreading(BiThrTree P){
	if(P){
		InThreading(P->lchild);/*递归左子树线索化*/
		if(!P->lchild){
			P->LTag = Thread;
			P->lchild = pre;
			}
		if(!pre->rchild){
			pre->RTag = Thread;
			pre->rchild = P;
			}
		pre = P;
		InThreading(P->rchild);/*递归右子树线索化*/
		}
}