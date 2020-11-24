/* SYSC 2006 Lab 3. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], double n)
{
	double sum = 0;
	double avg = 0;
	int i=0;
	while(i < n){
		double absoluteVal = fabs(x[i]);
		sum = absoluteVal + sum;
		i++;
}
	avg = sum/n;
	return avg;
}





/* Exercise 2. */

/* Return the average power of the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], double n)
{
	double avg = 0;
	double sum = 0;
	int i=0;
	
	while(i < n){
	double squaredVal = fabs(x[i]) * fabs(x[i]);
	sum = squaredVal + sum;
	++i;
}
	avg = sum/n;
    return avg;
}





/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
	double max = arr[0];
	int i = 1;
	while(i < n){
		if (arr[i] > max){
			max = arr[i];
}
		++i;
}
    return max;
}





/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
    double min = 0;
	double temp = arr[0];
	int i = 0;

	while (i < n){
		if (arr[i] < temp){
			temp = arr[i];
}
		min = temp;
		++i;
}
	
	return min;
}





/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */


void normalize(double x[], int n)
{
	double maxVal = max(x,n);
	double minVal = min(x,n);
	double range = (maxVal - minVal);

	for (int i = 0; i < n; i++){
		x[i] = (x[i] - minVal) / range;
	}

}
