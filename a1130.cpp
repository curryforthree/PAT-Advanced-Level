#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node{
   string data;
   int l, r;
} Node[25];
bool isRoot[25];
int Root;                    // 记录根结点
//void inOrder(int root){
//    if (root == -1){
//        return;
//    }
//    if(Node[root].l != -1 && Node[root].r != -1 ){
//        if (root != Root){
//            cout << "(";
//            inOrder(Node[root].l);
//            cout << Node[root].data;
//            inOrder(Node[root].r);
//            cout <<")";
//        }else{
//            inOrder(Node[root].l);
//            cout << Node[root].data;
//            inOrder(Node[root].r);
//        }
//    } else if (Node[root].l == -1 && Node[root].r != -1) {
//        if (root != Root){
//            cout << "(";
//            inOrder(Node[root].l);
//            cout << Node[root].data;
//            inOrder(Node[root].r);
//            cout <<")";
//        }else{
//            inOrder(Node[root].l);
//            cout << Node[root].data;
//            inOrder(Node[root].r);
//        }
//    }else{
//        cout << Node[root].data;
//    }
//
//}

void DFS(int root){
    if(root == -1){
        return;
    }
    if(root != Root && (Node[root].l != -1 || Node[root].r != -1)){
        cout << "(";
    }
    DFS(Node[root].l);
    cout << Node[root].data;
    DFS(Node[root].r);
    if(root != Root && (Node[root].l != -1 || Node[root].r != -1)){
        cout << ")";
    }

}

int main() {
    int n;
    cin >> n;
    fill(isRoot, isRoot + 25, true);
    for (int i = 1; i <= n; ++i) {
        cin >> Node[i].data >> Node[i].l >> Node[i].r;
        getchar();
        isRoot[Node[i].l] = isRoot[Node[i].r] = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (isRoot[i] == true){
            Root = i;
            break;
        }
    }
    DFS(Root);
    return 0;
}