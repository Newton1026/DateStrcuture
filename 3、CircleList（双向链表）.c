typedef struct DulNode{
ElemType data;
struct DulNode *prior;
struct DulNode *next;
}DulNode,*DuLinkList;
//�����s���뵽���p��p->next֮��
DuLinkList p,s;
s->prior = p;
s->next = p->next;
p->next->prior =s;
p->next = s;

//ɾ�����p
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);