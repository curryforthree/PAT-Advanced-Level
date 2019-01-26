#include <iostream>
#include <vector>
using namespace std;
const int maxn = 210;
const int INF = 1000000000;
int G[maxn][maxn];

int main() {
    fill(G[0], G[0] + maxn * maxn, INF);
    int n, v, query;
    cin >> n >> v;
    for (int i = 0; i < v; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }
    cin >> query;
    for (int i = 0; i < query; ++i) {
        int k;
        bool flag = true;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[j];
        }
        if(k != n + 1){
            printf("NO\n");
            continue;
        }
        if(a[0] != a[k - 1]){
            printf("NO\n");
            continue;
        }
        for (int j = 0; j < k - 1; ++j) {
            if (G[a[j]][a[j + 1]] != 1){
                flag = false;
                break;
            }
        }
        if (flag == false){
            printf("NO\n");
            continue;
        }
        vector<bool> Hash(n + 1, false);
        for (int j = 0; j < k - 1; ++j) {
            Hash[a[j]] = true;
        }
        for (int j = 1; j <= n; ++j) {
            if(Hash[j] == false){
                flag = false;
                break;
            }
        }
        if (flag == false){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}