#include<stdio.h> 
int a[100001];
int main(void) {
	int i, j, n, k, sum = 0, max = 0;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < k; i++)
		sum += a[i];
	max = sum;
	for (i = 0, j = k; i < n && j < n; i++, j++) {
		sum -= a[i];
		sum += a[j];
		if (max < sum)
			max = sum;
	}
	printf("%d", max);
	return 0;
}