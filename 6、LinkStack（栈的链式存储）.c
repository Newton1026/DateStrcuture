typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack{
	LinkStackPtr top;
	int conunt;
}LinkStack;

StackNode Push1(LinkStack *S,SElemType e){
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next=S->top;
	S->top=s;
	S->conunt++;
	return OK;
}

Status Pop1(LinkStack *S,SElemType *e){
	LinkStackPtr p;
	if(StackEmpty(*S))
		return ERROR;
	*e=S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	S->conunt--;
	return OK;
	
}