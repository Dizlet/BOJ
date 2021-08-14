#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int a[10][10], input[10][10];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
bool check[70], visit[10][10];
int n, m, answer;
vector <pair<int, int>>zero;
vector <pair<int, int>>bfs_start;
queue<int>q;
void bfs(int sy, int sx);

void Init(void) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = input[i][j];
		}
	}
	return;
}
void makeWall(int depth, int idx) {
	int i, j, len, y, x, score;
	if (depth == 3) {
		Init();
		for (i = 0; i < bfs_start.size(); i++) {
			y = bfs_start[i].first;
			x = bfs_start[i].second;
			bfs(y, x);
		}
		score = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					score++;
				}
			}
		}
		answer = max(score, answer);
		return;
	}
	for (i = idx; i < zero.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			makeWall(depth + 1, i + 1);
			check[i] = false;
		}
	}
	return;
}
void bfs(int sy, int sx) {
	int ty, tx, y, x, i;
	q.push(sy);
	q.push(sx);
	memset(visit, false, sizeof(visit));
	visit[sy][sx] = true;
	for (i = 0; i < zero.size(); i++) {
		if (check[i] == true) {
			y = zero[i].first;
			x = zero[i].second;
			a[y][x] = 1;
		}
	}
	while (!q.empty()) {
		ty = q.front();
		q.pop();
		tx = q.front();
		q.pop();
		for (i = 0; i < 4; i++) {
			y = ty + dy[i];
			x = tx + dx[i];
			if (y < 0 || x < 0 || y >= n || x >= m)continue;
			if (visit[y][x] == false && a[y][x] == 0) {
				q.push(y);
				q.push(x);
				visit[y][x] = true;
				a[y][x] = 2;
			}
		}
	}
}
int main(void) {
	int i, j;
	scanf("%d %d", &n, &m);
	memset(visit, false, sizeof(visit));
	memset(check, false, sizeof(check));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 0) {
				zero.push_back(make_pair(i, j));
			}
			else if (input[i][j] == 2) {
				bfs_start.push_back(make_pair(i, j));
			}
		}
	}
	makeWall(0, 0);
	printf("%d", answer);
	return 0;
}