#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int m, n, temp, ans;
    map<int, int> mp;
    cin >> m >> n;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> temp;
            mp[temp]++;
            if(mp[temp] > m * n / 2){
                flag = true;
                ans = temp;
                break;
            }
        }
        if(flag) break;
    }
//    for (auto it = mp.begin();  it != mp.end(); it++) {
//        if(it->second > m * n / 2){
//            ans = it->first;
//            break;
//        }
//    }
    cout << ans;
    return 0;
}