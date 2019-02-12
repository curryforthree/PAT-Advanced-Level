#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string name, id;
    int s;
};
bool cmp(node a, node b){
    return a.s > b.s;
}
int main() {
    int n, gL, gH;
    cin >> n;
    vector<node> v(n), ans;
    for (int i = 0; i < n; ++i)
        cin >> v[i].name >> v[i].id >> v[i].s;
    cin >> gL >> gH;
    for (int i = 0; i < n; ++i) {
        if(v[i].s >= gL && v[i].s <= gH){
            ans.push_back(v[i]);
        }
    }
    if(ans.size() == 0){
        printf("NONE\n");
        return 0;
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %s\n", ans[i].name.c_str(), ans[i].id.c_str());
    }
    return 0;
}