#include <iostream>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int cnt[maxn];
int maxN = 1, maxIdx = 1;

void dfs(int index, int layer){
    cnt[layer]++;
    for (int i = 0; i < child[index].size(); ++i) {
        dfs(child[index][i], layer + 1);
    }
}

int main() {
    int n, m, tmpId, k;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmpId >> k;
        int tmpC;
        for (int j = 0; j < k; ++j) {
            cin >> tmpC;
            child[tmpId].push_back(tmpC);
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        if(cnt[i] > maxN){
            maxN = cnt[i];
            maxIdx = i;
        }
    }
    printf("%d %d\n", maxN, maxIdx);
    return 0;
}