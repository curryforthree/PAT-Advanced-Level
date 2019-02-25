#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node{
	int data; 
	vector<int> child;
}Node[maxn];
int s;
vector<int> tmpAns;
bool cmp(int a, int b){
	return Node[a].data > Node[b].data;
}

void dfs(int root, int nowSum){ 
	if(nowSum > s){
		return;
	}
	if(nowSum == s){
		if(Node[root].child.size() == 0){
			for(int i = 0; i < tmpAns.size(); i++){
				if(i != tmpAns.size() - 1) printf("%d ",tmpAns[i]);
				else printf("%d\n", tmpAns[i]);
			}
		}else{
			return;
		}
	}
	for(int i = 0; i < Node[root].child.size(); i++){
		tmpAns.push_back(Node[Node[root].child[i]].data);
		dfs(Node[root].child[i], nowSum + Node[Node[root].child[i]].data);
		tmpAns.pop_back();
	}
}


int main(){
	int n, m, tmpId, k;
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++)
		cin >> Node[i].data;
	for(int i = 0; i < m; i++){
		cin >> tmpId >> k;
		int tmpC;
		for(int j = 0; j < k; j++){
			cin >> tmpC;
			Node[tmpId].child.push_back(tmpC);
		} 
		sort(Node[tmpId].child.begin(), Node[tmpId].child.end(), cmp);
	}
	tmpAns.push_back(Node[0].data); 
	dfs(0, Node[0].data);
	return 0;
}
