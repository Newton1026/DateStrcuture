//{0,5,3,4,6,2}时间复杂度O(n^2)
void InsertSort(SqList *L2){
	int i,j;
	for(i=2;i<L2->length;i++){
		if(L2->r[i]<L2->r[i-1]){//需将L2->r[i]插入有序子表
			L2->r[0]=L2->r[i];//设置哨兵
			for(j=i-1;L2->r[j]>L2->r[0];j--)
			L2->r[j+1]=L2->r[j];//记录后移
		L2->r[j+1]=L->r[0];//插入正确位置
		}
	}
}
