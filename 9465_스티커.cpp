#include<stdio.h>
#include<algorithm>
using namespace std;
int t, n, dp[3][100001], a[2][100001];
int main(void) {
	int i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
			scanf("%d", &a[0][j]);
		for (j = 1; j <= n; j++)
			scanf("%d", &a[1][j]);
		if (i >= 1)
			for (j = 0; j < n; j++)
				dp[0][j] = dp[1][j] = dp[2][j] = 0;
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];
		for (j = 1; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[2][j - 1]) + a[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[2][j - 1]) + a[1][j];
			dp[2][j] = max({ dp[0][j - 1],dp[1][j - 1],dp[2][j - 1] });
		}
		printf("%d\n", max({ dp[0][n],dp[1][n],dp[2][n] }));
	}
	return 0;
}