#include<stdio.h>
#include<algorithm>
using namespace std;
pair <int, int> p[100000];
int main(void) {
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p + n);
	int s = 0, e = 0, cnt = 0;
	for (i = 0; i < n; i++) {
		if (p[i].second >= e) {
			e = p[i].first;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}