#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    string ans;
    ans = to_string(c);
    if(ans[0] == '-'){
        printf("-");
        ans = ans.substr(1);
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%c", ans[i]);
        if((ans.size() - i - 1) % 3 == 0 && i != ans.size() - 1){
            printf(",");
        }
    }
    return 0;
}