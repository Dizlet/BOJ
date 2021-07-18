#include<stdio.h>
#define INF 654321
int main(void) {
	int n, i, j, t, min, dp[100001] = { 0 };
	scanf("%d", &n);
	dp[1] = 1;
	for (i = 2; i <= n; i++) {
		min = INF;
		for (j = 1; i - (j * j) >= 0; j++) {
			if (min > dp[i - j * j]) {
				min = dp[i - j * j];
			}
		}
		dp[i] = min + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}