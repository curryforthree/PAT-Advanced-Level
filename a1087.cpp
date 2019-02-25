#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int maxn = 210;
int G[maxn][maxn];
int weight[maxn];
vector<int> pre[maxn];
map<string, int> sti;
map<int, string> its;
int idx = 1;
int n, k;
string start;
int d[maxn];
bool vis[maxn];
int startId;
vector<int> tempPath, ans;
int maxHappy = 0, maxAve = 0, tot = 0;
int getId(string name){  // ±àºÅ´Ó1~n 
	if(sti[name] == 0){
		sti[name] = idx;
		its[idx] = name;
		idx++;
		return idx - 1;
	}else{
		return sti[name];
	}
}

void dij(int s){
	fill(d, d + maxn, INF);
	d[s] = 0;
	for(int i = 1; i <= n; i++){
		int u = -1, MIN = INF;
		for(int j = 1; j <= n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) break;
		vis[u] = true;
		for(int v = 1; v <= n; v++){
			if(G[u][v] != INF && vis[v] == false){
				if(d[v] > d[u] + G[u][v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[v] == d[u] + G[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs(int u){
	if(u == startId){
		tot++;
		tempPath.push_back(u);
		int op = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--){
			op += weight[tempPath[i]];
		}
		int ave = op / (tempPath.size() - 1);
		if(op > maxHappy){
			ans = tempPath;
			maxHappy = op;
			maxAve = ave;
		}else if(op == maxHappy){
		 	if(ave > maxAve){
			 	ans = tempPath;
				maxHappy = op;
				maxAve = ave;
			 }
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(u);
	for(int i = 0; i < pre[u].size(); i++){
		dfs(pre[u][i]);
	}
	tempPath.pop_back();
	return;
}


int main(){
	int tmpw;
	string tmpName, tmpu, tmpv;
	cin >> n >> k >> start;
	startId = getId(start);
	weight[startId] = 0;
	for(int i = 0; i < n - 1; i++){
		cin >> tmpName >> tmpw;
		int tmpId = getId(tmpName);
		weight[tmpId] = tmpw;
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int i = 0; i < k; i++){
		cin >> tmpu >> tmpv >> tmpw;
		G[sti[tmpu]][sti[tmpv]] = tmpw;
		G[sti[tmpv]][sti[tmpu]] = tmpw;
	}
	dij(startId);
	dfs(sti["ROM"]);
	printf("%d %d %d %d\n", tot, d[sti["ROM"]], maxHappy, maxAve);
	for(int i = ans.size() - 1; i >= 0; i--){
		if(i != 0) printf("%s->", its[ans[i]].c_str());
		else printf("%s\n", its[ans[i]].c_str());
	}
	
	return 0;
}
