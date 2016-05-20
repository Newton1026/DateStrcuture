void MergeSort(SqList1 *L){
	MSort(L->r,L->r,L->length);
		}

void MSort(int SR[],int TR1[],int s,int t){
	int m;
	int TR2[MAXSIZE+1];
	if(s = t)
		TR1[s] = SR[s];
	else {
		m = (s+t)/2;
		MSort(SR,TR2,s,m);
		MSort(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
		}
	}
void Merge(int SR[],int TR[],int i,int m,int n){
	int j,k,l;
	for(j=m+1;k<m&&j<=n;k++){
		if(SR[i]<SR[j]);
		else
			TR[k] = SR[j++];
		}
	if(i<m){
		for(l=0;l<=n-j;l++)
			TR[k+1]=SR[j+1];
		}
}