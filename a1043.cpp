#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
bool cmp(int a, int b){
	return a > b;
}
bool isMirror;

void getPost(int preL, int preR){
	if(preL > preR) return;
	int i = preL + 1, j = preR;         
	if(!isMirror){         // ��BST��������Ӧ�ö�С�ڸ��ڵ㣬������Ӧ�ö����ڵ��ڸ��ڵ� 
		while(i <= preR && pre[preL] > pre[i]) i++;       // �ҵ��������ĵ�һ���ڵ� 
		while(j > preL && pre[preL] <= pre[j]) j--;                 // �ҵ������������һ���ڵ㣬 ����Ӧ��ֻ��һ�� 	
	}else{
		while(i <= preR && pre[preL] <= pre[i]) i++;       // �ҵ��������ĵ�һ���ڵ� 
		while(j > preL && pre[preL] > pre[j]) j--; 
	}
	if(i - j != 1) return;
	getPost(preL + 1, j);
	getPost(i, preR);
	post.push_back(pre[preL]);
}

int main(){
	int n;
	cin >> n;
	pre.resize(n);
	for(int i = 0; i < n; i++)
		cin >> pre[i];		
	getPost(0, n - 1);
	if(post.size() != n){
		isMirror = true;
		post.clear();
		getPost(0, n - 1);
	}
	if(post.size() == n){
		printf("YES\n");
		for(int i = 0; i < n; i++){
			if(i != n - 1) printf("%d ", post[i]);
			else printf("%d\n", post[i]);
		}
	}else{
		printf("NO\n");
	}
	return 0;
}
