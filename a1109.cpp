#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10005;
struct p{
    string name;
    int h;
};

int res[maxn][maxn];

bool cmp(p a, p b){
    if (a.h != b.h){
        return a.h > b.h;
    }else{
        return a.name < b.name;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int numRow = n / k;
    vector<p> a;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].h;
    }
    sort(a.begin() + 1, a.end(), cmp);
    int lastRow = n - (k - 1) * numRow;   // 最后一列人数
    for (int i = 0; i < k; ++i) {
        if (i == 0 && lastRow != numRow){
            numRow = lastRow;
        } else{
            numRow = n / k;
        }
        int sign = 1;             //符号
        int del = 0;               // 增量
        int numPep;                // 本队之前的人数
        if (i == 0){
            numPep = 0;
        } else{
            numPep = lastRow + numRow * (i - 1);
        }
        for (int j = 1; j <=  numRow; ++j) {
            int now = numRow / 2 + 1 + del * sign;
            res[i][now - 1] = numPep + j;
            if (j % 2 != 0){
                del++;
            }
            sign = -sign;
        }
    }
    for (int i = 0; i < k; ++i) {
        int nowN = numRow;
        if (i == 0){
            nowN = lastRow;
        }
        for (int j = 0; j < nowN; ++j) {
            cout << a[res[i][j]].name;
            if (j != nowN - 1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
    return 0;
}