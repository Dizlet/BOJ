#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue <long long> q;
int n, m;
int main(void) {
	int i, j, cnt = 0;
	long long y, x, temp, sum = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%lld", &temp);
		sum += temp;
		q.push(-temp);
	}

	while (cnt < m) {
		y = -q.top();
		q.pop();
		x = -q.top();
		q.pop();
		sum += (y + x);
		q.push(-(y + x));
		q.push(-(y + x));
		cnt++;
	}
	printf("%lld", sum);
	return 0;
}