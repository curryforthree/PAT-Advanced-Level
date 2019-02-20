#include <iostream>
using namespace std;
const int maxn = 100010;
struct Node{
    int address;
    char data;
    int next;
}node[maxn];

int main() {
    int a1, a2, n, tmpA, tmpN;
    char tmpD;
    cin >> a1 >> a2 >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmpA >> tmpD >> tmpN;
        node[tmpA].address = tmpA;
        node[tmpA].data = tmpD;
        node[tmpA].next = tmpN;
    }
    int p = a1, q = a2, len1 = 0, len2 = 0;    //len1,len2记录两个链表的长度
    while(p != -1){
        len1++;
        p = node[p].next;
    }
    while(q != -1){
        len2++;
        q = node[q].next;
    }
    p = a1; q = a2;
    if(len1 > len2)
        for (int i = 0; i < len1 - len2; ++i)
            p = node[p].next;
    if(len2 > len1)
        for (int i = 0; i < len2 - len1; ++i)
            q = node[q].next;
    while(p != -1 && q != -1){
        if(node[p].address == node[q].address){
            printf("%05d", node[p].address);
            break;
        }
        p = node[p].next;
        q = node[q].next;
    }
    if(q == -1 || p == -1){
        printf("-1");
    }

    return 0;
}