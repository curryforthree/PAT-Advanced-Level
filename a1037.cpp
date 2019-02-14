#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    cin >> m;
    vector<int> pro(m);
    for (int i = 0; i < m; ++i)
        cin >> pro[i];
    sort(c.begin(), c.end());
    sort(pro.begin(), pro.end());
    int p = 0, q = 0;
    while(c[p] < 0 && pro[q] < 0 && p < n && q < m){
        ans += c[p] * pro[q];
        p++;
        q++;
    }
    p = n - 1; q = m - 1;
    while(c[p] > 0 && pro[q] > 0 && p >= 0 && q >= 0){
        ans += c[p] * pro[q];
        p--;q--;
    }
    printf("%d\n", ans);
    return 0;
}