#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
priority_queue<int> a;
priority_queue<int, vector<int>, greater<int>> b;

int main(){
	int n, w;
	cin>>n>>w;
	for (int i = 1, x; i <= n; i++){
		cin>>x;
		int k = i*w*0.01;
		k = max(1, k);
		if (b.empty() || x >= b.top()) b.push(x);
		else a.push(x);
		while ((int)b.size() < k) b.push(a.top()), a.pop();
		while ((int)b.size() > k) a.push(b.top()), b.pop();
		cout<<b.top()<<' ';
	}
	
	return 0;
} 
