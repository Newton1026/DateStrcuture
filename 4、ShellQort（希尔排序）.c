void ShellSort(SqList1 *L){
	int i,j;
	int increment = L->length;
	do{
		increment = increment/3+1;//��������
		for(i=increment+1;i<=L->length;i++){
			if(L->r[i]<L->r[i-increment]){//�轫L->r[i]���뵽���������ӱ�
				L->r[0]=L->r[i];//�ݴ���L-r[0]
				for(j=i-increment;j>0&&L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j];//��¼���ƣ����Ҳ���λ��
				L->r[j+increment]=L->r[0];//����
				}
			}
		}
	while(increment>1);//��ֹ����
}
