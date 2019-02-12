#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id;
    string name;
    int s;
};
bool cmp1(node a, node b){
    return a.id < b.id;
}
bool cmp2(node a, node b){
    if(a.name != b.name) return a.name < b.name;
    else return a.id < b.id;
}
bool cmp3(node a, node b){
    if(a.s != b.s) return a.s < b.s;
    else return a.id < b.id;
}
int main() {
    int n, c;
    cin >> n >> c;
    vector<node> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].id >> v[i].name >> v[i].s;
    if(c == 1) sort(v.begin(), v.end(), cmp1);
    else if(c == 2) sort(v.begin(), v.end(), cmp2);
    else sort(v.begin(), v.end(), cmp3);
    for (int i = 0; i < v.size(); ++i)
        printf("%06d %s %d\n", v[i].id, v[i].name.c_str(), v[i].s);
    return 0;
}