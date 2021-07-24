#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, input[10], number[10], check[10];
void output(void) {
	for (int i = 0; i < m; i++)
		printf("%d ", number[i]);
	printf("\n");
	return;
}
void f(int depth) {
	if (depth == m) {
		output();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			number[depth] = input[i];
			check[i] = 1;
			f(depth + 1);
			check[i] = 0;
		}
	}
	return;
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);
	sort(input, input + n);
	f(0);
	return 0;
}