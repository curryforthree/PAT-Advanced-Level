#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int maxn = 510;
int G[maxn][maxn];
int degree[maxn];
int n, m;
vector<bool> visit;
int Count = 0;
void DFS(int u){
    visit[u] = true;
    Count++;
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] != 0 && visit[i] == false){
            DFS(i);
        }
    }
}


int main() {
    int u, v;
    cin >> n >> m;
    visit.resize(n + 1);
    fill(G[0], G[0] + maxn * maxn, 0);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << degree[i];
        if (i != n){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    vector<int> odd;
    vector<int> even;
    for (int i = 1; i <= n; ++i) {
        if(degree[i] % 2 == 0){
            even.push_back(i);
        } else{
            odd.push_back(i);
        }
    }
    DFS(1);
    if(Count != n){
        printf("Non-Eulerian\n");
    }else if(odd.size() == 2 ){
        printf("Semi-Eulerian\n");
    } else if(odd.size() == 0){
        printf("Eulerian\n");
    } else{
        printf("Non-Eulerian\n");
    }
    return 0;
}