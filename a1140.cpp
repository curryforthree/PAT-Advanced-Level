#include <bits/stdc++.h>
using namespace std;
int main(){
	int d, n;
	cin >> d >> n;
	string a = to_string(d);
	while(n > 1){
		int len = a.size(), cnt = 1;
		string tmp;
		for(int i = 0; i < len; i++){
			char now = a[i];
			int left = i, right = i;
			while(right < len && a[right] == a[left]) right++;
			cnt = right - left;
			tmp += now;
			tmp += to_string(cnt);
			i = right - 1;
		}
		a = tmp;
		n--;
	}
	cout << a;
	return 0;
}
