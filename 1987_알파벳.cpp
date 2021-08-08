#include<stdio.h>
#include<algorithm>
using namespace std;
int a[21][21], check[30], r, c, maxcnt = 1;
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
void dfs(int y, int x, int cnt) {
	int i, nextY, nextX;
	maxcnt = max(maxcnt, cnt);
	for (i = 0; i < 4; i++) {
		nextY = y + dy[i];
		nextX = x + dx[i];
		if (nextY >= 0 && nextX >= 0 && nextY < r && nextX < c && check[a[nextY][nextX]] == 0) {
			check[a[nextY][nextX]] = 1;
			dfs(nextY, nextX, cnt + 1);
			check[a[nextY][nextX]] = 0;
		}
	}
}
int main(void) {
	int i, j;
	char s[21] = { 0 };
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", s);
		for (j = 0; s[j]; j++) {
			a[i][j] = s[j] - 'A' + 1;
			s[j] = 0;
		}
	}
	check[a[0][0]] = 1;
	dfs(0, 0, 1);
	printf("%d", maxcnt);
	return 0;
}