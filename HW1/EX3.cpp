#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void relativelyPrime (int n1, int n2){
	while(n1!=n2){
			if (n1>n2)
			n1 -= n2;
			else
			n2 -= n1;
	}
	 if(n1==1){
		 printf("Yes");
	 } else {
		 printf("No");
	 }

}



int main() {
	printf("This numbers are relatively prime?\n");
	relativelyPrime(14, 9);
	return 0;
}
