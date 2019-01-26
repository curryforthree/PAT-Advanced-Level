#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int father[maxn];
set<int> bird;               // 记录所有的鸟
set<int> allRoot;
int findFather(int a){
    int x = a;
    while(a != father[a]){
        a = father[a];
    }
    while (x != father[x]){
        int z = x;
        x = father[x];
        father[z] = a;
    }
    return a;
}
void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faB] = faA;
    }
}
int main() {
    int n, k, q, query1, query2, First, Id;
    scanf("%d", &n);
    for (int i = 0; i < maxn; ++i) {       // 并查集初始化
        father[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &k, &First);
        bird.insert(First);
        for (int j = 0; j < k - 1; ++j) {
            scanf("%d", &Id);
            bird.insert(Id);
            Union(First, Id);
        }
    }
    for(auto it = bird.begin(); it != bird.end(); it++){
        if(father[*it] == *it){
            allRoot.insert(*it);
        }
    }
    printf("%d %d\n", allRoot.size(), bird.size());
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &query1, &query2);
        if (findFather(query1) == findFather(query2)){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
    }
    return  0;
}