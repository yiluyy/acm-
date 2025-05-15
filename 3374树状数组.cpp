#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+10;
int n, m, nums[N], tree[N];

void update(int index, int plus){
	for (int i = index; i <= n; i += i & -i){
		tree[i] += plus;
	}
}

int prefix(int i){
	int s = 0;
	while (i){
		s += tree[i];
		i -= i & -i;
	}
	return s;
}

int main(){
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
		cin>>nums[i];
		update(i, nums[i]);
	}
	while (m--){
		int type;
		cin>>type;
		if (type == 1){
			int x, k;
			cin>>x>>k;
			update(x, k);
		}
		else{
			int x, y;
			cin>>x>>y;
			cout<<prefix(y)-prefix(x-1)<<endl;
		}
	}
	
	return 0;
}
