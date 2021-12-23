#include <stdio.h>

void countingSort(int A[], int B[], int n, int max){
	int C[max+1];
	for (int i = 0; i <= max; ++i)
	{
		C[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		C[A[i]] += 1;
	}

	for (int i = 1; i <= max; ++i)
	{
		// It helps in placing the elements 
		// into the correct index of the sorted array.
		C[i] += C[i-1];
	}

	for (int i = n-1; i >= 0; --i)
	{
		B[C[A[i]] - 1] = A[i];// Elemanların doğru yerini bulup yerleştiriyor.
		C[A[i]] -= 1;
	}
}

int main()
{
	int n = 10;
	int A[10] = {23, 12, 3, 2, 30, 3, 5, 12, 23, 16};
	int B[n];
	int max = A[0];
	for (int i = 1; i < n; ++i)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}

	countingSort(A, B, n, max);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", B[i]);
	}
	return 0;
}