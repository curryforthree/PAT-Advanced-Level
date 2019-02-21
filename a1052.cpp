#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 1000000000;
struct Node{
    int address, data, next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b){
    if (a.flag != b.flag) return a.flag > b.flag;
    else  return a.data < b.data;
}

int main() {
    int n, beginA, tmpA, tmpD, tmpN;
    cin >> n >> beginA;
    for (int i = 0; i < 100010; ++i)               // 初始化
        node[i].flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> tmpA >> tmpD >> tmpN;
        node[tmpA].address = tmpA;
        node[tmpA].data = tmpD;
        node[tmpA].next = tmpN;
    }
    int p = beginA, cnt = 0;   //cnt记录有效结点的个数
    while(p != -1){
        cnt++;
        node[p].flag = true;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    if(cnt != 0){
        printf("%d %05d\n", cnt, node[0].address);
        for (int i = 0; i < cnt; ++i) {
            if(i != cnt - 1) printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }else{
        printf("0 -1\n");
    }
    return 0;
}