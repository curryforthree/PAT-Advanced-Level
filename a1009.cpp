#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;

int main() {
    vector<double> a(maxn), b(maxn), res(maxn);
    int k, nowExp, cnt = 0;
    double nowCo;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> nowExp >> nowCo;
        a[nowExp] += nowCo;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> nowExp >> nowCo;
        b[nowExp] += nowCo;
    }
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == 0.0)
            continue;
        for (int j = 0; j < b.size(); ++j) {
            if (b[j] == 0.0)
                continue;
            nowExp = i + j;
            nowCo = a[i] * b[j];
            res[nowExp] += nowCo;
        }
    }
    for (int i = 0; i < res.size(); ++i)
        if (res[i] != 0)
            cnt++;
    printf("%d", cnt);
    for (int i = res.size() - 1; i >= 0; --i) {
        if(res[i]){
            printf(" %d %.1f", i, res[i]);
        }
    }
    return 0;
}