#include<bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;
vector<int> tree[N];
int dep[N], n, m;
long long res[N];
int dp[N][18], cun[N][N];

void dfs(int son, int father){
	dep[son] = dep[father] + 1;
	int i;
	dp[son][0] = father;
	for (i = 1; (1<<i) <= n; i++){
		dp[son][i] = dp[dp[son][i - 1]][i - 1];
	}
	for (auto v : tree[son]){
		if (v != father)
			dfs(v, son);
	}
	return;
}
int lca(int x, int y){
	if (dep[x] < dep[y])
		swap(x, y);
	int i;
	for (i = log2(n); i >= 0; i--){
		if (dep[dp[x][i]] >= dep[y])
			x = dp[x][i];
	}
	if (x == y)
		return x;
	for (i = log2(n); i >= 1; i--){
		if (dp[x][i] != dp[y][i]){
			x = dp[x][i];
			y = dp[y][i];
		}
	}
	return dp[x][0];
}
int main(){
	cin>>n>>m;
	int i, t;
	for (i = 1; i <= n - 1; i++){
		scanf("%d", &t);
		tree[i].push_back(t);
		tree[t].push_back(i);
	}
	dfs(0, -1);
	for (i = 1; i <= n - 1; i++){
		for (t = i; t <= n - 1; t++){
			cun[i][t] = lca(i, t);
		}
	}
	int l, r, z;
	for (i = 1; i <= m; i++){
		scanf("%d %d %d", &l, &r, &z);
		int j;
		for (j = l; j <= r; j++){
			if (j > z) res[i] += dep[cun[z][j]];
			else res[i] += dep[cun[j][z]];
		}
	}
	for (i = 1; i <= m; i++)
		printf("%lld\n", res[i] % 201314);
	return 0;
}
