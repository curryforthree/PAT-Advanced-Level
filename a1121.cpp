#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000;
vector<int> single;         //记录单身狗
int main() {
    int n, k;
    cin >> n;
    vector<int> couple(maxn, -1);        // 初值不能是0！，因为编号有 0 的人！！！
    for (int i = 0; i < n; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        couple[c1] = c2;
        couple[c2] = c1;
    }
    cin >> k;
    vector<int> join;
    vector<int> isJoin;
    join.resize(k);
    isJoin.resize(maxn);
    for (int i = 0; i < k; ++i) {
        cin >> join[i];
        isJoin[join[i]] = 1;
    }
    for (int i = 0; i < k; i++) {
        if(couple[join[i]] == -1 || isJoin[couple[join[i]]] == 0){
            single.push_back(join[i]);
        }
    }
    sort(single.begin(), single.end());
    printf("%d\n", single.size());
    for (int i = 0; i < single.size(); ++i) {
        if(i != 0) printf(" ");
        printf("%05d", single[i]);
    }
    return 0;
}