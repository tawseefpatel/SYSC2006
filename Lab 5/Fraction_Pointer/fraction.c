/* fraction.c - SYSC 2006 Lab 4 */

#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

#include "fraction.h"






/* EXERCISE 1 */
void print_fraction(fraction_t f)
{
	printf("%d/%d", f.num, f.den);
}





/* EXERCISE 2 */
int gcd(int a, int b)
{
	int q = abs(a);
	int p = abs(b);
	double r = q%p;

	while(r != 0){
		q = p; p = r; r = q%p;
	}

	return p;
}





/* EXERCISE 3 */
fraction_t reduce(fraction_t f)
{ 
	f = (fraction_t) {f.num, f.den};
	int divider = gcd(f.num, f.den);

	f.den = f.den/divider;
	f.num = f.num/divider;

	if (f.den < 0) {
		f.num = -1*f.num;
		f.den = abs(f.den); }

    return f;
}





/* EXERCISE 4 */
fraction_t make_fraction(int a, int b)
{
	fraction_t f = {a,b};

	if (b == 0){exit(1);}

    return reduce(f);
}





/* EXERCISE 5 */
fraction_t add_fractions(fraction_t f1, fraction_t f2)
{
	return make_fraction((f2.num*f1.den)+(f2.den*f1.num),f2.den*f1.den);
}





/* EXERCISE 6 */
fraction_t multiply_fractions(fraction_t f1, fraction_t f2)
{
	return make_fraction(f1.num*f2.num, f1.den*f2.den);
}
