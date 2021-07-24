#include<stdio.h>
#include<queue>
using namespace std;
int a[1001][1001], visit_bfs[1001], n, m, v, visit_dfs[1001];
queue <int>q;
void dfs(int num) {
	int i;
	for (i = 1; i <= n; i++) {
		if (a[num][i] == 1 && visit_dfs[i] == 0) {
			printf("%d ", i);
			visit_dfs[i] = 1;
			dfs(i);
		}
	}
	return;
}
void bfs(void) {
	int i, t;
	q.push(v);
	visit_bfs[v] = 1;
	printf("%d ", v);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (i = 1; i <= n; i++) {
			if (a[t][i] == 1 && visit_bfs[i] == 0) {
				printf("%d ", i);
				q.push(i);
				visit_bfs[i] = 1;
			}
		}
	}
	return;
}
int main(void) {
	int i, j, x, y;
	scanf("%d %d %d", &n, &m, &v);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}

	printf("%d ", v);
	visit_dfs[v] = 1;
	dfs(v);

	printf("\n");
	bfs();
	return 0;
}