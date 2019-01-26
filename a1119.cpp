#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre, post;
vector<int> in;
bool isUnique = true;

void getIn(int preL, int preR, int postL, int postR){
    if(preL == preR){
        in.push_back(pre[preL]);
        return;
    }
    int i = preL + 1;
    while(i <= preR && pre[i] != post[postR - 1]){
        i++;
    }
    if (i > preL + 1){
        getIn(preL + 1, i - 1, postL, postL + i - preL - 2);
    }else{
        isUnique = false;
    }
    in.push_back(pre[preL]);
    getIn(i, preR, postL + i - preL - 1, postR - 1);
    return;
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    getIn(0, n - 1, 0, n - 1);
    if(isUnique == true){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    for (int i = 0; i < in.size(); ++i) {
        printf("%d", in[i]);
        if (i != in.size() - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}