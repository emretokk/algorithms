#include <iostream>
using namespace std;



int main(){
	int A[6]={5,2,4,6,1,3};
	for (int j=1;j<6;++j)
	{
		int key = A[j];
		int i = j-1;
		while (i>=0 && A[i] > key){
			A[i+1] = A[i];   
			i--;
		}
		A[i+1] = key;
	}
	for (int i=0;i<6;++i)
	{
		cout << A[i] << endl;
	}
	return 0;
}