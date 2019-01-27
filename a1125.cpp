#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = a[0];
    for (int i = 1; i < a.size(); ++i) {
        res += a[i];
        res /= 2;
    }
    cout << res;

    return 0;
}