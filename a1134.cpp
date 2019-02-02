#include <iostream>
#include <vector>
#include <map>
using namespace std;
int getEdgeId(int a, int b){
    if(a < b){
        return 10000 * a + b;
    }else{
        return 10000 * b + a;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> allEdge;
    vector<int> G[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v, Edge;
        cin >> u >> v;
        Edge = getEdgeId(u ,v);
        allEdge.push_back(Edge);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    map<int, bool> mp;
    for (int i = 0; i < allEdge.size(); ++i) {
        mp[allEdge[i]] = false;
    }
    int query;
    cin >> query;
    for (int i = 0; i < query; ++i) {
        int k;
        bool flag = true;
        cin >> k;
        vector<int> nowSet(k);
        map<int, bool> temp;
        temp = mp;
        for (int j = 0; j < k; ++j) {
            cin >> nowSet[j];
        }
        for (int j = 0; j < k; ++j) {
            int u = nowSet[j];
            for (int l = 0; l < G[u].size(); ++l) {
                int v = G[u][l];
                int tempEdge = getEdgeId(u, v);
                temp[tempEdge] = true;
            }
        }
        for (auto it = temp.begin();  it != temp.end() ; it++) {
            if (it->second == false){
                printf("No\n");
                flag = false;
                break;
            }
        }
        if(flag == true){
            printf("Yes\n");
        }
    }
    return 0;
}