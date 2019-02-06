#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 10010;
set<int> B, G;
set<int> allEdge;
vector<int> BB[maxn], GG[maxn], BG[maxn];
int getEdge(int a, int b){
    return a > b ? 10000 * b + a : 10000 * a + b;
}
struct node{
    int a, b;
};
int main() {
    int n, m, query;
    string a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int u = 0, v = 0;
        if(a.size() > b.size()){        // a的长度> b的长度，说明a是女生
            u = -stoi(a);
            v = stoi(b);
            G.insert(u);
            B.insert(v);
            BG[u].push_back(v);
            BG[v].push_back(u);
            allEdge.insert(getEdge(u, v));
        } else if(a.size() < b.size()){    // 同理 ,a是男生
            u = stoi(a);
            v = -stoi(b);
            G.insert(v);
            B.insert(u);
            BG[u].push_back(v);
            BG[v].push_back(u);
            allEdge.insert(getEdge(u, v));
        }else{                            // 同性
            if(a.size() == 4){              //同为男生
                u = stoi(a);
                v = stoi(b);
                B.insert(u);
                B.insert(v);
                BB[u].push_back(v);
                BB[v].push_back(u);
                allEdge.insert(getEdge(u, v));
            }else{                        //同为女生
                u = -stoi(a);
                v = -stoi(b);
                G.insert(u);
                G.insert(v);
                GG[u].push_back(v);
                GG[v].push_back(u);
                allEdge.insert(getEdge(u, v));
            }
        }
    }
    for (auto it = B.begin(); it != B.end(); it++) {
        sort(BB[*it].begin(), BB[*it].end());
    }
    for (auto it = G.begin(); it != G.end(); it++) {
        sort(GG[*it].begin(), GG[*it].end());
    }
    cin >> query;
    int cnt = 0;
    vector<node> ans;
    for (int i = 0; i < query; ++i) {
        int u, v;
        cnt = 0;
        ans.clear();
        cin >> a >> b;
        if (a.size() > b.size()){            // a是女生  b是男
            u = -stoi(a);
            v = stoi(b);
            for (int j = 0; j < GG[u].size(); ++j) {
                for (int k = 0; k < BB[v].size(); ++k) {
                    if(allEdge.find( getEdge(GG[u][j], BB[v][k]) ) != allEdge.end() ){
                        cnt++;
                        ans.push_back(node{GG[u][j], BB[v][k]});
                    }
                }
            }
        }else if(a.size() < b.size()){           //a是男生，b是女生
            u = stoi(a);
            v = -stoi(b);
            for (int j = 0; j < BB[u].size(); ++j) {
                for (int k = 0; k < GG[v].size(); ++k) {
                    if(allEdge.find( getEdge(BB[u][j], GG[v][k]) ) != allEdge.end() ){
                        cnt++;
                        ans.push_back(node{BB[u][j], GG[v][k]});
                    }
                }
            }
        } else{            // 同性
            if(a.size() == 4){       // 同为男生
                u = stoi(a);
                v = stoi(b);
                for (int j = 0; j < BB[u].size(); ++j) {
                    for (int k = 0; k < BB[v].size(); ++k) {
                        if(allEdge.find( getEdge(BB[u][j], BB[v][k]) ) != allEdge.end() && BB[u][j] != v && BB[v][k] != u ){
                            cnt++;
                            ans.push_back(node{BB[u][j], BB[v][k]});
                        }
                    }
                }
            }else{
                u = -stoi(a);
                v = -stoi(b);
                for (int j = 0; j < GG[u].size(); ++j) {
                    for (int k = 0; k < GG[v].size(); ++k) {
                        if(allEdge.find( getEdge(GG[u][j], GG[v][k]) ) != allEdge.end() && GG[u][j] != v && GG[v][k] != u){
                            cnt++;
                            ans.push_back(node{GG[u][j], GG[v][k]});
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
        for (int j = 0; j < cnt; ++j) {
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }
    return 0;
}