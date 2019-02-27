#include <bits/stdc++.h>
using namespace std;
bool HashTable[1000000000];

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] > 0 && v[i] < 1000000000){
			HashTable[v[i]] = true;
 		}
	}

	for(int i = 1; i < 100010; i++){
		if(HashTable[i] == false){
			printf("%d\n", i);
			break; 
		}
	}
	return 0;
}
