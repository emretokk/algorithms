#include <bits/stdc++.h>
using namespace std;



int main(){
	// in this situation Bit string is 10 00  
	//       LSB    MSB
	int A[4]={0,0,0,1};
	int B[4]={0,0,0,1};
	int C[5];
	int carry = 0, i;
	for (i=0;i<4;i++)
	{		
		C[i] = (A[i] + B[i] + carry) % 2;
		carry = (A[i] + B[i] + carry) / 2;
	}
	C[i] = carry;
	for (int j=0;j<5;++j)
	{
		cout << C[4-j];
	}
	return 0;
}