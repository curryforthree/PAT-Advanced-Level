#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int INF = 1000000000;
int G[maxn][maxn];

int main(){
	int n, m, a, b, w, k;
	cin >> n >> m;
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &w);
		G[a][b] = G[b][a] = w;
	}
	cin >> k;
	int u = 0, MIN = INF;
	for(int i = 0; i < k; i++){
		int tot;
		bool isC = true, isEx = true;
		int sum = 0;
		scanf("%d", &tot);
		vector<int> v(tot);
		for(int j = 0; j < tot; j++)
			cin >> v[j];
		for(int j = 0; j < tot - 1; j++){
			if(G[v[j]][v[j + 1]] != INF){
				sum += G[v[j]][v[j + 1]];
			}else{
				isEx = false;
				break;
			}
		}
		if(isEx == false){
			printf("Path %d: NA (Not a TS cycle)\n", i + 1);
			continue;
		}
		set<int> s;
		for (int j = 0; j < tot; j++)
			s.insert(v[j]);
		if(s.size() != n || v[0] != v[tot - 1]){
			isC= false;
		}
		if(isC == false){
			printf("Path %d: %d (Not a TS cycle)\n", i + 1, sum);
			continue;
		}
		if(sum < MIN){
			u = i + 1;
			MIN = sum;
		}
		if(tot == n + 1){
			printf("Path %d: %d (TS simple cycle)\n", i + 1, sum);
		}else{
			printf("Path %d: %d (TS cycle)\n", i + 1, sum);
		}
	}
	printf("Shortest Dist(%d) = %d\n", u, MIN);
	return 0;
}
