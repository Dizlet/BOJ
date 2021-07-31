#include<stdio.h>
#include<queue>
using namespace std;
queue <int> q;

int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 }, map[105][105];
char s[105][105] = { 0 };

int main(void) {
	int i, j, n, m, ty, tx, y, x, cnt = 0, key = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", &s[i]);
	q.push(0);
	q.push(0);
	s[0][0] = '0';
	cnt = 1;
	while (!q.empty()) {
		ty = q.front();
		q.pop();
		tx = q.front();
		q.pop();
		key = 0;
		if (ty == n - 1 && tx == m - 1)break;
		for (i = 0; i <= 3; i++) {
			y = ty + dy[i];
			x = tx + dx[i];
			if (y >= 0 && x >= 0 && y < n && x < m && s[y][x] == '1') {
				q.push(y);
				q.push(x);
				s[y][x] = '0';
				map[y][x] = map[ty][tx] + 1;
			}
		}
		cnt++;
	}
	printf("%d", map[n - 1][m - 1] + 1);
	return 0;
}