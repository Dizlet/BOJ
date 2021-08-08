#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1000001], path[1000001];
int main(void) {
	int i, n;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		dp[i] = 12345678;
	for (i = 2; i <= n; i++) {
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}
		if (dp[i] > dp[i - 1] + 1) {
			dp[i] = dp[i - 1] + 1;
			path[i] = i - 1;
		}
	}
	printf("%d", dp[n]);
	int temp = path[n];
	printf("\n%d", n);
	while (temp != 0) {
		printf(" %d", temp);
		temp = path[temp];
	}

	return 0;
}