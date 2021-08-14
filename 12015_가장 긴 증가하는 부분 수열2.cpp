#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> v;
vector <int> path;
int a[1000001], check[1000001];
int main(void) {
	int n, i, j, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		auto idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		check[i] = idx;
		if (idx + v.begin() == v.end()) {//최대 갱신
			v.push_back(a[i]);
			cnt++;
		}
		else v[idx] = a[i];
	}
	printf("%d\n", cnt);
	return 0;
}