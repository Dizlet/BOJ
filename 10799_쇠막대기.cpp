#include<stdio.h>
int main(void) {
	char s[100001] = { 0 };
	scanf("%s", s);
	int i, sum = 0, p = 0;
	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] == '(' && s[i + 1] == ')') {
			sum += p;
			i = i + 1;
			continue;
		}
		else if (s[i] == '(') {
			sum++;
			p++;
		}
		else if (s[i] == ')' && p >= 1) {
			p--;
		}
	}
	printf("%d", sum);
	return 0;
}