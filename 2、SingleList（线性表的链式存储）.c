#define ERROR 0
#define OK    1
typedef int ElemType;
typedef int Status;
typedef struct Node{
	ElemType data;
	struct Node *next;
		}Node;
typedef struct Node *LinkList;
/*单链表的读取*/
Status GetElem(LinkList L,int i,ElemType *e){
	int j;
	LinkList p;/*声明一结点p*/
	p = L->next;/*让p指向链表L的第一个结点*/
	j = 1;/*j为计数器*/
	while(p && j<i){/*p不为空或者计数器还没等于i,循环继续*/
		p = p->next;
		++j;
		}
	if(!p||j>i)
		return ERROR;
	*e = p->data;
	return OK;
}
/*单链表的插入*/
Status ListInsert(LinkList *L,int i,ElemType e){
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p &&j < i){
		p = p->next;
		++j;
		}
	if(!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s ->data = e;
	s ->next = p ->next;
	p ->next = s;
	return OK;
}
/*单链表的删除*/
Status ListDelete(LinkList *L,int i,ElemType e){
	int j;
	LinkList b,m;
	b = *L;
	j = 1;
	while(b &&j < i){
		b = b->next;
		++j;
		}
	if(!b || j > i)
		return ERROR;
	m = b->next;/*欲删除的节点b->next赋值给m*/
	b->next = m->next;/*删除*/
	*e = m->data;
	free(m);
	return OK;
}
/*单链表的整变创建_头插法*/
void CreateListHead(LinkList *L,int n){
	LinkList d;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*建立一个带头节点的单链表*/
	(*L)->next = NULL;
	for(i=0;i<n;i++){
		d = (LinkList)malloc(sizeof(Node));/*生成新节点*/
		d->data = rand()%100+1;/*随机生成100以内的数字*/
		d->next = (*L)->next;
		(*L)->next = d;/*插入到表头*/
	}
}

/*单链表的整体创建_尾插法*/
void CreateListTail(LinkList *L,int n){
	LinkList f,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*建立一个带头节点的单链表*/
	r = *L;/*r为指向尾部的结点*/
	for(i=0;i<n;i++){
		f = (LinkList)malloc(sizeof(Node));/*生成新节点*/
		f->data = rand()%100+1;/*随机生成100以内的数字*/
		r->next = f;
		r = f;/*插入到表头*/
	}
}

/*单链表的整体删除*/
Status ClearList(LinkList *L){
	LinkList p1,q1;
	p1 = (*L)->next;
	while(p1){/*没到表尾*/
		q1 = p1->next;
		free(p1);
		p1 = q1;
		}
	(*L)->next =NULL;
	return OK;
}
