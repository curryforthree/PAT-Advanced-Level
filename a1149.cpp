#include <bits/stdc++.h>
using namespace std;

int getId(int a, int b){
	if(a > b) swap(a, b);
	return 100000 * a + b;
}

int main(){
	int n, m, u, v, k;
	set<int> s;
	map<int, bool> mp;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &u, &v);
		int tmpId = getId(u, v);
		s.insert(tmpId);
		mp[u] = true;
		mp[v] = true;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &k);
		vector<int> v(k);
		bool flag = true;
		for(int j = 0; j < k; j++)
		 	scanf("%d", &v[j]);
		for(int j = 0; j < k; j++){
			if(mp[v[j]] == false) continue;
			for(int l = j + 1; l < k; l++){
				int q = getId(v[j], v[l]);
				if(s.find(q) != s.end()){
					flag = false;
					break;
				}
			}
			if(flag == false) break;
		} 
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
