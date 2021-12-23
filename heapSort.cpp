#include <bits/stdc++.h>
using namespace std;


int LEFT(int i){
	return 2*i+1;
}

int RIGHT(int i){
	return 2*i+2;
}

void maxHeapify(int A[], int n, int i){
	int largest=i;
	int l = LEFT(i);
	int r = RIGHT(i);

	/* DETECTS THE LARGEST NUMBER */
	if (l < n && A[l] > A[largest])
	{
		largest = l;
	}

	if (r < n && A[r] > A[largest])
	{
		largest = r;
	}

	/* SWAPS THE CURRENT root WITH largest if the root is not largest 
		and continues to heapify with the swapped child index
	*/
	if (largest != i)
	{
		int temp;
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;

		maxHeapify(A, n, largest);
	}
}

void buildMaxHeap(int A[], int n){
	// Build heap rearrange the array

	// The first index of a non-leaf node is given by n/2 - 1.
	// All other nodes after that are leaf-nodes and thus don't need to be heapified.
	for (int i = n/2-1; i >= 0; i--)
	{
		maxHeapify(A, n, i);
	}
}

void heapSort(int A[], int n){
	buildMaxHeap(A,n);
	for (int j = n-1; j >= 1; j--)
	{
		/* SWAP current Root to End of the array */
		int temp;
		temp = A[0];
		A[0] = A[j];
		A[j] = temp;

		// Heapify root element to get highest element at root again
		maxHeapify(A, j, 0);
	}
}
int main(){
	int A[8] = {12,11,10,7,7,7,6,5};

	heapSort(A, 8);

	for (int i = 0; i < 8; ++i)
	{
		cout << A[i] << " ";
	}
	
	return 0;
}