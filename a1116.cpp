#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;
set<int> s, printed;
map<int, int> Rank;
bool isPrime(int a){
    if(a <= 1){
        return false;
    }
    int sqr = sqrt(a * 1.0);
    for (int i = 2; i <= sqr; ++i) {
        if (a % i == 0){
            return false;
        }
    }
    return true;
}
int main() {
    int n, k, nowId, query;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nowId;
        s.insert(nowId);
        Rank[nowId] = i;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> query;

        if (s.find(query) == s.end()){
            printf("%04d: Are you kidding?\n", query);
        }else if(printed.find(query) != printed.end()){
            printf("%04d: Checked\n", query);
        }else if(Rank[query] == 1){
            printf("%04d: Mystery Award\n", query);
        }else if(isPrime(Rank[query]) == true){
            printf("%04d: Minion\n", query);
        } else{
            printf("%04d: Chocolate\n", query);
        }
        printed.insert(query);
    }
    return 0;
}