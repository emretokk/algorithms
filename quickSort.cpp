#include <iostream>
using namespace std;

int PARTITION(int A[], int p, int r){
	int pivot = A[r];
	int i = p-1;
	for (int j = p; j<r; ++j){
		if (A[j] <= pivot)
		{
			i++;
			// SWAP A[i] with A[j]
			int temp;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	// SWAP A[i+1] with A[r] (pivot)
	int temp;
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;
}

void quickSort(int A[], int p, int r){
	if (p<r)
	{
		int q = PARTITION(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	int A[8] = {12,11,10,7,7,7,6,5};
	
	quickSort(A,0,7);

	for (int i = 0; i < 8; ++i)
	{
		cout << A[i] << " ";
	}
	return 0;
}