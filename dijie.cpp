#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll INF = 1e18;
const int N = 1e5+10;
int n, m, V, T;
ll dis[N];
struct edge{
	int v, w;
};

vector<edge> e[N];
priority_queue<pair<ll, int>> q;
int vis[N];

void dij(){
	for (int i = 1; i <= n; i++){
		dis[i] = INF;
	}
	dis[T] = 0;
	q.push({0, T});
	while (q.size()){
		auto t = q.top();
		q.pop();
		int u = t.second;
		ll val = -t.first;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto i : e[u]){
			int v = i.v, w = i.w;
			ll bg = val/V, used = val%V+w;
			if (used > V){
				bg++;
				used = w;
			}
			ll ndis = bg*V+used;
			if (dis[v] > ndis){
				dis[v] = ndis;
				q.push({-dis[v], v});
			}
		}
	}
}

signed main(){
	cin>>n>>m>>V>>T;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	dij();
	for (int i = 1; i <= n; i++){
		if (dis[i] != INF){
			ll bg = dis[i]/V, used = dis[i]%V;
			if (used) bg++;
			bg = max(bg, 1LL);
			cout<<bg<<' ';
		} 
		else cout<<-1<<' ';
	}
		
	return 0;
}
