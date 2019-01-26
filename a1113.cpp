#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int len = a.size();
    int t = len/2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < t; ++i) {
        sum1 += a[i];
        sum2 += a[i + t];
    }
    if(len % 2 == 0){
        printf("0 %d", sum2 - sum1);
    }else{
        sum2 += a[a.size() - 1];
        printf("1 %d", sum2 - sum1);
    }

    return 0;
}