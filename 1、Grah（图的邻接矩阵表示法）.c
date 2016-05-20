typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct {
	VertexType vexs[MAXVEX];/*�����*/
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ���
	int numVertexes,numEdgees;//ͼ�е�ǰ�Ķ������ͱ���
}MGraph;
/*����������ͼ���ڽӾ����ʾ*/
void CreateMGraph(MGraph *G){
	int i,j,k,w;
	scanf("%d,%d",&G->numVertexes,&G->numEdgees);
	for(i=0;i<G->numVertexes;i++)
		scanf(&G->vexs[i]);
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;//�ڽӾ����ʼ��
		for(k=0;k<G->numEdgees;k++)//Ȩֵw
			{
				scanf("%d,%d,%d",&i,&j,&k);
				G->arc[i][j]=w;
				G->arc[j][i]=w;
			}
	
}
/*����������ͼ���ڽӱ��ʾ*/
typedef struct EdgeNode{/*�߱���*/
	int adjvex;//�ڽӵ��򣬴洢�ö����Ӧ���±�
	EdgeType weigth;
	struct EdgeNode *next;//����ָ����һ���ڽӵ�
}EdgeNode;
typedef struct VertexNode{//�������
	VertexType data;//�����򣬴洢������Ϣ
	EdgeNode *firstEdge;//�߱�ͷָ��
}VertexNode,AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int numVertexes,numEdges;//��ǰ�������ͱ���
}GraphAdjList;

void CeateALGraph(GraphAdjList *G1){
	int i,j,k;
	EdgeNode *e;
	scanf("%d,%d",&G1->numVertexes,&G1->numEdgees);
	for(i=0;i<G1->numVertexes;i++){//���붥����Ϣ�����������
		scanf(&G1->adjList[i].data);//���붥����Ϣ
		G1->adjList[i].firstEdge=NULL;//���߱���Ϊ�ձ�
		}
	for(k=0;k<G1->numEdges;k++){//�����߱�
		scanf("%d,%d",&i,&j);//�����(vi,vj)�ϵĶ������
		e = (EdgeNode*)malloc(sizeof(EdgeNode));//���ɱ߱���
		e->adjvex = j;//�ڽ����Ϊj
		e->next = G1->adjList.firstEdge;//��eָ��ָ��ǰ����ָ��Ľ��
		G1->adjList[i].firstEdge = e;//����ǰ�����ָ��ָ��e
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;//�ڽ����Ϊi
		e->next = G1->adjList[j].firstEdge;
		G1->adjList[j].firstEdge = e;
		}	
}
typedef int Boolean;
Boolean visited[MAX];
void DFS(MGraph G,int i){
	int j;
	visited[i] = TRUE;
	printf("%c",G->vexs[i]);
	for(j = 0;j<G->numVertexes;j++)
		if(G->arc[i][j]==1&&!visited[j])
			DFS(G,j);
}
void DFSTraverse(MGraph G){
	int i;
	for(i=0;i<G->numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G->numVertexes;i++)
		if(!visited[i])
			DFS(G,i);
}
void MiniSpanTree_Prim(MGraph G){
	int min,i,j,k;
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//������ؽ���ߵ�Ȩֵ
	lowcost[0] = 0;//��ʼ����һ��Ȩ��Ϊ0����v0����������
	adjvex[0] = 0;//��ʼ����һ�������±�Ϊ0
	for(i=1;i<G->numVertexes;i++){//ѭ�����±�Ϊ0���ȫ������
		lowcost[i] = G->arc[0][i];//��v0������֮�бߵ�Ȩֵ��������
		adjvex[i] = 0;//��ʼ����Ϊv0���±�
	for(i = 1;i<G->numVertexes;i++){
		min = INFINITY;//��ʼ����СȨֵ
		j = 1;
		k = 0;
		while(j<G->numVertexes)//ѭ��ȫ������
			if(lowcost[j]!=0&&lowcost[j]<min){//���Ȩֵ��Ϊ0��С��min
				min = lowcost[j];//���õ�ǰȨֵ��Ϊ��Сֵ
				k = j;//����ǰ��Сֵ���±����k
				}
			j++;
		}
	printf("(%d,%d)",adjvex[k],k);//��ӡ��ǰ�������Ȩֵ��С��
	lowcost[k]=0;//����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
	for(j=1;j<G->numVertexes;j++){//ѭ�����ж���
		if(lowcost[j]!=0&&G->arc[k][j]<lowcost[j]){//���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
			lowcost[j] = G->arc[k][j];//����СȨֵ����lowcost
			adjvex[j] = k;//���±�Ϊk�Ķ������adjvex
			}
		}
	}
}