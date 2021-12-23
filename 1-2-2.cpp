#include <bits/stdc++.h>
using namespace std;


// insertion sort
int f1(int n){
	return 8*pow(n, 2);
}

// merge sort
int f2(int n){
	return 64*n*log(n);
}


int main(){
	for (int i=2;true;++i)
	{
		if (f1(i) <= f2(i))
		{
			cout << i << endl;
		}
		else {break;}
	}
	return 0;
}