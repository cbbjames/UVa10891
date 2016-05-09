#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
int s[maxn], d[maxn][maxn], a[maxn], t[maxn][maxn], n;
int dp(int i,int j) {
	if (t[i][j]) return d[i][j];
	t[i][j] = 1;
	int m = 0;
	for (int k = i + 1; k <= j; k++) m = min(m, dp(k,j));
	for (int k = i; k < j; k++) m = min(m, dp(i, k));
	d[i][j] = s[j] - s[i - 1] - m;
	return d[i][j];
}
int main() {
	while (cin >> n&&n) {
		s[0] = 0;
		for (int i = 1; i <= n; i++) { cin >> a[i]; s[i] = s[i - 1] + a[i]; }
		memset(t, 0, sizeof(t));
		cout << 2*dp(1, n)-s[n] << endl;
	}
	//system("PAUSE");
	return 0;
}