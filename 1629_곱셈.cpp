#include<stdio.h>
int a, b, c;
long long pow(long long x, long long y) {
	long long num = 1;

	while (y > 0) {
		num %= c;
		x %= c;
		if (y % 2 == 1)
			num = (num * x) % c;
		x = (x * x) % c;
		y /= 2;
	}
	return num % c;
}
int main(void) {
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", pow(a, b) % c);
	return 0;
}