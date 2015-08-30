#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include "rand_dist.h"

#define true 1
#define false 0
#define RESETCOLOR "\033[0m"

int numPlaces (int n) {
    if (n < 0) return numPlaces ((n == INT_MIN) ? INT_MAX : -n);
    if (n < 10) return 1;
    return 1 + numPlaces (n / 10);
}

/*
int test_framework() {
	int passed = true;

	// Seed
//	srand(time(NULL));
	srand(1);

	// First test
	int min = 10;
	int max = 100;
	int random_value = rand_interval(min, max);
	if (random_value < max && random_value > min) {
		printf("%d < %d < %d - \x1B[32mtest passed." RESETCOLOR "\n", min, random_value, max); // Print in green
	} else {
		passed = false;
		printf("\x1B[31mtest failed. \n"); // Print in red
		printf("Generated password: %d \n", random_value);
	}

	// Return to normal color.
	printf("\x1B[0m");

	// free memory
	// free(random_value);

	return !passed;
}
*/

int test_bounded_distribution() {
	int passed = true;

	// Seed
//	srand(time(NULL));
	srand(1);

	// First test
	int min = 10;
	int max = 100;
	int random_value = rand_interval(min, max);
	if (random_value < max && random_value > min) {
		printf("%d < %d < %d - \x1B[32mtest passed." RESETCOLOR "\n", min, random_value, max); // Print in green
	} else {
		passed = false;
		printf("\x1B[31mtest failed. \n"); // Print in red
		printf("Generated password: %d \n", random_value);
	}

	// Return to normal color.
	printf("\x1B[0m");

	// free memory
	// free(random_value);

	return !passed;
}

int main() {
	test_bounded_distribution();

	return 0;
}