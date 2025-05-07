 #include<bits/stdc++.h>
 
using namespace std;

const int N = 1010;
int n, m, tmp, res, fa[N], flag[N];

int find(int x){
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void un(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) return;
	fa[x] = y;
}
int main(){
	while (scanf("%d", &tmp), tmp != 0){
		cin>>m;
		n = tmp;
		for (int i = 1; i <= n; i++) fa[i] = i;
		while(m--){
			int x, y;
			cin>>x>>y;
			un(x, y);
		}
		res = -1;
		for (int i = 1; i <= n; i++){
			if (!flag[find(fa[i])]){
				flag[find(fa[i])] = 1;
				res++;
			}
			//cout<<fa[i]<<endl;
		}
		cout<<res<<endl;
		memset(flag, 0, sizeof flag);
	}
	return 0;
}
