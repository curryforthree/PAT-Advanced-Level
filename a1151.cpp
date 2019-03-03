#include <bits/stdc++.h>
using namespace std;
vector<int> in, pre;
map<int, bool> mp;

int main(){
	int m, n; 
	cin >> m >> n;
	in.resize(n);
	pre.resize(n);
	vector<int> a(n + 1);
	for(int i = 0; i < n; i++){
		cin >> in[i];
		mp[in[i]] = true;
		a[in[i]] = i + 1;
	}
	for(int i = 0; i < n; i++)
		cin >> pre[i];
		
	for(int j = 0; j < m; j++){
		int u, v;
		cin >> u >> v;
		int nowRoot;
		if(mp[u] == false || mp[v] == false){
			if(mp[u] == false && mp[v] == false){
				printf("ERROR: %d and %d are not found.\n", u, v);
				continue;
			}
			if(mp[u] == false){
				printf("ERROR: %d is not found.\n", u);
				continue;
			}
			if(mp[v] == false){
				printf("ERROR: %d is not found.\n", v);
				continue;
			}
		}
		for(int i = 0; i < n; i++){
			nowRoot = pre[i];
			if(a[nowRoot] >= a[u] && a[pre[i]] <= a[v]){
				break;
			}
			if(a[nowRoot] >= a[v] && a[pre[i]] <= a[u]){
				break;
			}
		}
		if(nowRoot == u || nowRoot == v){
			if(nowRoot == u){
				printf("%d is an ancestor of %d.\n", u, v);
			}else{
				printf("%d is an ancestor of %d.\n", v, u);
			}
			continue;
		}
		printf("LCA of %d and %d is %d.\n", u, v, nowRoot);
	}
	
	return 0;
}
