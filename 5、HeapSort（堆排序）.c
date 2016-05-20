//{50,10,90,30,70,40,80,60,20}
void HeapSort(SqList1 *L){
	int i;
	for(i=L->length/2;i>0;i--)//把L中的r构成一个大顶堆
	HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--){
		swap(L,1,i);
		HeapAdjust(L,1,i-1);
		}
}

void HeapAdjust(SqList1 *L,int s,int m){
	int temp,j;
	temp = L->r[s];
	for(j=2*s;j<=m;j*=2){
		if(j<m&&L->r[j]<L->r[j+1])
			++j;
		if(temp>L->r[j])
			break;
		L->r[s] = L->r[j];
		s = j;
		}
	L->r[s] = temp;//插入
}
