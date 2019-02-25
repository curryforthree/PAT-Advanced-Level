#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
vector<int> tmpAns;
set<int> ans;
int maxLayer = 0;
bool visit[maxn];

void dfs(int u, int layer){
	if(layer > maxLayer){
		tmpAns.clear();
		tmpAns.push_back(u);
		maxLayer = layer;
	}else if(layer == maxLayer){
		tmpAns.push_back(u);
	}
	visit[u] = true;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(visit[v] == false){
			dfs(v, layer + 1);
		}
	}
}

int main(){
	int n, tmpu, tmpv, s1;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		scanf("%d%d", &tmpu, &tmpv);
		G[tmpu].push_back(tmpv);
		G[tmpv].push_back(tmpu);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){     
		if(visit[i] == false){
			dfs(i, 1);
			if(i == 1){
				s1 = tmpAns[0];
				for(int i = 0; i < tmpAns.size(); i++)
					ans.insert(tmpAns[i]);
			}
			cnt++;
		}
	}	
	if(cnt >= 2){
		printf("Error: %d components\n", cnt);
	}else{
		maxLayer = 0;
		tmpAns.clear();
		fill(visit, visit + maxn, false);
		dfs(s1, 1);
		for(int i = 0; i < tmpAns.size(); i++)
			ans.insert(tmpAns[i]);
		for(auto it = ans.begin(); it != ans.end(); it++){
			printf("%d\n", *it);	
		}
		
	}
	return 0;
}
