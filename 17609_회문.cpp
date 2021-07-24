#include<stdio.h>
#include<string.h>
char s[100001];
bool f(void) {
	int i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}
bool g(void) {
	int i, j, x, y, start, end, res_1, res_2, key;
	key = false;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		if (s[i] == s[j])continue;//회문을 만족
		if (s[i + 1] != s[j] && s[i] != s[j - 1])return false;//문자를 1개 지워도 회문 불만족

		if (s[i + 1] == s[j]) {//s[i]를 제거후 회문인 경우, res_1 = true
			res_1 = true;
			start = i + 1,end=j;
			for (; start < end; start++, end--) {
				if (s[start] != s[end]) {
					res_1 = false;
					break;
				}
			}
			if (res_1 == true)return true;
		}
		if (s[i] == s[j - 1]) {//s[j]를 제거후 회문인 경우, res_2 = true
			res_2 = true;
			start = i, end = j - 1;
			for (; start < end; start++, end--) {
				if (s[start] != s[end]) {
					res_2 = false;
					break;
				}
			}
			if (res_2 == true)return true;
		}
		return false;
	}
}
int main(void) {
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%s", s);
		if (f() == true)//회문
			printf("0\n");
		else if (g() == true)//유사회문
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}