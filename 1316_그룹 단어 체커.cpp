#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[101] = { 0 };
	int i, j, sum = 0, n, check[26], len, key;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		len = strlen(s);
		key = 1;
		for (j = 0; j < 26; j++)
			check[j] = 0;

		for (j = 1; j <= len; j++) {
			if (check[s[j] - 'a'] == -1) {
				key = 0;
				break;
			}
			if (s[j] != s[j - 1]) {
				check[s[j - 1] - 'a'] = -1;
			}
			if (check[s[j] - 'a'] == 0) {
				check[s[j] - 'a'] = 1;
			}
		}
		if (key == 1)
			sum++;
	}
	printf("%d", sum);
	return 0;
}
