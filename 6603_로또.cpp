#include<stdio.h>
int k,s[15], num[15], check[50];
void output(void) {
	for (int i = 0; i < 6; i++)
		printf("%d ", num[i]);
	printf("\n");
	return;
}
void f(int level, int start) {
	int i;
	if (level == 6) {
		output();
		return;
	}
	for (i = start; i < k; i++) {
		if (check[s[i]] == 0) {
			check[s[i]] = 1;
			num[level] = s[i];
			f(level + 1, i+1);
			check[s[i]] = 0;
			num[level] = 0;
		}
	}
	return;
}
int main(void) {
	int i;
	while (1) {
		scanf("%d", &k);
		if (k == 0)break;
		for (i = 0; i < k; i++) {
			scanf("%d", &s[i]);
			num[i] = check[i] = 0;
		}
		f(0, 0);
		printf("\n");
	}
	return 0;
}