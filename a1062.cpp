#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id, Gv, Gt, Gtotal;
    int r;
};

bool cmp(node a, node b){
    if(a.r != b.r){
        return a.r < b.r;
    }else if(a.Gtotal != b.Gtotal){
        return a.Gtotal > b.Gtotal;
    }else if(a.Gv != b.Gv){
        return a.Gv > b.Gv;
    }else{
        return a.id < b.id;
    }
}

int main() {
    int n, L, H;
    cin >> n >> L >> H;
    vector<node> v(n), ans;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].id >> v[i].Gv >> v[i].Gt;
        v[i].Gtotal = v[i].Gt + v[i].Gv;
        if(v[i].Gv < L || v[i].Gt < L){
            continue;
        }
        if(v[i].Gt >= H && v[i].Gv >= H){
            v[i].r = 1;
        }else if(v[i].Gv >= H && v[i].Gt < H){
            v[i].r = 2;
        }else if(v[i].Gv >= v[i].Gt){
            v[i].r = 3;
        }else{
            v[i].r = 4;
        }
        ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%08d %d %d\n", ans[i].id, ans[i].Gv, ans[i].Gt);
    }
    return 0;
}