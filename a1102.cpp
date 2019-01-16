#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 15;

bool isroot[maxn];
int printC = 0;

struct node{
    int l;
    int r;

} Node[maxn];

int getRoot(int n){
    for (int i = 0; i < n; ++i) {
        if(isroot[i]){
            return i;
        }
    }
    return -1;
}

void reverse(int root){
    if (Node[root].l == -1 && Node[root].r == -1){
        return;
    }
    if (Node[root].r != -1){
        reverse(Node[root].r);
    }
    if (Node[root].l != -1){
        reverse(Node[root].l);
    }
    swap(Node[root].l, Node[root].r);
}

void inOrder(int root, int n){
    if (Node[root].l != -1){
        inOrder(Node[root].l, n);
    }
    printf("%d", root);
    printC++;
    if (printC < n){
        printf(" ");
    }
    if (Node[root].r != -1){
        inOrder(Node[root].r, n);
    }
}

void levelOrder(int root, int n){
    queue<int> q;
    q.push(root);
    while(q.empty() == false){
        int front = q.front();
        q.pop();
        printf("%d", front);
        printC++;
        if (printC < n){
            printf(" ");
        }else{
            printf("\n");
        }
        if (Node[front].l != -1){
            q.push(Node[front].l);
        }
        if (Node[front].r != -1){
            q.push(Node[front].r);
        }
    }
}

int main() {
    int n;
    string a;
    fill(isroot, isroot + maxn, true);
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        getline(cin, a);
        if (a[0] >= '0' && a[0] <= '9'){
            Node[i].l = a[0] - '0';
            isroot[a[0] - '0'] = false;

        }else{
            Node[i].l = -1;
        }
        if (a[2] >= '0' && a[2] <= '9'){
            Node[i].r = a[2] - '0';
            isroot[a[2] - '0'] = false;

        }else{
            Node[i].r = -1;
        }
    }
    int root = getRoot(n);
    reverse(root);
    levelOrder(root, n);
    printC = 0;
    inOrder(root, n);
    return 0;
}