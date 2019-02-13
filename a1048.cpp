#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int HashTable[maxn] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        HashTable[v[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        if(HashTable[m - v[i]]){
            if(m - v[i] == v[i] && HashTable[v[i]] >= 2){     // 两个硬币一样，其个数必须要大于等于2
                printf("%d %d", v[i], v[i]);
                return 0;
            }
            if(v[i] < m - v[i]){                        // 两个硬币币值不同，小的先输出
                printf("%d %d", v[i], m - v[i]);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}