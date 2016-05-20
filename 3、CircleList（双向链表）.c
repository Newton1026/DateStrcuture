typedef struct DulNode{
ElemType data;
struct DulNode *prior;
struct DulNode *next;
}DulNode,*DuLinkList;
//将结点s插入到结点p和p->next之间
DuLinkList p,s;
s->prior = p;
s->next = p->next;
p->next->prior =s;
p->next = s;

//删除结点p
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);