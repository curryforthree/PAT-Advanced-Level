#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	int l, r;
}Node[110];
vector<int> in, layer;       // 存储中序的下标 
void getIn(int root){
	if(root == -1) return;
	getIn(Node[root].l);
	in.push_back(root);
	getIn(Node[root].r);
}

void getLayer(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front = q.front();
		layer.push_back(Node[front].data);
		q.pop();
		if(Node[front].l != -1) q.push(Node[front].l);
		if(Node[front].r != -1) q.push(Node[front].r);
	}

}
int main(){
	int n, tmpl, tmpr;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> tmpl >> tmpr;
		Node[i].l = tmpl;
		Node[i].r = tmpr;
	}
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	getIn(0);
	for(int i = 0; i < n; i++)
		Node[in[i]].data = v[i];
	getLayer(0);
	for(int i = 0; i < layer.size(); i++){
		if(i != layer.size() - 1) printf("%d ", layer[i]);
		else printf("%d\n", layer[i]);
	}
	
	
	return 0;
}
