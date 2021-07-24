#include<stdio.h>
int input[10001];
int main(void)
{
	int x, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		input[x]++;
	}
	i = 0;
	while (i < 10001)
	{
		if (input[i] > 0)
		{
			printf("%d\n", i);
			input[i]--;
		}
		else
			i++;
	}
	return 0;
}