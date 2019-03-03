#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a){
	if(a <= 1) return false;
	int sqr = sqrt(a);
	for(int i = 2; i <= sqr; i++){
		if(a % i == 0) return false;
	}
	return true;
}


int main(){
	int l, k;
	cin >> l >> k;
	getchar();
	string a;
	cin >> a;
	int len = l - k;
	for(int i = 0; i <= len; i++){
		string nowS = a.substr(i, k);
		int now = stoi(nowS);
		if(isPrime(now)){
			printf("%s\n", nowS.c_str());
			return 0;
		}
	}
	printf("404\n");
	
	
	
	
	return 0;
}
