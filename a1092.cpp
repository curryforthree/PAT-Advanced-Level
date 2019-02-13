#include <iostream>
using namespace std;
int HashTable[128];
int main() {
    string a, b;
    int cnt = 0;
    bool flag = false;       // false 表示有多余的，true表示少
    cin >> a >> b;
    for (int i = 0; i < b.size(); ++i)
        HashTable[b[i]]++;
    for (int i = 0; i < a.size(); ++i)
        HashTable[a[i]]--;
    for (int i = 0; i < 127; ++i) {
        if(HashTable[i] > 0){
            flag = true;
            cnt += HashTable[i];
        }
    }
    if(flag) printf("No %d", cnt);
    else printf("Yes %d", a.size() - b.size());
    return 0;
}