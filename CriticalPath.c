int *etv,*ltv;
int *Stack2;
int top2;
Status TopologicalSort(GraphAdjList GL){
	EdgeNode *e;
	int i,k,gettop;
	int top = 0 ;
	int count = 0;
	