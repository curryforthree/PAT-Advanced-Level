#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> inIdx;
void getInorderIdx(int root){
	if(root > n){
		return;
	}
	getInorderIdx(2 * root);
	inIdx.push_back(root);
	getInorderIdx(2 * root + 1);
}

int main(){
	cin >> n;
	vector<int> v(n), ans(n + 1);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	getInorderIdx(1);
	for(int i = 0; i < n; i++)
		ans[inIdx[i]] = v[i];
	for(int i = 1; i <= n; i++)
		if(i != n) printf("%d ", ans[i]);
		else printf("%d\n", ans[i]);
	return 0;
}
