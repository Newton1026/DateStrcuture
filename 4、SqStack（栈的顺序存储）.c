#define MAXSIZE 20
typedef int SElemType;
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack;
/*��ջ*/
Status push(SqStack *S,SElemType e){
	if(S->top==MAXSIZE - 1){
		return ERROR;
		}
	S->top++;
	S->data[S->top] = e;
	return OK;
}
Status Pop(SqStack *S,ElemType *e){
	if(S->top==-1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
}