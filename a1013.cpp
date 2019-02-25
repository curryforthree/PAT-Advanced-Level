#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
bool vis[maxn];
vector<int> G[maxn];

void dfs(int u){
	vis[u] = true;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(vis[v] == false){
			dfs(v);
		}
	}
}
void bfs(int u){
	queue<int> q;
	vis[u] = true;
	q.push(u);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(int i = 0; i < G[front].size(); i++){
			int v = G[front][i];
			if(vis[v] == false){
				q.push(v);
				vis[v] = true;
			}
		}
	}
}


int main(){
	int n, m ,k, u, v;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> query(k); 
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	for(int i = 0; i < k; i++)
		cin >> query[i];
	for(int i = 0; i < k; i++){
		fill(vis, vis + maxn, false);
		int res = 0;
		vis[query[i]] = true;
		for(int j = 1; j <= n; j++){
			if(vis[j] == false){
				bfs(j);
				res++;
			}
		}
		printf("%d\n", res - 1);
	}
	return 0;
}
