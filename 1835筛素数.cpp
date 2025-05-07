#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
long long l, r, res, vis[N], prim[N], cnt, vislr[N];

void get_prim(int n){
	for (int i = 2; i <= n; i++){
		if (!vis[i]){
			prim[++cnt] = i;
			//if (i >= l && i <= r) res++;
		} 
		for (int j = 1; 1ll * i * prim[j] <= n; j++){
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0) break;
		}
	}
}
int main(){
	cin>>l>>r;
	if (l == 1) l += 1;
	int ma = sqrt(r);
	get_prim(ma);
	for (long long i = 1; i <= cnt; i++){
		long long start = max(2 * prim[i], (l + prim[i] - 1) / prim[i] * prim[i]);
		for (long long j = start; j <= r; j += prim[i]){
			//if (j < l) continue;
			vislr[j - l] = 1;
		}
	}
	for (int i = 0; i <= r - l; i++) if(!vislr[i]) res++;
	cout<<res;
	return 0;
}
