#include <bits/stdc++.h>
using namespace std;
vector<int> v, post;
int m, n;
bool flag;
void judge1(int root){
	if(2 * root <= n){
		if(v[2 * root] > v[root]){
			flag = false;
			return;
		}else{
			judge1(2 * root);
		}
	}
	if(2 * root + 1 <= n){
		if(v[2 * root + 1 ] > v[root]){
			flag = false;
			return;
		}else{
			judge1(2 * root + 1 );
		}
	}
	return;
}
void judge2(int root){
	if(2 * root <= n){
		if(v[2 * root] < v[root]){
			flag = false;
			return;
		}else{
			judge2(2 * root);
		}
	}
	if(2 * root + 1 <= n){
		if(v[2 * root + 1 ] < v[root]){
			flag = false;
			return;
		}else{
			judge2(2 * root + 1 );
		}
	}
	return;
}

void getPost(int root){
	if(root > n) return;
	getPost(root * 2);
	getPost(root * 2 + 1);
	post.push_back(v[root]);
}


int main(){
	
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		v.clear();
		v.resize(n + 1);
		for(int j = 1; j <= n; j++)
			cin >> v[j];
		flag = true;
		if(v[1] > v[2]){
			judge1(1);
			if(flag == true){
				printf("Max Heap\n");
			}
		}else{
			judge2(1);
			if(flag == true){
				printf("Min Heap\n");
			}
		}
		if(flag == false){
			printf("Not Heap\n");
		}
		post.clear();
		getPost(1);
		for(int j = 0; j < post.size(); j++){
			if(j != post.size() - 1) printf("%d ", post[j]);
			else printf("%d\n", post[j]);
		}
	}
	return 0;
}
