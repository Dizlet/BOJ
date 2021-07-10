#include<stdio.h>
int main(void) {
	int i, check[10001] = { 0 }, n, sum;
	for (i = 1; i <= 10000; i++) {
		n = i;
		sum = n;
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		if (sum <= 10000)
			check[sum]++;
	}

	for (i = 1; i <= 10000; i++) {
		if (check[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}
