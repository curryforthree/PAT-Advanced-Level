#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, n1 , n2, n3 , cnt = 0;
    string a;
    cin >> a;
    n = a.size();
    n2 = (n + 2) / 3 + (n + 2) % 3;
    n1 = n3 = (n + 2 - n2) / 2;
    vector<char> v[n2];
    for (int i = 0; i < n2; ++i)
        v[i].resize(n1);
    for (int i = 0; i < n1; ++i)
        v[0][i] = a[cnt++];
    for (int i = 1; i < n2; ++i)
        v[i][n1 - 1] = a[cnt++];
    for (int i = n1 - 2; i >= 0; --i)
        v[n2 - 1][i] = a[cnt++];
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if(v[j][i] == 0) printf(" ");
            else printf("%c", v[j][i]);
        }
        printf("\n");
    }
    return 0;
}