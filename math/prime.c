#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define MAX(x,y)(((x)>(y)) ? (x) : (y))

int isprime(int n) {
	if (n==2 || n==3) return TRUE;
	if (n%2==0 || n%3==0) return FALSE;
	int i=5;
	while (i<sqrt(n)+1) {
		if (n%i==0 || n%(i+2)==0) return FALSE;
		i += 6;
	}
	return TRUE;
}

int * primes(int n) {
	int* fact = malloc(n); int* fp = fact;
	while (n>1) {
		if (isprime(n) == TRUE) {*(fp++) = n; n=1;}
		for (int i=2; i<n; i++) {
			if (n%i==0 && isprime(i) == TRUE) { *(fp++) = i; n = n/i; if (n == 1) break; }
		}
	}
	return fact;
}	

int main() {
	int lim = 1000000, max=0;
	for (int i=2; i<=lim; i++) {
		printf("%d: ", i);
		int* fact = primes(i);
		for (int j=0; j<=i; j++) { 
      if (fact[j] != 0) { max = MAX(max, fact[j]); printf("%d ", fact[j]); }
			else break;
		}
		printf("\n");
	}
  printf("Largest Prime: %d\n", max);
	return 0;
}
