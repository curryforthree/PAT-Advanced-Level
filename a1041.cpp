#include <iostream>
#include <vector>
using namespace std;
int HashTable[10010] = {0};
int main() {
    int n;
    bool flag = false;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        HashTable[v[i]]++;
    }
    for (int i = 0; i <= n; ++i) {
        if(HashTable[v[i]] == 1){
            printf("%d", v[i]);
            flag = true;
            break;
        }
    }
    if(flag == false) printf("None\n");
    return 0;
}