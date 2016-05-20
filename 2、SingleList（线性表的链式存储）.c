#define ERROR 0
#define OK    1
typedef int ElemType;
typedef int Status;
typedef struct Node{
	ElemType data;
	struct Node *next;
		}Node;
typedef struct Node *LinkList;
/*������Ķ�ȡ*/
Status GetElem(LinkList L,int i,ElemType *e){
	int j;
	LinkList p;/*����һ���p*/
	p = L->next;/*��pָ������L�ĵ�һ�����*/
	j = 1;/*jΪ������*/
	while(p && j<i){/*p��Ϊ�ջ��߼�������û����i,ѭ������*/
		p = p->next;
		++j;
		}
	if(!p||j>i)
		return ERROR;
	*e = p->data;
	return OK;
}
/*������Ĳ���*/
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
/*�������ɾ��*/
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
	m = b->next;/*��ɾ���Ľڵ�b->next��ֵ��m*/
	b->next = m->next;/*ɾ��*/
	*e = m->data;
	free(m);
	return OK;
}
/*����������䴴��_ͷ�巨*/
void CreateListHead(LinkList *L,int n){
	LinkList d;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*����һ����ͷ�ڵ�ĵ�����*/
	(*L)->next = NULL;
	for(i=0;i<n;i++){
		d = (LinkList)malloc(sizeof(Node));/*�����½ڵ�*/
		d->data = rand()%100+1;/*�������100���ڵ�����*/
		d->next = (*L)->next;
		(*L)->next = d;/*���뵽��ͷ*/
	}
}

/*����������崴��_β�巨*/
void CreateListTail(LinkList *L,int n){
	LinkList f,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*����һ����ͷ�ڵ�ĵ�����*/
	r = *L;/*rΪָ��β���Ľ��*/
	for(i=0;i<n;i++){
		f = (LinkList)malloc(sizeof(Node));/*�����½ڵ�*/
		f->data = rand()%100+1;/*�������100���ڵ�����*/
		r->next = f;
		r = f;/*���뵽��ͷ*/
	}
}

/*�����������ɾ��*/
Status ClearList(LinkList *L){
	LinkList p1,q1;
	p1 = (*L)->next;
	while(p1){/*û����β*/
		q1 = p1->next;
		free(p1);
		p1 = q1;
		}
	(*L)->next =NULL;
	return OK;
}
