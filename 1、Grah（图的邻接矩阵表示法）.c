typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct {
	VertexType vexs[MAXVEX];/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexes,numEdgees;//图中当前的顶点数和边数
}MGraph;
/*建立无向网图的邻接矩阵表示*/
void CreateMGraph(MGraph *G){
	int i,j,k,w;
	scanf("%d,%d",&G->numVertexes,&G->numEdgees);
	for(i=0;i<G->numVertexes;i++)
		scanf(&G->vexs[i]);
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;//邻接矩阵初始化
		for(k=0;k<G->numEdgees;k++)//权值w
			{
				scanf("%d,%d,%d",&i,&j,&k);
				G->arc[i][j]=w;
				G->arc[j][i]=w;
			}
	
}
/*建立无向网图的邻接表表示*/
typedef struct EdgeNode{/*边表结点*/
	int adjvex;//邻接点域，存储该顶点对应的下标
	EdgeType weigth;
	struct EdgeNode *next;//链域，指向下一个邻接点
}EdgeNode;
typedef struct VertexNode{//顶点表结点
	VertexType data;//顶点域，存储顶点信息
	EdgeNode *firstEdge;//边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int numVertexes,numEdges;//当前顶点数和边数
}GraphAdjList;

void CeateALGraph(GraphAdjList *G1){
	int i,j,k;
	EdgeNode *e;
	scanf("%d,%d",&G1->numVertexes,&G1->numEdgees);
	for(i=0;i<G1->numVertexes;i++){//读入顶点信息，建立顶点表
		scanf(&G1->adjList[i].data);//输入顶点信息
		G1->adjList[i].firstEdge=NULL;//将边表置为空表
		}
	for(k=0;k<G1->numEdges;k++){//建立边表
		scanf("%d,%d",&i,&j);//输入边(vi,vj)上的顶点序号
		e = (EdgeNode*)malloc(sizeof(EdgeNode));//生成边表结点
		e->adjvex = j;//邻接序号为j
		e->next = G1->adjList.firstEdge;//将e指针指向当前顶点指向的结点
		G1->adjList[i].firstEdge = e;//将当前顶点的指针指向e
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;//邻接序号为i
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
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关结点间边的权值
	lowcost[0] = 0;//初始化第一个权重为0，即v0加入生成树
	adjvex[0] = 0;//初始化第一个顶点下标为0
	for(i=1;i<G->numVertexes;i++){//循环除下标为0外的全部顶点
		lowcost[i] = G->arc[0][i];//将v0顶点与之有边的权值存入数组
		adjvex[i] = 0;//初始化都为v0的下标
	for(i = 1;i<G->numVertexes;i++){
		min = INFINITY;//初始化最小权值
		j = 1;
		k = 0;
		while(j<G->numVertexes)//循环全部顶点
			if(lowcost[j]!=0&&lowcost[j]<min){//如果权值不为0且小于min
				min = lowcost[j];//则让当前权值成为最小值
				k = j;//将当前最小值的下标存入k
				}
			j++;
		}
	printf("(%d,%d)",adjvex[k],k);//打印当前顶点边中权值最小边
	lowcost[k]=0;//将当前顶点的权值设置为0，表示此顶点已经完成任务
	for(j=1;j<G->numVertexes;j++){//循环所有顶点
		if(lowcost[j]!=0&&G->arc[k][j]<lowcost[j]){//若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
			lowcost[j] = G->arc[k][j];//将较小权值存入lowcost
			adjvex[j] = k;//将下标为k的顶点存入adjvex
			}
		}
	}
}