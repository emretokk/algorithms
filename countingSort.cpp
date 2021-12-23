#include <iostream>
using namespace std;

void countingSort(int A[], int B[], int n, int k){
    // Initialize count array with all zeros.
	int C[k+1];
	for (int i = 0; i <= k; ++i)
	{
		C[i] = 0;
	}
    
    // Store the count of each element
	for (int i = 0; i < n; ++i)
	{
		C[A[i]]+=1;
	}

	// Store the cummulative count of each array
	for (int i = 1; i <= k; ++i)
	{
		C[i] += C[i-1];	
	}

	for (int j=n-1; j>=0; --j) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]] -= 1;
	}
}

int main()
{
	int n = 8;
	int A[n] = {2,15,33,0,25,33,0,23};
	int B[n];
	// k is the max value of A
	int k = A[0];
	// finds the max num
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
		cout << B[i] << " ";
	}

	return 0;
}