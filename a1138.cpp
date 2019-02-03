#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre, in, post;
void getPost(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return;
    }
    int k = inL;
    while(in[k] != pre[preL]){
        k++;
    }
    int numLeft = k - inL;
    getPost(preL + 1, preL + numLeft, inL, k - 1);
    getPost(preL + numLeft + 1, preR, k + 1, inR);
    post.push_back(pre[preL]);
    return;
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    getPost(0, n - 1, 0, n - 1);
    cout << post[0] << endl;
    return 0;
}