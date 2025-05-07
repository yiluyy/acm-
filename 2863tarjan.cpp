#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
const int M = 5e4+10;
int dnf[N], low[N], tot;
int sta[N], inst[N], top;
int scc[N], siz[N], cnt, ans;
vector<int> e[M];

void tarjan(int x){
	dnf[x] = low[x] = ++tot;
	sta[++top] = x;
	inst[x] = 1;
	for (auto i : e[x]){
		if (!dnf[i]){
			tarjan(i);
			low[x] = min(low[i], low[x]);
		}
		else if (inst[i]){
			low[x] = min(low[x], dnf[i]);
		}
	}
	if (dnf[x] == low[x]){
		int t;
		++cnt;
		do{
			t = sta[top--];
			inst[t] = 0;
			scc[t] = cnt;
			siz[cnt]++;
		}while (t != x);
		if (siz[cnt] > 1) ans++;
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin>>a>>b;
		e[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		if (!dnf[i]) tarjan(i);
	}
	cout<<ans;
	return 0;
}
