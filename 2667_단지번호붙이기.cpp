#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
queue <int>q;
int a[26][26], n, dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int f(int sy, int sx, int k) {
	int i, y, x, ty, tx, cnt;
	q.push(sy);
	q.push(sx);
	a[sy][sx] = k;
	cnt = 1;
	while (!q.empty()) {
		ty = q.front();
		q.pop();
		tx = q.front();
		q.pop();
		for (i = 0; i <= 3; i++) {
			y = ty + dy[i];
			x = tx + dx[i];
			if (x >= 0 && y >= 0 && x < n && y < n && a[y][x] == 1) {
				q.push(y);
				q.push(x);
				a[y][x] = k;
				cnt++;
			}
		}
	}
	return cnt;
}
int main(void) {
	int i, j, key, cnt, num[1000] = { 0 };
	char s[26][26] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", &s[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (s[i][j] == '1')
				a[i][j] = 1;
	key = 2;
	cnt = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				num[cnt] = f(i, j, key);
				key++;
				cnt++;
			}
		}
	}
	sort(num, num + cnt);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d\n", num[i]);
	return 0;
}