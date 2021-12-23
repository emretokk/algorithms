#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void MERGE(int A[], int p, int q, int r){
	// Creating 2 subarray for comparison
	int n1 = q-p+1;
	int n2 = r-q;

	int L[n1+1];
	int R[n2+1];
	
	// Fills arrays
	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[p+i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[q+1 +i];
	}

	// Representing the max value of int data type

	// If you want to sort as decreasing you need to change these values into negative(-) and change
	// the <= into > in the comparison part
	L[n1] = 2147483647;
	R[n2] = 2147483647;


	// Comparison part
	// Loops both arrays elements and put the min value into main array.
	int i=0,j=0;
	
	for (int k = p; k <= r; ++k)
	{
		// If you want to sort as decreasing you need to change this expression into >
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

void MergeSort(int A[], int p, int r){
	// Divides array from half until the every array have 1 element.
	// 1 item is already sorted. Then we can merge until we got 2 subarrays of our main array and then
	// get the final sorted array.
	if (p<r)
	{
		int q = (p+r) / 2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		MERGE(A,p,q,r);
	}
}

void insertionSort(int A[], int n){
	for (int j=1;j<n;++j)
	{
		int key = A[j];
		int i = j-1;
		while(i>=0 && A[i] > key){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}

int main()
{
	int n1 = 100;
	int n2 = 100000;
	int diziMerge1[n1];
	int diziMerge2[n2];
	int diziInsert[n2];

	for (int i = 0; i < n1; ++i)
	{
		int rd = rand() % 100 +1;
		diziMerge1[i] = rd;
	}
	for (int i = 0; i < n2; ++i)
	{
		int rd = rand() % 100 +1;
		diziMerge2[i] = rd;
		diziInsert[i] = rd;
	}

	clock_t startInsert, finishInsert;
	clock_t startMerge1, finishMerge1;
	clock_t startMerge2, finishMerge2;

	startInsert = clock();
	insertionSort(diziInsert, n2);
	finishInsert = clock();
	
	startMerge1 = clock();
	MergeSort(diziMerge1,0,n1-1);
	finishMerge1 = clock();

	startMerge2 = clock();
	MergeSort(diziMerge2,0,n2-1);
	finishMerge2 = clock();

	cout << "Time consumed in ARRAY[100] with Merge Sort: " <<
	float((finishMerge1-startMerge1)/CLOCKS_PER_SEC);
	cout << "\n\n";
	cout << "\nTime consumed in ARRAY[100000] with Merge Sort: " <<
	float(1.0*(finishMerge2-startMerge2)/CLOCKS_PER_SEC);
	cout << "\n\n";	
	cout << "\nTime consumed in ARRAY[100000] with Insertion Sort: " <<
	float((1.0*(finishInsert-startInsert))/CLOCKS_PER_SEC);
	


	return 0;
}