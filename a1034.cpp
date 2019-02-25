#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
map<int, string> iTos;
map<string, int> sToi, ans;
int G[maxn][maxn];  
int weight[maxn];
bool visit[maxn];
int cntIdx = 1;
int n, k;
int getId(string name){
	if(sToi[name] == 0){
		sToi[name] = cntIdx;
		iTos[cntIdx] = name;
		cntIdx++;
		return cntIdx - 1;
	}else{
		return sToi[name];
	}
}
void dfs(int id, int& head, int& tot, int& sum){
	visit[id] = true;
	tot++;
	if(weight[id] > weight[head]){
		head = id;
	}
	for(int i = 1; i < cntIdx; i++){
		if(G[id][i] != 0){
			sum += G[id][i];
			G[id][i] = G[i][id] = 0;
			if(visit[i] == false){
				dfs(i, head, tot, sum);
			}
		}
	}
}

void dfsTravel(){
	for(int i = 1; i < cntIdx; i++){
		if(visit[i] == false){
			int head = i, tot = 0, sum = 0;
			dfs(i, head, tot, sum);
			if(tot > 2 && sum > k){
				ans[iTos[head]] = tot;
 			}
		}
	}
}

int main(){
	int  tmpW;
	string name1, name2;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> name1 >> name2 >> tmpW;
		int id1, id2;
		id1 = getId(name1);
		id2 = getId(name2);
		G[id1][id2] += tmpW;
		G[id2][id1] += tmpW;
		weight[id1] += tmpW	;
		weight[id2] += tmpW;
	}
	dfsTravel();
	cout << ans.size() << endl;
	for(auto it = ans.begin(); it != ans.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
