#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<int, string> mp;
char a[5] = {'S', 'H', 'C', 'D', 'J'};
void init(){
    for (int i = 1; i <= 54; ++i) {
        mp[i] = a[(i - 1) / 13] + to_string(i % 13 ? i % 13 : 13);
    }
}
int main() {
    int k;          // 重复次数
    cin >> k;
    init();
    vector<int> v(55), seq(55), next(55);
    for (int i = 0; i <= 54; ++i)          //序列初始化
        v[i] = i;
    for (int i = 0; i < 54; ++i)
        cin >> seq[i + 1];
    for (int i = 0; i < k; ++i) {       // 洗牌k次
        for (int j = 1; j <= 54; ++j)
            next[seq[j]] = v[j];
        v = next;
    }
    for (int i = 1; i < v.size(); ++i) {
        printf("%s", mp[v[i]].c_str());
        if(i != v.size() - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}