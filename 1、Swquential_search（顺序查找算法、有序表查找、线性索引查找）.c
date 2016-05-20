int Sequential_Search(int *a,int n,int key){
	int i;
	for(i=0;i<=n;i++){
		if(a[i]==key)
			return i;
		}
	return 0;
}

int Sequentia2_Search(int *a,int n,int key){
	int i;
	a[0] = key;
	i = n;
	while(a[i]!=key){
		i--;
		}
	return i;
}

int Binary_Search(int *a,int n ,int key){
	int low,high,mid;
	low = 1;
	high = n;
	while(low<=high){
		mid = (low+high)/2;
		if(key<a[mid])
			high = mid -1;
		else if (key>a[mid])
			low = mid + 1;
		else 
			return mid;
		}
	return 0;
}

