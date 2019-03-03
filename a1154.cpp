#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
int main(){
	int n, m, a, b, k;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		vector<int> v(n);
		set<int> s;
		bool flag = true;
		for(int j = 0; j < n; j++){
			cin >> v[j];
			s.insert(v[j]);
		}
		for(int u = 0; u < n; u++){ // 检查每一条边的两个端点
			for(int j = 0; j < G[u].size(); j++){
				int  c = G[u][j];
				if(v[u] == v[c]){
					flag = false;
					break;
				}
			}
			if(flag == false){
				break;
			}
		}
		if(flag){
			printf("%d-coloring\n", s.size());
		}else{
			printf("No\n");	
		}
	} 
	return 0;
}
