#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> v(n);
        stack<int> st;
        bool flag = true;
        for (int j = 0; j < n; ++j)
            cin >> v[j];
        int idx = 0;            // idx用来表示弹出序列的序号
        int maxNum = 0;         // 记录最大容量
        for (int j = 1; j <= n; ++j) {
            st.push(j);
            if(st.size() > maxNum) {
                maxNum = st.size();
            }
            while(!st.empty() && st.top() == v[idx]){     // 栈顶元素即为现在需要输出序列的第一个,就一直弹出
                st.pop();
                idx++;
            }
        }
        if(idx != n  || maxNum > m || st.size() != 0) flag = false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}