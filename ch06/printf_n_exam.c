#include <stdio.h>

int main() {
	int len1, len2;

	printf("hello%nworld%n\n", &len1, &len2);

	printf("len1: %d, len2: %d\n", len1, len2);

	return 0;
}

