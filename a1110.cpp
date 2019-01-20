#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 21;
struct node{
    int l;
    int r;
}Node[maxn];
bool isRoot[maxn];            // isRoot用来判断
int n;                        // 结点数
int BFSJudge(int root){
    queue<int> q;
    q.push(root);
    int count = 0;
    int f;
    while(q.empty() == false){
        f = q.front();
        q.pop();
        count++;
        if (f != -1){
            q.push(Node[f].l);
            q.push(Node[f].r);
        }
        if(count <= n && f == -1){
            return -1;
        }
        if(count == n){
            break;
        }
    }
    return f;
}
int main() {
    int root;        // 根节点
    cin >> n;
    fill(isRoot, isRoot + n, true);    // isRoot 初始化
    for (int i = 0; i < n; ++i) {
        string in1, in2;
        cin >> in1 >> in2;
        if (in1 != "-"){
            Node[i].l = stoi(in1);
            isRoot[Node[i].l] = false;
        } else{
            Node[i].l = -1;
        }
        if (in2 != "-"){
            Node[i].r = stoi(in2);
            isRoot[Node[i].r] = false;
        } else{
            Node[i].r = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]){
            root = i;
            break;
        }
    }
    int res = BFSJudge(root);
    if (res == -1){
        printf("NO %d\n", root);
    } else{
        printf("YES %d\n", res);
    }
    return 0;
}