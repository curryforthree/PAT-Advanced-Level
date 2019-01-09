#include <iostream>
#include <algorithm>
using namespace std;

struct pol{
    int exp;
    double co;
};
bool cmp(pol a, pol b){
    return a.exp > b.exp;
}
pol a[20];
//pol b[20];
int main() {
    int num1, num2;
    int e;
    double c;
    cin >> num1;
    for (int i = 0; i < num1; ++i) {
        cin >> a[i].exp >> a[i].co;
    }
    cin >> num2;
    for (int i = 0; i < num2; ++i) {
        cin >> e >> c;
        for (int j = 0; j < 20; ++j) {
            if (a[j].exp > e){
                continue;
            } else if(a[j].exp == e){
                a[j].co += c;
                break;
            } else if(a[j].exp < e){
                a[num1].exp = e;
                a[num1++].co = c;
                break;
            }
        }
    }
    sort(a, a + 20, cmp);
    int count = 0;
    for (int i = 0; i < 20; ++i) {
        if(a[i].co){
            count++;
        }
    }
    printf("%d", count);
    for (int i = 0; i < 20; ++i) {
        if (a[i].co){
            printf(" %d %.1f", a[i].exp, a[i].co);
        }
    }

    return 0;
}