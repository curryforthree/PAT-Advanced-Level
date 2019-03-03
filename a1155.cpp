#include <bits/stdc++.h>
using namespace std;
vector<int> level, tmp;

int n;
void dfs(int root){
	if(root > n) return;
	if(2 * root > n && 2 * root + 1 > n){
		tmp.push_back(level[root]);
		for(int i = 0; i < tmp.size(); i++){
			if(i != tmp.size() - 1) printf("%d ", tmp[i]);
			else printf("%d\n", tmp[i]);
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(level[root]);
	dfs(2 * root + 1);
	dfs(2 * root);
	tmp.pop_back();
}

int main(){
	bool flag = true;
	cin >> n;
	level.resize(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> level[i];
	dfs(1);
	if(level[1] > level[2]){   // ºÏ≤È «∑Ò¥Û∂•∂— 
		for(int i = 1; i <= n; i++){
			if(2* i <= n && level[i] < level[2 * i]){
				flag = false;
				break;
			}
			if(2* i + 1 <= n && level[i] < level[2 * i + 1]){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("Max Heap\n");
		}else{
			printf("Not Heap\n");
		}
	}else{
		for(int i = 1; i <= n; i++){
			if(2* i <= n && level[i] > level[2 * i]){
				flag = false;
				break;
			}
			if(2* i + 1 <= n && level[i] > level[2 * i + 1]){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("Min Heap\n");
		}else{
			printf("Not Heap\n");
		}
	}
	return 0;
}
