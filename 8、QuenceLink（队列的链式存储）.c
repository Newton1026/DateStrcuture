typedef int QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front,rear;
}LinkQueue;
/*插入元素e为Q的新的队尾元素*/
Status EnQueue1(LinkQueue* Q,QElemType e){
	QueuePtr s1 = (QueuePtr)malloc(sizeof(QNode));
	if(!s1)
		exit(OVERFLOW);
	s1->data = e;
	s1->next = NULL;
	Q->rear->next = s1;
	Q->rear = s1;
	return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e){
	QueuePtr p1;
	if(Q->front == Q->rear)
		return ERROR;
	p1=Q->front->next;
	*e = p1->data;
	Q->front->next=p1->next;
	if(Q->rear==p1)
		Q->rear=Q->front;
	free(p1);
	return OK;
}