#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int cnt[maxn];
int maxL = -1;
void dfs(int idx, int layer){
    cnt[layer]++;
    if(layer > maxL){
        maxL = layer;
    }
    for (int i = 0; i < child[idx].size(); ++i) {
        dfs(child[idx][i], layer + 1);
    }
}
int main() {
    int n, root, tmp;
    double p, r, ans = 0.0;
    cin >> n >> p >> r;
    r /= 100;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == -1){
            root = i;
        }else{
            child[tmp].push_back(i);
        }
    }
    dfs(root, 0);
    ans = p * pow(1 + r, maxL);
    printf("%.2f %d\n", ans, cnt[maxL]);
    return 0;
}