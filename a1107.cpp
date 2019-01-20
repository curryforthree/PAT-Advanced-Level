#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1005;

int isroot[maxn] = {0};
int choose[maxn];
int father[maxn];

void init(int n){
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFa(int a){
    while (a != father[a]){
        a = father[a];
    }
    return a;
}
void Union(int a, int b){
    int FaA = findFa(a);
    int FaB = findFa(b);
    if (FaA != FaB){
        father[FaB] = FaA;
    }
}

bool cmp(int a, int b){
    return a > b;
}
int main() {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; ++i) {
        int k, h;
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j) {
            cin >> h;
            if(choose[h] == 0){
                choose[h] = i;
            }
            Union(i, choose[h]);
        }
    }
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        isroot[findFa(i)]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (isroot[i] != 0){
            total++;
        }
    }
    sort(isroot + 1, isroot + n + 1, cmp);
    printf("%d\n", total);
    for (int i = 1; i <= total; ++i) {
        printf("%d", isroot[i]);
        if (i != total){
            printf(" ");
        }
    }
    return 0;
}