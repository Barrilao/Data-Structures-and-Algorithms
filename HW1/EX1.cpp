#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void primeNumbers(int n) {
	int cont = 0, i = 1, d;
	bool res;
	while (cont < n) {
		res = true;
		if (i % 2 == 0)
			if (i == 2)
				res=true;
			else
				res=false;
		else
			for (d = 3; d <= sqrt(i); d += 2)
				if (i % d == 0)
					res=false;
		if (res) {
			printf("%i ", i);
			cont++;
		}
		i++;
	}
}


int main() {
	printf("N prime numbers:\n");
	primeNumbers(100);

	return 0;
}
