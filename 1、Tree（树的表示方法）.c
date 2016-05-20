#define MAX_TREE_SZIE 100
/*双亲表示法*/
typedef int TElemType;
typedef struct PTNode{
	TElemType data;/*结点数据*/
	int parent;/*双亲位置*/
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SZIE];
	int r,n;/*根的位置和结点数*/
}PTree;

/*孩子表示法*/
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct/*表头结构*/
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct{/*树结构*/
	CTBox nodes[MAX_TREE_SZIE];//结点数组
	int r,n;/*根的位置和结点数*/
}CTree;

/*树的孩子兄弟表示法*/
typedef struct CSNode{
	TElemType data;
	struct CSNode *firstChild,*rigthSib;
}CSNode,*CSTree;
	
