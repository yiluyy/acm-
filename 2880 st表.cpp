#include<bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
int high[N][25], low[N][25];

int main(){
	int n, q;
	cin>>n>>q;
	int ma = log2(n);
	for (int i = 1; i <= n; i++){
		cin>>high[i][0];
		low[i][0] = high[i][0];
	}
	for (int j = 1; j <= ma; j++){
		for (int i = 1; i + (1<<(j-1)) <= n; i++){
			high[i][j] = max(high[i][j-1], high[i+(1<<j-1)][j-1]);
			low[i][j] = min(low[i][j-1], low[i+(1<<j-1)][j-1]);
		}
	}
	for (int i = 1; i <= q; i++){
		int a, b;
		cin>>a>>b;
		int k = log2(b-a+1);
		int hh = max(high[a][k], high[b-(1<<k)+1][k]);
		int ll = min(low[a][k], low[b-(1<<k)+1][k]);
		cout<<hh-ll<<endl;
	}
	return 0;
}
