#define MAXSIZE 10
typedef struct{
	int r[MAXSIZE+1];
	int length;
}SqList1;
//ð�������˼����ǲ��ϵؽ�����ʱ�临�Ӷ�ΪO(n^2)
void swap(SqList1 *L,int i,int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
void BubbleSort0(SqList1 *L){
	int i,j;
	for(i =1;i<L->length;i++){
		for(j=i+1;j<L->length;j++){
			if(L->r[i]>L->r[j]){
				swap(L,i,j);
				}
			}
		}
}
//{9,1,5,8,3,7,4,6,2}
void BubbleSot(SqList1 *L){
	int i,j;
	for(i=1;i<L->length;i++){
		for(j=L->length-1;j>=i;j--){//j�Ӻ���ǰѭ��
			if(L->r[j]>L->r[j+1]){//��ǰ�ߴ��ں���
				swap(L,j,j+1);//����
				}
			}
		}
}

//{2,1,3,4,5,6,7,8,9}
void BublleSort2(SqList1 *L1){
	int i,j;
	Status flag = TRUE;
	for(i=1;i<L1->length&&flag;i++){//��flagΪtrue���˳�ѭ��
		flag =FALSE;//��ʼ��Ϊflase
		for(j=L1->length-1;j>=i;j--){
			if(L1->r[j]>L1->r[j+1]){
				swap(L1,j,j+1);//����
				flag = TRUE;//�����ݽ�������flagΪtrue
			}
		}
	}
}
