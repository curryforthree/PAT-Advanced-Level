#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct node{
    int data;
    node* l;
    node* r;
};
int countNode[maxn];
int maxLayer = -1;
node* insert(node* root, int x){
    if (root == NULL){
        root = new node;
        root->data = x;
        root->l = root->r = NULL;
        return root;
    }
    if (x <= root->data){
        root->l = insert(root->l, x);
    } else{
        root->r = insert(root->r, x);
    }
    return root;
}

void DFS(node* root, int layer){
    if (root == NULL){
        if (layer - 1 > maxLayer){
            maxLayer = layer - 1;
        }
        return;
    }
    countNode[layer]++;
    DFS(root->l, layer + 1);
    DFS(root->r, layer + 1);
}
int main() {
    int n, a;
    cin >> n;
    node* root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        root = insert(root, a);
    }
    DFS(root, 0);
    printf("%d + %d = %d", countNode[maxLayer], countNode[maxLayer - 1], countNode[maxLayer] + countNode[maxLayer - 1]);
    return 0;
}