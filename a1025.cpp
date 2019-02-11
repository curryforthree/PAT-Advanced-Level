#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int s, locIdx, locRank;
};
bool cmp(node a, node b){
    if(a.s != b.s) return a.s > b.s;
    else return a.name < b.name;
}
int main() {
    int n, k;
    cin >> n;
    vector<node> all;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        vector<node> v(k);
        for (int j = 0; j < k; ++j){
            cin >> v[j].name >> v[j].s;
            v[j].locIdx = i + 1;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].locRank = 1;
        all.push_back(v[0]);
        for (int j = 1; j < k; ++j) {
            if(v[j].s != v[j - 1].s) v[j].locRank = j + 1;
            else v[j].locRank = v[j - 1].locRank;
            all.push_back(v[j]);
        }
    }
    sort(all.begin(), all.end(), cmp);
    printf("%d\n", all.size());
    int LastRank = 1;
    printf("%s %d %d %d\n", all[0].name.c_str(), 1, all[0].locIdx, all[0].locRank);
    for (int i = 1; i < all.size(); ++i) {
        printf("%s ", all[i].name.c_str());
        if(all[i].s != all[i - 1].s){
            printf("%d ", i + 1);

            LastRank = i + 1;
        } else {
            printf("%d ", LastRank);
        }
        printf("%d %d\n", all[i].locIdx, all[i].locRank);
    }
    return 0;
}