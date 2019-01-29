#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int id;
    int cnt;
    friend bool operator < (node a, node b){                         // 重载小于号,实现按照题意的自动排序
        return (a.cnt != b.cnt) ? a.cnt > b.cnt : a.id < b.id;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
    }
    set<node> st;
    st.insert(node{queries[0], 1});
    vector<int> Times(n + 1);                                  // 记录每个query出现的次数，方便对set进行查找
    Times[queries[0]] = 1;
    for (int i = 1; i < n; ++i) {
        printf("%d:", queries[i]);
        int printCount = 0;
        for (auto it = st.begin(); printCount < k && it != st.end(); it++) {
            printf(" %d", it->id);
            printCount++;
        }
        auto it = st.find(node{queries[i], Times[queries[i]]});
        if(it == st.end()){
            Times[queries[i]]++;
            st.insert(node{queries[i], Times[queries[i]]});
        }else{
            st.erase(node{queries[i], Times[queries[i]]});
            Times[queries[i]]++;
            st.insert(node{queries[i], Times[queries[i]]});
        }
        printf("\n");

    }
    return 0;
}