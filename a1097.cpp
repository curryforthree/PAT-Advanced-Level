#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 100010;
map<int, bool> mp;

struct Node{
    int address;
    int data;
    int next;
}node[maxn];

int main() {
    int beginA, n, tmpA, tmpD, tmpN;
    cin >> beginA >> n;
    for (int i = 0; i < 10010; ++i)     // mp初始化
        mp[i] = false;
    for (int i = 0; i < n; ++i) {
        cin >> tmpA >> tmpD >> tmpN;
        node[tmpA].address = tmpA;
        node[tmpA].data = tmpD;
        node[tmpA].next  =tmpN;
    }
    vector<Node> v;                    // 记录被删去的结点
    int p = node[beginA].next, pre = beginA, cnt = 1;          // cnt记录最终链表上的结点个数
    mp[abs(node[beginA].data)] = true;
    while(p != -1){
        if(mp[abs(node[p].data)] == true){
            node[pre].next = node[p].next;
            v.push_back(node[p]);              // 被删除的结点加入v中
            p = node[p].next;
        }else{
            cnt++;
            mp[abs(node[p].data)] = true;
            pre = p;
            p = node[p].next;
        }
    }
    p = beginA;
    for (int i = 0; i < cnt; ++i) {
        if(i != cnt - 1) printf("%05d %d %05d\n", node[p].address, node[p].data, node[node[p].next].address);
        else printf("%05d %d -1\n", node[p].address, node[p].data);
        p = node[p].next;
    }
    for (int i = 0; i < v.size(); ++i) {
        if(i != v.size() - 1) printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);
        else printf("%05d %d -1\n", v[i].address, v[i].data);
    }
    return 0;
}