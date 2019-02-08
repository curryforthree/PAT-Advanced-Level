#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
int main() {
    vector<double> v(maxn);
    int k, a, cnt = 0;
    double b;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        v[a] += b;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        v[a] += b;
    }
    for (int i = 0; i < v.size(); ++i)
        if(v[i] != 0.0)
            cnt++;
    printf("%d", cnt);
    for (int i = v.size() - 1; i >= 0; --i) {
        if(v[i] != 0.0){
            printf(" %d %.1f", i, v[i]);
        }
    }
    return 0;
}