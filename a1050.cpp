#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool HashTable[128] = {false};
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.size(); ++i)
        HashTable[b[i]] = true;
    for (int i = 0; i < a.size(); ++i) {
        if(HashTable[a[i]] == true) continue;
        cout << a[i];
    }

    return 0;
}