#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    string a, b, c, res;
    int n;
    scanf("%d\n", &n);
    getline(cin, a);
    getline(cin, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == b[i]){
            res += a[i];
        }else{
            break;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        getline(cin, c);
        reverse(c.begin(), c.end());
        for (int j = 0; j < c.size(); ++j) {
            if(c[j] != res[j]){
                res = res.substr(0, j);
                break;
            }
        }
    }
    if(res.size() == 0){
        printf("nai\n");
    }
    else {
        reverse(res.begin(), res.end());
        printf("%s\n", res.c_str());
    }
    return 0;
}