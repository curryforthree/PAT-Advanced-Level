#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int n, tot, nearS = INF;
vector<int> sum;

int main() {
    cin >> n >> tot;
    sum.resize(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; ++i) {        // 枚举左端点     找到最小的面值
        int j = upper_bound(sum.begin() + i, sum.end(), tot + sum[i - 1]) - sum.begin();
        if(sum[j - 1] - sum[i - 1] == tot){
            nearS = tot;
            break;
        }else if(j <= n && sum[j] - sum[i - 1] < nearS) {  //若j == n + 1说明不存在
            nearS = sum[j] - sum[i - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int j = upper_bound(sum.begin() + i, sum.end(), nearS + sum[i - 1]) - sum.begin();
        if(sum[j - 1] - sum[i - 1] == nearS){
            printf("%d-%d\n", i, j - 1);
        }
    }
    return 0;
}