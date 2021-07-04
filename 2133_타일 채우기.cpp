#include<stdio.h>
int main(void) {
	int i, j, n, d[31] = { 0 };
	scanf("%d", &n);
	d[2] = 3;
	for (i = 4; i <= 30; i += 2) {
		d[i] = d[i - 2] * 3 + 2;
		for (j = i - 4; j >= 2; j -= 2) {
			d[i] += d[j] * 2;
		}
	}
	printf("%d", d[n]);
	return 0;
}