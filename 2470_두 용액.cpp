#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 2121212121
int a[100001], first, second, n;
int f(int x, int x_idx) {
	int i, left, mid, right, min, min_value;
	left = 0;
	right = n - 1;
	min = INF;
	if (x_idx != 0)min_value = a[0];
	else min_value = a[1];
	while (left <= right) {
		mid = (left + right) / 2;
		if (mid == x_idx) {
			if (abs(a[mid - 1] + x) <= abs(a[mid + 1] + x)) {
				right = mid - 1;
				continue;
			}
			else {
				left = mid + 1;
				continue;
			}
		}
		int cur = a[mid];//ÇöÀç °ª
		int score = abs(cur + x);
		if (min > score) {
			min = score;
			min_value = cur;
		}
		if (cur + x > 0) right = mid - 1;
		else if (cur + x < 0) left = mid + 1;
		else if (cur + x == 0 && mid != x_idx) return cur;
	}
	return min_value;
}
int main(void) {
	int i, min, f_v, s_v;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);
	min = INF;
	f_v = s_v = 0;

	for (i = 0; i < n; i++) {
		first = a[i];
		second = f(first, i);
		int score = abs(first + second);
		//printf("%d : %d %d -> %d\n", i, first, second,score);
		if (min > score) {
			min = score;
			f_v = first;
			s_v = second;
		}
	}

	if (f_v < s_v)printf("%d %d", f_v, s_v);
	else printf("%d %d", s_v, f_v);
	return 0;
}