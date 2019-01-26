#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 10000;
struct person{
    int id;
    int m;
    int area;
} p[maxn];
struct family{
    int rootId;
    int numPep;
    int sumArea;
    int sumSets;
    double averArea;
    double averSets;
} f[maxn];
int father[maxn];
bool cmp(family a, family b){
    if (a.averArea != b.averArea){
        return a.averArea > b.averArea;
    } else{
        return a.rootId < b.rootId;
    }
}
int findFather(int a){
    while(a != father[a]){
        a = father[a];
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
    int n;
    int nowId, fa, mom, k, child, estate, tempArea;
    set<int> all;                          //all记录所有的 结点id
    vector<int> root;                       //root记录所有的根结点
    int count = 0;                                  //记录有几个根结点
    cin >> n;
    for (int i = 0; i < maxn; ++i) {           //father数组初始化
        father[i] = i;
    }
    for (int i = 0; i < n; ++i) {              // 输入处理
        scanf("%d %d %d %d", &nowId, &fa, &mom, &k);
        all.insert(nowId);
        if (fa != -1){
            all.insert(fa);
            if (findFather(nowId) < findFather(fa)){
                Union(nowId, fa);
            }else{
                Union(fa, nowId);
            }
        }
        if (mom != -1){
            all.insert(mom);
            if (findFather(nowId) < findFather(mom)){
                Union(nowId, mom);
            }else{
                Union(mom, nowId);
            }
        }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            all.insert(child);
            if (findFather(nowId) < findFather(child)){
                Union(nowId, child);
            }else{
                Union(child, nowId);
            }
        }
        cin >> estate >> tempArea;
        p[nowId].id = nowId;
        p[nowId].m = estate;
        p[nowId].area = tempArea;
    }
    for (auto i = all.begin(); i != all.end(); ++i) {         // 找到所有根结点
        if(*i == findFather(*i)){
            count++;
            root.push_back(*i);
        }
    }
    for (auto i = all.begin(); i != all.end(); ++i) {         // 处理整个家族成员的信息
        int nowRoot = findFather(*i);
        f[nowRoot].rootId = nowRoot;
        f[nowRoot].numPep++;
        f[nowRoot].sumArea += p[*i].area;
        f[nowRoot].sumSets += p[*i].m;
        f[nowRoot].averArea = 1.0 * f[nowRoot].sumArea / f[nowRoot].numPep;
        f[nowRoot].averSets = 1.0 * f[nowRoot].sumSets / f[nowRoot].numPep;
    }
    sort(f, f + maxn, cmp);
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        printf("%04d %d %.3f %.3f\n", f[i].rootId, f[i].numPep, f[i].averSets, f[i].averArea);
    }
    return 0;
}