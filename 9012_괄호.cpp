#include<stdio.h>
#include<string.h>
int main(void) {
	int i, j, t, x, y, key;
	char a[51] = { 0 };
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%s", a);
		x = y = key = 0;
		for (j = 0; a[j]; j++) {
			if (a[j] == '(')
				x++;
			if (a[j] == ')')
				y++;
			if (x < y) {
				key = 1;
				break;
			}
		}
		if (x == y && key == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}