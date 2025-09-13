#include<bits/stdc++.h>

using namespace std;

const int N = 16;
vector<long long> pre(N+1);

long long sumx(long long x){
	string s = to_string(x);
	int m = s.length();
	vector<vector<long long>> dp(m, vector<long long>(200, -1));
	auto dfs = [&](auto&& dfs, int i, long long sum, bool islimit) -> long long {
		if (i == m) return sum;
		if (!islimit && dp[i][sum] != -1) return dp[i][sum];
		long long res = 0;
		int up = islimit ? s[i]-'0' : 9;
		for (int j = 0; j <= up; j++){
			res += dfs(dfs, i+1, sum+j, islimit && j == up);
		}
		if (!islimit) dp[i][sum] = res;
		return res;
	};
	return dfs(dfs, 0, 0, true);
}

void solve(){
	long long k;
	cin>>k;
	int ll = 0, rr = 16;
	while (ll + 1 != rr){
		int mid = (ll+rr) >> 1;
		if (pre[mid] > k) rr = mid;
		else ll = mid;
	}
	long long left = k-pre[ll];
	long long t = (long long)pow(10, ll)-1;
	long long dig = left/(ll+1);
	left = left%(ll+1);
	long long en = t+dig+1;
	long long ans = sumx(en-1);
	string res = "";
	while (en){
		res += '0'+en%10;
		en /= 10;
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < left; i++) ans += res[i]-'0';
	cout<<ans<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	pre[0] = 0;
	for (int i = 1; i <= N; i++){
		pre[i] += pre[i-1]+i*(9*(long long)pow(10, i-1));
	}
	while (t--){
		solve();
	}
	return 0;
}
