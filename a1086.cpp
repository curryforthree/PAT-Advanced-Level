#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> pre, in, ans;
stack<int> st;
void getPost(int root, int inL, int inR){
    if(inL > inR){
        return;
    }
    int k = inL, numLeft = 0;
    while(pre[root] != in[k] && k < inR) k++;
    numLeft = k - inL;
    getPost(root + 1, inL, k - 1);
    getPost(root + numLeft + 1, k + 1, inR);
    ans.push_back(pre[root]);
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < 2 * n; ++i) {
        string a;
        getline(cin, a);
        if(a.size() > 3){     //push
            int tmp = stoi(a.substr(5));
            pre.push_back(tmp);
            st.push(tmp);
        }else{        //pop
            in.push_back(st.top());
            st.pop();
        }
    }
    getPost(0, 0, n - 1);
    for (int i = 0; i < ans.size(); ++i) {
        if(i != ans.size() - 1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
    return 0;
}