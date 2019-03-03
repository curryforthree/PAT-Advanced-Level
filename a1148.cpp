#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			vector<int> a(n + 1, 1);
			vector<int> w;
			a[i] = a[j] = -1;
			int cnt = 0;
			for(int k = 1; k <= n; k++){
				if(v[k] * a[abs(v[k])] < 0){
					w.push_back(k);
					if(k == i) cnt++;
					if(k == j) cnt++;
				}
			}
			if(w.size() == 2 && cnt == 1){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
