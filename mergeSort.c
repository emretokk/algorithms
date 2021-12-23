#include <stdio.h>

void MERGE(int A[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1];
	int R[n2+1];
	for (int i=0;i<n1;++i)
	{
		L[i] = A[p+i];
	}
	for (int i=0;i<n2;++i)
	{
		R[i] = A[q+1 +i];
	}
	L[n1] = 2147483647;
	R[n2] = 2147483647;

	int i=0;
	int j=0;
	for (int k=p; k<=r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int A[], int p, int r){
	if (p<r)
	{   
		int q = (p + r) /2;
		mergeSort(A,p,q); 	
		mergeSort(A,q+1,r);
		MERGE(A,p,q,r);
	}
}

int main(){
	int A[11] = {5,2,46,76,12214,3,2,6,1231,214,31};

	mergeSort(A,0,10);

	for (int i = 0; i < 11; ++i)
	{
		printf("%d ",A[i]);
	}
	return 0;
}