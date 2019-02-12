#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;
bool HashTable[128] = {false};
set<char> printed;
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.size(); ++i){
        if(islower(b[i])) b[i] = toupper(b[i]);
        HashTable[b[i]] = true;
    }
    for (int i = 0; i < a.size(); ++i) {
        if(islower(a[i])) a[i] = toupper(a[i]);
        if(HashTable[a[i]] == false && printed.find(a[i]) == printed.end()){
            printf("%c", a[i]);
            printed.insert(a[i]);
        }
    }

    return 0;
}