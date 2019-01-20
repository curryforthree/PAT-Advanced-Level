#include <iostream>
#include <vector>
using namespace std;
double a[100001];
int main() {
    int n;
    double sum = 0.0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i] * i * (n - i + 1) ;
    }
    printf("%.2f", sum);


    return 0;
}