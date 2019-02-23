#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int data;
    int index;
};
vector<int> post, in;
vector<node> ans;
int n;
bool cmp(node a, node b){
    return a.index < b.index;
}
void getLayer(int root, int l, int r, int index){
    if(l > r) return;
    int k = l;
    while(k < r && in[k] != post[root]){         // 这是循环条件，所以只能写 k < r，之后循环一次之后可能就等于r
        k++;
    }
    ans.push_back(node{post[root], index});
    getLayer(root - 1 - r + k, l, k - 1, index * 2);
    getLayer(root - 1, k + 1, r, index * 2 + 1);
}
int main() {
    cin >> n;
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    getLayer(n - 1, 0, n - 1, 1);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        if(i != ans.size() - 1) printf("%d ", ans[i].data);
        else printf("%d\n", ans[i].data);
    }
    return 0;
}