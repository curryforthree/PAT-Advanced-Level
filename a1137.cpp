#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int gp, gm, gf, g;
};
bool cmp(node a, node b){
    if(a.g != b.g) return a.g > b.g;
    else return a.name < b.name;
}
map<string, int> mp;
vector<node> v, ans;
int main() {
    int p, m, n, score, cnt = 1;
    string s;
    scanf("%d %d %d\n" ,&p, &m, &n);
    for (int i = 0; i < p; ++i) {
        cin >> s >> score;
        if(score >= 200){
            mp[s]= cnt++;
            v.push_back(node{s, score, -1, -1, 0});
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> s >> score;
        if(mp[s]){
            int nowIdx = mp[s] - 1;
            v[nowIdx].gm = score;
        }
    }
    for (int j = 0; j < n; ++j) {
        cin >> s >> score;
        if(mp[s]){
            int nowIdx = mp[s] - 1;
            v[nowIdx].gf = score;
            if(v[nowIdx].gm > v[nowIdx].gf){
                v[nowIdx].g = 0.4 * v[nowIdx].gm + 0.6 * v[nowIdx].gf + 0.5;
            }else{
                v[nowIdx].g = v[nowIdx].gf;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if(v[i].g >= 60) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    }




    return 0;
}