#include <iostream>
#include <set>
#include <string>
using namespace std;
set<int> s;
int main() {
    int n, now;
    cin >> n;
    string a;
    for (int i = 0; i < n; ++i) {
        cin >> now;
        a = to_string(now);
        int sum = 0;
        for (int j = 0; j < a.length(); ++j) {
            sum += a[j] - '0';
        }
        s.insert(sum);
    }
    printf("%d\n", s.size());
    for (auto i = s.begin();  i != s.end() ; i++) {
        if (i == s.begin()){
            printf("%d", *i);
        }else{
            printf(" %d", *i);
        }
    }
    return 0;
}