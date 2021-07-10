#include<stdio.h>
#include<string.h>
int main(void)
{
	int i, sum = 0;
	char s[105] = { 0 };
	scanf("%s", s);
	sum = strlen(s);
	for (i = 0; s[i]; i++) {
		if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
			sum -= 2;
		else if (
			s[i] == 'c' && s[i + 1] == '=' ||
			s[i] == 'c' && s[i + 1] == '-' ||
			s[i] == 'd' && s[i + 1] == '-' ||
			s[i] == 'l' && s[i + 1] == 'j' ||
			s[i] == 'n' && s[i + 1] == 'j' ||
			s[i] == 's' && s[i + 1] == '='
			) {
			sum--;
		}
		else if (s[i] == 'z' && s[i + 1] == '=' && s[i - 1] != 'd')
			sum--;
	}
	printf("%d", sum);
	return 0;
}
