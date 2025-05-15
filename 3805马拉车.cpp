#include<bits/stdc++.h>

using namespace std;

const int N = 3e7+10;
char a[N], s[N];
int d[N], ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a+1;
	int n = strlen(a+1), k = 0;
	s[0] = '$', s[++k] = '#';
	for (int i = 1; i <= n; i++){
		s[++k] = a[i], s[++k] = '#';
	}
	n = k; 
	d[1] = 1;
	for (int i = 2, l, r = 0; i <= n; i++){
		if (i <= r) d[i] = min(d[r+l-i], r-i+1);
		while (s[i-d[i]] == s[i+d[i]]) d[i]++;
		ans = max(d[i]-1, ans);
		if (i+d[i]-1 > r) l = i-d[i]+1, r = i+d[i]-1;
	}
	cout<<ans;
	return 0;
}
