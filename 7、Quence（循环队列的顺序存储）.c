typedef int QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q);{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue *Q,QElemType e)
{
	if((Q.rear+1)%MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}