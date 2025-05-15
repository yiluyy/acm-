#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int d[N][N], p[N][N];

void path(int x, int y){
	if (p[x][y] == 0) return;
	int k = p[x][y];
	path(x, k);
	cout<<k<<' ';
	path(k, y);
}
int main(){
	int n, m;
	cin>>n>>m;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		d[u][v] = min(w, d[u][v]);
		d[v][u] = min(w, d[u][v]);
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (d[i][j] > d[i][k]+d[k][j]){
					d[i][j] = d[i][k]+d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout<<d[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
