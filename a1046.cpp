#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n, query, sum;
    cin >> n;
    vector<int> D(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> D[i];
        D[i] = D[i] + D[i - 1];
    }
    cin >> sum;
    sum += D[n];
    cin >> query;
    for (int i = 0; i < query; ++i) {
        int a, b;
        cin >> a >> b;
        printf("%d\n", abs(D[a] - D[b]) > sum - abs(D[a] - D[b]) ? sum - abs(D[a] - D[b]) : abs(D[a] - D[b]));
    }
    return 0;
}