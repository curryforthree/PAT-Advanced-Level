#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
struct node {
    int id;
    int s;
};
int n, m;
int Rank[10000000][4];               // 记录每一个id的四门课的rank
int allS[10000000][4];              // alls[id][0] 表示A， [1] 表示C ，2-M， 3—E
char mp[5] = {"ACME"};
bool cmp(node a, node b){
    return a.s > b.s;
}
int main() {
    cin >> n >> m;
    set<int> s;
    int nowRank = 0, nowId;
    vector<node> v;
    for (int i = 0; i < n; ++i) {
        cin >> nowId;
        cin >> allS[nowId][1] >> allS[nowId][2] >> allS[nowId][3];
        s.insert(nowId);
        allS[nowId][0] = (allS[nowId][1] + allS[nowId][2] + allS[nowId][3]) / 3;
    }
    for (nowRank = 0;  nowRank < 4; nowRank++) {
        v.clear();
        for (auto i = s.begin();  i != s.end() ; i++) {
            v.push_back(node{*i, allS[*i][nowRank]});
        }
        sort(v.begin(), v.end(), cmp);
        Rank[v[0].id][nowRank] = 1;
        for (int i = 1; i < v.size(); ++i) {
            if( v[i - 1].s != v[i].s){
                Rank[v[i].id][nowRank] = i + 1;
            } else{
                Rank[v[i].id][nowRank] = Rank[v[i - 1].id][nowRank];
            }
        }
    }
    int query;
    for (int i = 0; i < m; ++i) {
        cin >> query;
        if(s.find(query) == s.end()) {
            printf("N/A\n");
            continue;
        }
        int BestIndex = 0, BestR = INF;
        for (int j = 0; j < 4; ++j) {
            if(Rank[query][j] < BestR){
                BestR = Rank[query][j];
                BestIndex = j;
            }
        }
        printf("%d %c\n", BestR, mp[BestIndex]);
    }
    return 0;
}