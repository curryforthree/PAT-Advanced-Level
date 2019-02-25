#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    vector<int> child;        // 存储树
    double num;
}Node[maxn];
int isRoot[maxn];
double ans = 0.0;
double p, r;

void dfs(int root, int layer){
    if(Node[root].child.size() == 0){
        ans += p * pow((1 + r), layer) * Node[root].num;
        return;
    }
    for (int i = 0; i < Node[root].child.size(); ++i) {
        dfs(Node[root].child[i], layer + 1);
    }
}

int main() {
    int n, k, tmpc, root;
    cin >> n >> p >> r;
    r /= 100;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if(k == 0){
            isRoot[i] = 1;
            cin >> Node[i].num;
        }else{
            for (int j = 0; j < k; ++j) {
                cin >> tmpc;
                isRoot[tmpc] = 1;
                Node[i].child.push_back(tmpc);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", ans);
    return 0;
}