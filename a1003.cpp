#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int G[510][510];
bool visit[510] = {false};
int d[510];     // 最短距离
int weight[510];    // 顶点的权重
int w[510] = {0};         // 顶点对应最短路径上的最大权重和
int numPath[510] = {0};    // 最短路径条数

int main() {
    int n, m, c1, c2;
    int a, b, c;
    cin >> n >> m >> c1 >> c2;
    fill(G[0], G[0] + 510 * 510, INF);
    fill(d, d + 510, INF);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c;
    }

    d[c1] = 0;
    w[c1] = weight[c1];
    numPath[c1] = 1;
    for (int i = 0; i < n; ++i) {    // dijkstra  有n个顶点 循环n次

        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1){
            break;
        }
        visit[u] = true;
        for (int v = 0; v < n; ++v) {
            if(G[u][v] != INF && visit[v] != true){
                if(d[v] > G[u][v] + d[u]){
                    d[v] = G[u][v] + d[u];
                    numPath[v] = numPath[u];
                    w[v] = w[u] + weight[v];
                }else if(d[v] == G[u][v] + d[u]){
                    numPath[v] += numPath[u];
                    if (w[v] < w[u] + weight[v]){
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
    printf("%d %d", numPath[c2], w[c2]);
    return 0;
}