#include <iostream>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string a, now = "", b;
    map<string, int> mp;
    int m = 0;
    getline(cin, a);
    for (int i = 0; i < a.size(); ++i) {
        if(isalnum(a[i])) {
            if (isupper(a[i])) a[i] = tolower(a[i]);
            now += a[i];
        }
        if(isalnum(a[i]) == false || i == a.size() - 1){
            if(now != ""){
                mp[now]++;
                now = "";
            }
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > m){
            m = it->second;
            b = it->first;
        }
    }
    cout << b << " "<< m;
    return 0;
}