#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];


int main(){
	int n, m, a, b, k;
	vector<int> ans;
	cin >> n >> m;
	vector<int> indegree(n + 1);
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		G[a].push_back(b);
		indegree[b]++;
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		vector<int> tmp, query(n);
		tmp = indegree;
		for(int j = 0; j < n; j++)
			cin >> query[j];
		for(int j = 0; j < n; j++){
			if(tmp[query[j]] != 0){
				ans.push_back(i);
				break;
			}
			for(int l = 0; l < G[query[j]].size(); l++){
				int u = G[query[j]][l];
				tmp[u]--;
			}
		}
	}
	printf("%d", ans[0]);
	for(int i = 1; i < ans.size(); i++)
		printf(" %d", ans[i]);
	return 0;
}
