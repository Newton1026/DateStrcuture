//{0,5,3,4,6,2}ʱ�临�Ӷ�O(n^2)
void InsertSort(SqList *L2){
	int i,j;
	for(i=2;i<L2->length;i++){
		if(L2->r[i]<L2->r[i-1]){//�轫L2->r[i]���������ӱ�
			L2->r[0]=L2->r[i];//�����ڱ�
			for(j=i-1;L2->r[j]>L2->r[0];j--)
			L2->r[j+1]=L2->r[j];//��¼����
		L2->r[j+1]=L->r[0];//������ȷλ��
		}
	}
}
