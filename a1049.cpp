#include <iostream>
using namespace std;

int main() {
    int a, n = 1, now, ans = 0, left, right;
    cin >> a;
    while(a/n){
        now = a / n % 10;
        left = a / (n * 10);
        right = a % n;
        if(now == 0) ans += left * n;
        else if(now == 1) ans += left * n + right + 1;
        else ans += (left + 1) * n;
        n *= 10;
    }
    cout << ans;
    return 0;
}