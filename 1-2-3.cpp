#include <bits/stdc++.h>
using namespace std;

int f1(int a){
	return 100*(pow(a, 2));
}

int f2(int a){
	return pow(2, a);
}

int main(){
	for (int i=1;true;++i)
		{
			if (f1(i) < f2(i))
			{
				cout << i << endl;
			break;
			}
		}	
	return 0;
}