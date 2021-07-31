#include<stdio.h>
int main(void) {
	int i, j, cnt = 0, n, l, prefixNum[101] = { 0 }, numList[101] = { 0 };
	bool find = false;
	long long first = 0, sum = 0, num = 0;
	scanf("%d %d", &n, &l);
	for (i = 1; i <= 100; i++)
		prefixNum[i] = prefixNum[i - 1] + i;
	for (i = l; i <= 100; i++) {
		first = n - prefixNum[i - 1];
		if (first < 0)continue;
		if (first % i == 0) {
			num = first / i;
			sum = 0;
			cnt = i;
			for (j = 1; j <= i; j++) {
				numList[j] = num;
				sum += num;
				num++;
			}
			if (sum == n) {
				find = true;
				break;
			}
			else {
				cnt = 101;
				find = false;
			}
		}
	}
	if (cnt <= 100 && find) {
		for (i = 1; i <= cnt; i++)
			printf("%d ", numList[i]);
	}
	else
		printf("-1");
	return 0;
}