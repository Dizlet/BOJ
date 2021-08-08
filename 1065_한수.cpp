#include<stdio.h>
#include<math.h>
int main(void) {
	int i, n, a[1001] = { 0 }, b[3], temp, j, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= 99; i++) {
		a[i] = 1;
	}
	for (i = 100; i <= 999; i++) {
		temp = i, j = 2;
		while (temp) {
			b[j] = temp % 10;
			temp /= 10;
			j--;
		}
		if (b[1] - b[0] == b[2] - b[1])
			a[i] = 1;
	}
	for (i = 1; i <= n; i++) {
		if (a[i] == 1)
			sum++;
	}
	printf("%d", sum);
	return 0;
}
