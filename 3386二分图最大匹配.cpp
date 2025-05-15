#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int n, m, ed, head[N], cnt, vis[510], match[510], ans;
typedef struct edge{
	int to, next;
}edge;
edge e[N];

bool dfs(int u){
	for (int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if (vis[v]) continue;
		vis[v] = 1;
		if (!match[v] || dfs(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}

void add(int a, int b){
	e[++cnt] = {b, head[a]};
	head[a] = cnt;
}

int main(){
	cin>>n>>m>>ed;
	for (int i = 1; i <= ed; i++){
		int u, v;
		cin>>u>>v;
		add(u, v);
	}
	for (int i = 1; i <= n; i++){
		memset(vis, 0, sizeof vis);
		if (dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
} 
