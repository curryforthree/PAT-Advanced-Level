#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    return a > b;
}
int main() {
    int n, n1, n2;
    cin >> n;
    string a = to_string(n);
    while(a.size() < 4){
        a = '0' + a;
    }
    sort(a.begin(), a.end());
    n1 = stoi(a);
    sort(a.begin(), a.end(), cmp);
    n2 = stoi(a);
    int Last = -1;
    while(n2 - n1 && n2 - n1 != Last){
        printf("%04d - %04d = %04d\n", n2, n1, n2 - n1);
        a = to_string(n2 - n1);
        while(a.size() < 4){
            a = '0' + a;
        }
        Last = n2 - n1;
        sort(a.begin(), a.end());
        n1 = stoi(a);
        sort(a.begin(), a.end(), cmp);
        n2 = stoi(a);
    }
    if(n2 - n1 == 0){
        printf("%04d - %04d = 0000\n", n1, n2);
    }
    return 0;
}