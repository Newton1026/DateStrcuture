#define MAX_TREE_SZIE 100
/*˫�ױ�ʾ��*/
typedef int TElemType;
typedef struct PTNode{
	TElemType data;/*�������*/
	int parent;/*˫��λ��*/
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SZIE];
	int r,n;/*����λ�úͽ����*/
}PTree;

/*���ӱ�ʾ��*/
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct/*��ͷ�ṹ*/
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct{/*���ṹ*/
	CTBox nodes[MAX_TREE_SZIE];//�������
	int r,n;/*����λ�úͽ����*/
}CTree;

/*���ĺ����ֵܱ�ʾ��*/
typedef struct CSNode{
	TElemType data;
	struct CSNode *firstChild,*rigthSib;
}CSNode,*CSTree;
	
