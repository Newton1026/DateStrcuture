#define MAXEDGE 15
#define MAXVEX 9
typedef struct{
	int begin;
	int end;
	int weigth;
}Edge;

void MiniSpanTree_Kruskal(MGraph G){
	int i,n,m;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];
	for(i=0;i<G->numVertexes;i++)
		parent[i] = 0;
	for(i=0;i<G->numEdgees;i++)
		{
			n = Find(parent,edges[i]->begin;
			m = Find(parent,edges[i]->end;
			if(n!=m){
				parent[n]=m;
				printf("(%d,%d)",edges[i]->begin,edges[i]->end,
					edges[i]->weigth);
				}
	}
}

int Find(int *parent,int f)
{
	while(parent[f]>0)
		f = parent[f];
	return f;
}