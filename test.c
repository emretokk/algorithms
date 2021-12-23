#include <stdio.h>
#include <stdbool.h>

bool square(int n) {

    for (int i = 1; i <= n; i++) {
        int temp = i * i;
        if (temp == n)
            return true;
        else if (temp > n)
            return false;
    }
}

void main() {
	int number;
	int temp;
	printf("Please enter a number: \n");
    scanf("%d", &number);

    for (int i = 1; i < number; i++) {
    	int tmp = i;
    	int digitSum = 0;
    	while(tmp > 0){
    		digitSum += tmp % 10;
    		tmp/=10;
    	}
    	if (square(digitSum))
    	{

    		printf("%d ", i);

    		int tmpp = i;
    		int digit = 0;
    		while(tmpp > 0){
    			digit = tmpp%10;
    			if (tmpp/10 == 0)
    			{
    				printf("%d",digit);
    			}
    			else{
    				printf("%d:",digit);
    			}
    			tmpp /= 10;
    		}
    		printf(" %d",digitSum);
    		printf("\n");
    	}
    }
}