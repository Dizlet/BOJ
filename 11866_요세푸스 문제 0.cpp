#include<stdio.h>
#include<queue>
using namespace std;
queue <int> q;
int main(void) {
	int n, k, i, t, a[1001] = { 0 };
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		q.push(i);
	i = 1;
	while (!q.empty()) {
		for (i = 1; i <= k - 1; i++) {
			t = q.front();
			q.pop();
			q.push(t);
		}
		a[n - q.size()] = q.front();
		q.pop();
	}
	printf("<");
	for (i = 0; i < n - 1; i++)
		printf("%d, ", a[i]);
	printf("%d>", a[n - 1]);
	return 0;
}