#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map<int, string> mp;
set<string> printed;

int main() {
    int m, n, s;
    scanf("%d%d%d\n", &m, &n, &s);
    if (m < s){
        printf("Keep going...\n");
        return 0;
    }
    int count = 1;
    for (int i = 1; i <= m; ++i) {
        string a;
        getline(cin, a);
        mp[i] = a;
    }
    for (int i = s; i <= m; ++i) {
        if (i == s){
            cout << mp[i] << endl;
            printed.insert(mp[i]);
            continue;
        }
        if(count == n){
            if(printed.find(mp[i]) == printed.end()){
                cout << mp[i] << endl;
                printed.insert(mp[i]);
                count = 1;
            }
            continue;

        }
        count++;
    }
    return 0;
}