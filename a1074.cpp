#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 1000000000;
struct Node{
    int address, data, next, idx;
}node[maxn];

bool cmp(Node a, Node b){
    return a.idx < b.idx;
}

int main() {
    int firstAddress, n, k, tmpAddress, tmpData, tmpNxt;
    cin >> firstAddress >> n >> k;
    for (int i = 0; i < 100010; ++i)
        node[i].idx = INF;
    for (int i = 0; i < n; ++i) {
        cin >> tmpAddress >> tmpData >> tmpNxt;
        node[tmpAddress].address = tmpAddress;
        node[tmpAddress].data = tmpData;
        node[tmpAddress].next = tmpNxt;
    }
    int p = firstAddress, cnt = 0;     // cnt记录结点
    while(p != -1){
        node[p].idx = cnt++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);     // 前面即为要输出的
    n = cnt;
    int a = n / k;         // 要分几块输出
    for (int i = 0; i < a; ++i) {
        int start = (i + 1) * k - 1, end = i * k;     // 每一块的开头与结尾
        for (int j = start; j >= end; --j) {
            if(j != end) printf("%05d %d %05d\n",node[j].address, node[j].data, node[j - 1].address);
            else if(j == end && i != a - 1) printf("%05d %d %05d\n",node[j].address, node[j].data, node[(i + 2) * k - 1].address);
            else if(j == end && i == a - 1 && n % k == 0) printf("%05d %d -1\n",node[j].address, node[j].data);
            else if(j == end && i == a - 1 && n % k != 0) printf("%05d %d %05d\n",node[j].address, node[j].data, node[start + 1].address);
        }
    }
    if(n % k){
        for (int i = a * k ; i < n; ++i) {
            if(i != n - 1) printf("%05d %d %05d\n",node[i].address, node[i].data, node[i + 1].address);
            else printf("%05d %d -1\n",node[i].address, node[i].data);
        }
    }
    return 0;
}