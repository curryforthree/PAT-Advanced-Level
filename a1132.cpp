#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        int z = stoi(a);
        int A = stoi(a.substr(0, a.size() / 2));
        int B = stoi(a.substr(a.size() / 2));
        if(A * B == 0){
            printf("No\n");
            continue;
        }
        if (z % (A * B) == 0){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
    }
    return 0;
}