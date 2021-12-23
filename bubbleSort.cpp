#include <iostream>
using namespace std;

void bubbleSort(int A[], int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = n-1; j>i; --j)
			{
				if (A[j] < A[j-1])
				{
					int temp;
					temp = A[j];
					A[j] = A[j-1];
					A[j-1] = temp;
				}
			}	
	}
}

int main()
{
	int n=8;
	int A[n] = {23,23,4,5,6,2,1,34};

	bubbleSort(A,n);

	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}

	return 0;
}