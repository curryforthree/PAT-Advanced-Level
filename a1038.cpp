#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return (a + b) <  (b + a);
}

int main() {
    int n, pos = -1;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end(),cmp);
    string ans;
    for (int i = 0; i < n; ++i)
        ans += v[i];
    for (int i = 0; i < ans.size(); ++i) {
        if(ans[i] == '0')
            continue;
        pos = i;
        break;
    }
    if(pos == -1){
        printf("\n");
        return 0;
    }
    ans = ans.substr(pos);
    cout << ans;
    return 0;
}