#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, k, temp, q, a, b;
    cin >> n;
    vector<set<int> > v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> temp;
            v[i].insert(temp);
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        int cnt = 0, tot = v[b].size();
        for (auto it = v[a].begin();  it != v[a].end() ; it++) {
            if(v[b].find(*it) == v[b].end()){                    //a中的元素b中没有
                tot++;                                           // 总数加1
            }else{                               // a,b都有
                cnt++;
            }
        }
        double ans = cnt * 1.0 / tot * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}