typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode{/*���������洢���ṹ*/
	TElemType data;
	struct BiThrNode *lchild,*rchild;/*���Һ���ָ��*/
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre;
/*���������������������*/
void InThreading(BiThrTree P){
	if(P){
		InThreading(P->lchild);/*�ݹ�������������*/
		if(!P->lchild){
			P->LTag = Thread;
			P->lchild = pre;
			}
		if(!pre->rchild){
			pre->RTag = Thread;
			pre->rchild = P;
			}
		pre = P;
		InThreading(P->rchild);/*�ݹ�������������*/
		}
}