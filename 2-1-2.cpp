#include <bits/stdc++.h>
using namespace std;



int main(){
	int A[8]={12,314,5,2,34,3,6,7};
	for (int i=1;i<8;++i)
	{
		int key=A[i];
		int tmp=i-1;
		while(tmp >= 0 && A[tmp] < key){
			A[tmp+1]=A[tmp];
			tmp--;
		}
		A[tmp+1]=key;
	}
	for (int i=0;i<8;++i)
	{
		cout << A[i] << endl;
	}
	return 0;
}