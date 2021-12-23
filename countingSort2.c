#include <stdio.h>

void countingSort(int A[], int B[], int n, int k){
	int C[k+1];
	for (int i = 0; i <= k; ++i)
	{
		C[i] = 0;
	}
    
	for (int i = 0; i < n; ++i)
	{
		C[A[i]]+=1;
	}

	for (int i = 1; i <= k; ++i)
	{
		C[i] += C[i-1];	
	}

	for (int j=n-1; j>=0; --j)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]] -= 1;
	}
}

int main()
{
	int n = 8;
	int A[8] = {2,15,33,0,25,33,0,23};
	int B[n];
	int k = A[0];
	for (int i = 1; i < n; ++i)
	{
		if (A[i] > k)
		{
			k = A[i];
		}
	}

	countingSort(A,B,n,k);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", B[i]);
	}

	return 0;
}