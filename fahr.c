#include <stdio.h>

main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;  /* lower limit of temprature */
	upper = 300; // upper limit
	step = 20;

	fahr = lower;
	while(fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	} // end of while
} // end of main