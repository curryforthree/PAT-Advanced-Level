#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
    int address;
    int data;
    int next;
}List[maxn];

int main() {
    int start, n, k;
    cin >> start >> n >> k;
    for (int i = 0; i < n; ++i) {
        int now, d, next;
        cin >> now >> d >> next;
        List[now].address = now;
        List[now].data = d;
        List[now].next = next;
    }
    vector<node> ans;
    int p = start;
    while(p != -1){
        if(List[p].data < 0){
            ans.push_back(List[p]);
        }
        p = List[p].next;
    }
    p = start;
    while(p != -1){
        if(List[p].data >= 0 && List[p].data <= k){
            ans.push_back(List[p]);
        }
        p = List[p].next;
    }
    p = start;
    while(p != -1){
        if(List[p].data >k){
            ans.push_back(List[p]);
        }
        p = List[p].next;
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i < ans.size() - 1){
            printf("%05d %d %05d\n" , ans[i].address, ans[i].data, ans[i + 1].address);
        }else{
            printf("%05d %d -1\n" , ans[i].address, ans[i].data);
        }

    }
    return 0;
}