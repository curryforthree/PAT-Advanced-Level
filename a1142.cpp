#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];

int main(){
	int nv, ne;
	cin >> nv >> ne;
	int a, b;
	for(int i = 0; i < ne; i++){
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d", &k);
		bool flag1 = true, flag2 = true;
		vector<int> v(k);
		vector<int> HashT(nv + 1);
 		for(int j = 0; j < k; j++){
			cin >> v[j];
			HashT[v[j]] = 1;
		}
		for(int j = 0; j < k - 1; j++){
			for(int l = j + 1; l < k; l++){
				if(G[ v[j] ][ v[l] ] == 0){
					flag1 = false;
					break;
				}
			}
			if(flag1 == false) break;
		}
		if(flag1 == false){
			printf("Not a Clique\n");
			continue;
		}
		for(int j = 1; j <= nv; j++){
			if(HashT[j] == 0){
				int l;
				for(l = 0; l < k; l++){
					if(G[j][v[l]] == 0){
						break;
					}
				}
				if(l == k){
					flag2 = false;
					break;
				}
			}
		}
		if(flag2 == false){
			printf("Not Maximal\n");
			continue;
		}
		if(flag1 && flag2){
			printf("Yes\n");
		}
	}
	
	return 0;
	
}
