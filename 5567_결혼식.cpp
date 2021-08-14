#include<stdio.h>
int n, m, cnt;
bool adj[501][501];
bool check[501];
void f(int depth, int cur) {
	if (depth == 2)return;
	for (int i = 1; i <= n; i++) {
		if (adj[cur][i] == true) {
			if (check[i] == false) {
				check[i] = true;
				cnt++;
			}
			f(depth + 1, i);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x][y] = adj[y][x] = true;
	}
	check[1] = true;
	f(0, 1);
	printf("%d", cnt);
	return 0;
}