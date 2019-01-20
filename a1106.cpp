#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int maxn = 100005;

vector<int> child[maxn];    // 树
int minLayer = INF;     // 记录最小的层数
int total = 0;          //  记录最小层数的结点的个数
void DFS(int root, int layer){
    if (child[root].empty() == true){
        if(layer < minLayer){
            total = 1;
            minLayer = layer;
        }else if(layer == minLayer){
            total++;
        }
        return;
    }
    for (int i = 0; i < child[root].size(); ++i) {
        DFS(child[root][i], layer + 1);
    }
}

int main() {
    int n, k, c;
    double p, r;
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> c;
            if(c == 0){
                break;
            }
            child[i].push_back(c);
        }
    }
    DFS(0, 0);
    double res;
//    cout << minLayer << "    " << total;
    res = p * pow((1 + r / 100), minLayer);
    printf("%.4f %d", res, total);
    return 0;
}