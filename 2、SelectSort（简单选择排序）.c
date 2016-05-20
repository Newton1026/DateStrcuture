//选择排序基本思想为每一趟在n-i+1个记录中选取关键字最小的记录作为有序
//序列的第i的记录
void SelectSort(SqList *L){
	int i,j,min;
	for(i=1;i<L->length;i++){
		min = i;
		for(j=i+1;j<L->length;j++){
			if(L->r[min]>L->r[j])
				min = j;
			}
		if(i!=min)
			swap(L,i,min);
		}
}
	
