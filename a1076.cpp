#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
bool inq[maxn];
int n, l;
struct node{
	int id;
	int layer;
};
vector<int> G[maxn];
 
int bfs(int u){
	int cnt = 0;
	queue<node> q;
	q.push(node{u, 0});
	inq[u] = true;
	while(!q.empty()){
		node front = q.front();
		q.pop();
		if(front.layer <= l){
			cnt++;
		}else{
			break;
		}
		for(int i = 0; i < G[front.id].size(); i++){
			int v = G[front.id][i];
			if(inq[v] == false){
				inq[v] = true;
				q.push(node{v, front.layer + 1});
			}
		}
	}
	return cnt;
}

int main(){
	cin >> n >> l;
	int m, tmpId, k;
	for(int i = 1; i <= n; i++){
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			scanf("%d", &tmpId);
			G[tmpId].push_back(i);
		}
	}
	cin >> k;
	vector<int> query(k);
	for(int i = 0; i < k; i++)
		cin >> query[i];
	for(int i = 0; i < k; i++){
		fill(inq, inq + maxn, false);
		int res = bfs(query[i]);
		printf("%d\n", res - 1);
	}
	return 0;
}
