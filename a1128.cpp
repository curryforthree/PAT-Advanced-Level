#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> s, xieduijiao, fanxieduijiao;
vector<int> a;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        s.clear();
        a.clear();
        a.resize(n + 1);
        xieduijiao.clear();
        fanxieduijiao.clear();
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
            s.insert(a[j]);
            xieduijiao.insert(j + a[j]);
            fanxieduijiao.insert(j - a[j]);
        }
        if(s.size() != n || xieduijiao.size() != n || fanxieduijiao.size() != n){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}