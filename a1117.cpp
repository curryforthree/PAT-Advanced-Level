#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main() {
    int n, res = 0;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i <= a.size(); ++i) {
        if (a[i - 1] > i){
            res++;
        }
    }
    cout << res;
    return 0;
}