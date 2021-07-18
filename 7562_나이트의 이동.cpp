#include<stdio.h>
#include<queue>
using namespace std;
#define INF 12345
int n, start_y, start_x, end_y, end_x, board[301][301];
int dy[8] = { -2,-1,1,2,2,1,-1,-2 }, dx[8] = { 1,2,2,1,-1,-2,-2,-1 };//1시방향부터 시계방향
queue <int>q;
int f(void) {
	int i, j, y, x, ty, tx;
	q.push(start_y);
	q.push(start_x);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			board[i][j] = INF;
	board[start_y][start_x] = 0;
	while (!q.empty()) {
		ty = q.front();
		q.pop();
		tx = q.front();
		q.pop();
		for (i = 0; i <= 7; i++) {
			y = ty + dy[i];
			x = tx + dx[i];
			if (x >= 0 && y >= 0 && x < n && y < n && board[y][x] == INF) {
				q.push(y);
				q.push(x);
				if (board[y][x] > board[ty][tx] + 1)
					board[y][x] = board[ty][tx] + 1;
			}
		}
	}
	return board[end_y][end_x];
}
int main(void) {
	int t, i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		scanf("%d %d", &start_y, &start_x);
		scanf("%d %d", &end_y, &end_x);
		printf("%d\n", f());
	}
	return 0;
}