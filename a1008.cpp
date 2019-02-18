#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, Last = 0, Now, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i) {
        Now = v[i];
        if(Now - Last > 0 ){
            ans += (Now - Last) * 6;
        }else{
            ans += (Last - Now) * 4;
        }
        ans += 5;
        Last = Now;
    }
    cout << ans;
    return 0;
}