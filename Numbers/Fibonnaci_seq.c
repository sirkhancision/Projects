/*
Program to print the Fibonacci sequence up to an arbitrary Nth number,
using the GMP library
Current issue: because the variable of the max position of the Fibonacci
sequence is of unsigned long type, the max position you can ask is 2^32 =
4,294,967,296
*/

#include <stdio.h>
#include <gmp.h>

int main() {
	unsigned long n; /* to generate the sequence up to the nth number */
	unsigned long i; /* increment variable */
	mpz_t n_minus1, n_minus2; /* to store n-1 and n-2 values from the sequence */
	mpz_t fib_number; /* the fibonacci numbers to be printed */

	/* Initializing GMP variables */
	mpz_init_set_d(n_minus1, 0);
	mpz_init_set_d(n_minus2, 1);
	mpz_init(fib_number);

	puts("Type the number of positions of the sequence to be printed:");
	scanf("%lu", &n);

	for (i = 0; n >= i; ++i) {
		printf("%lu: ", i);
		if (i == 0)
			puts("0");
		else if (i == 1)
			puts("1");
		else {
			mpz_add(fib_number, n_minus1, n_minus2);
			gmp_printf("%Zd\n", fib_number);
		}
		
		if (i > 1)
			if (i % 2 == 0)
				mpz_add(n_minus1, n_minus1, n_minus2);
			else
				mpz_add(n_minus2, n_minus1, n_minus2);
		else
			continue;
	}

	/* Freeing memory */
	mpz_clears(n_minus1, n_minus2, fib_number);
	return 0;
}