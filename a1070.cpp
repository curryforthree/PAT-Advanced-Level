#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int num;
    double price, pp;
};

bool cmp(node a, node b){
    return a.pp > b.pp;
}

int main() {
    int n;
    double d;
    double ans = 0.0;
    cin >> n >> d;
    vector<node> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].num;
    for (int i = 0; i < n; ++i)
        cin >> v[i].price;
    for (int i = 0; i < n; ++i)
        v[i].pp = v[i].price / v[i].num;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if(v[i].num < d){
            ans += v[i].price;
        }else{
            ans += (v[i].pp) * d;
            break;
        }
        d -= v[i].num;
    }
//    while(d > 0){
//        if(d > v[idx].num){
//            ans += v[idx].price;
//        }else{
//            ans += v[idx].pp * d;
//        }
//        d -= v[idx].num;
//        idx++;
//    }
    printf("%.2f", ans);
    return 0;
}