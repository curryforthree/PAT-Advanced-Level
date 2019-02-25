#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
void downAdjust(int low, int high){
	int i = low, j = 2 * i;   
	while(j <= high){
		if(j + 1 <= high && a[j + 1] > a[j]){
			j += 1;
		}
		if(a[i] < a[j]){
			swap(a[i], a[j]);
			i = j;
			j =  2*i;
		}else{
			break;
		}
	}
}
int main(){
	bool flag = false;
	cin >> n;
	a.resize(n + 1), b.resize(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	int idx = 0, p;
	while(idx <= n && b[idx] <= b[idx + 1]) idx++;
	p = idx + 1;
	while(p <= n && a[p] == b[p]) p++;
	if(p == n + 1){
		printf("Insertion Sort\n");
		sort(b.begin() + 1, b.begin() + idx + 2);
		for(int i = 1; i <= n; i++){
			 if(i != n)	printf("%d ", b[i]);
			 else printf("%d\n", b[i]);
		}
	}else{
		printf("Heap Sort\n");
		for(int i = n / 2; i >= 1; i--)
			downAdjust(i, n);
		for(int i = n; i > 1; i--){
			swap(a[1], a[i]);
			downAdjust(1, i - 1);
			if(a == b){
				flag = true;
				continue;
			}
			if(flag){
				for(int i = 1; i <= n; i++){
			 		if(i != n)	printf("%d ", a[i]);
			 		else printf("%d\n", a[i]);
				}
				break;	
			}
		} 
	}	
	return 0;
}
