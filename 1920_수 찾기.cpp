#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000], n;
int f(int x) {
	int left, right, mid, find;
	left = 0;
	right = n - 1;
	mid = (left + right) / 2;
	find = 0;
	while (left <= right) {
		if (a[mid] > x)
			right = mid - 1;
		else if (a[mid] < x)
			left = mid + 1;
		else {
			find = 1;
			break;
		}
		mid = (left + right) / 2;
	}
	return find;
}
int main(void) {
	int i, j, m, t, mid;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d ", &a[i]);
	sort(a, a + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &t);
		printf("%d\n", f(t));
	}
	return 0;
}