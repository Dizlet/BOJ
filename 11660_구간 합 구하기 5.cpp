#include<stdio.h>
int sum[1025][1025], a[1025][1025];
int main(void) {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {	
			if (i == 1)sum[i][j] = sum[i][j - 1] + a[i][j];
			else if (j == 1)sum[i][j] = sum[i - 1][j] + a[i][j];
			else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1]);
	}
	return 0;
}