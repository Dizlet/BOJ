#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5001], n, res_1, res_2, res_3, idx;
long long target, best_score = 3e9 + 1;
bool flag;
int main(void) {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n - 2; i++) {
		for (j = i + 2; j < n; j++) {
			target = 0 - (a[i] + a[j]);
			idx = lower_bound(a + i + 1, a + j - 1, target) - a;
			if (idx > i + 1 && abs(a[idx - 1] - target) < abs(a[idx] - target))idx--;
			long long final_score = a[idx] - target;
			if (abs(final_score) < best_score) {
				best_score = abs(final_score);
				res_1 = a[i];
				res_2 = a[idx];
				res_3 = a[j];
			}
			if (!abs(target)) {
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	printf("%d %d %d", res_1, res_2, res_3);
	return 0;
}