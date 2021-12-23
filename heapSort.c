#include <stdio.h>

int LEFT(int i){
	return 2*i+1;
}

int RIGHT(int i){
	return 2*i+2;
}

void Heapify(int A[], int n, int i){
	int largest=i;
	int l=LEFT(i);
	int r=RIGHT(i);

	if (l < n && A[l] > A[largest])
	{
		largest = l;
	}

	if (r < n && A[r] > A[largest])
	{
		largest = r;
	}

	if (largest != i){
		int temp;
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;

		Heapify(A, n, largest);
	}
}

void buildMaxHeap(int A[], int n){
	for (int i=n/2-1;i>=0;--i)
	{
		Heapify(A, n, i);
	}
}

void heapSort(int A[], int n){
	buildMaxHeap(A, n);
	for (int i=n-1;i>=0;--i)
	{	
		int temp;
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		Heapify(A, i, 0);
	}
}

void main()
{
	int A[8] = {12,32,5,1,2,3,5,13};

	heapSort(A, 8);

	for (int i=0;i<8;++i)
	{
		printf("%d ",A[i]);
	}
}