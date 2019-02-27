#include <bits/stdc++.h>
using namespace std;
vector<int> pre;
int main(){
	int m, n;
	cin >> m >> n;
	pre.resize(n);
	set<int> s;
	for(int i = 0; i < n; i++){
		cin >> pre[i];
		s.insert(pre[i]);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		bool flag1 = false, flag2 = false;
		if(s.find(a) == s.end()) flag1 = true;
		if(s.find(b) == s.end()) flag2 = true;
		if(flag1 && flag2) {
			printf("ERROR: %d and %d are not found.\n", a, b);
			continue;
		}
		else if(flag1){
			 printf("ERROR: %d is not found.\n", a);
			 continue;
		}
		else if(flag2){
			printf("ERROR: %d is not found.\n", b);
			continue;
		}
		int root = 0;
		while(root < n){
			if(pre[root] > a && pre[root] > b){
				int idx = root;
				while(idx < n && pre[idx] >= pre[root]) idx++;
				root = idx;
			}else if(pre[root] < a && pre[root] < b){
				int idx = root;
				while(idx < n && pre[idx] <= pre[root]) idx++;
				root = idx;
			}else{
				break;
			}
		}
		if(pre[root] == a){
			printf("%d is an ancestor of %d.\n", a, b);
		}else if(pre[root] == b){
			printf("%d is an ancestor of %d.\n", b, a);
		}else{
			printf("LCA of %d and %d is %d.\n", a, b, pre[root]);
		}
	}
	return 0;
}
