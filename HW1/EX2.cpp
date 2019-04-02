#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void factorial(int n){
	int i, res =1;
	for (i = 1; i <= n; i++)
	    res = res * i;
	printf("%i", res);
}

int main() {
	printf("Factorial of N:\n");
	factorial(10);
	return 0;
}
