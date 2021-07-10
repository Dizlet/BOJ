#include<stdio.h>
int w[101],v[101],dp[100001];
int main(void) {
	int i, j, n, k;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d %d", &w[i], &v[i]);
	for (i = 0; i < n; i++)
		for (j = k; j >=w[i]; j--)
			if (dp[j] < dp[j - w[i]] + v[i])
				dp[j] = dp[j - w[i]] + v[i];
	printf("%d", dp[k]);
	return 0;
}