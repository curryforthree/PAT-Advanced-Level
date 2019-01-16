#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    int c = 0;
    vector<int> a;
    vector<int> b;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int max = -1;
    for (int i = 0; i < n; ++i) {
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] == b[i] && b[i] >= max){
            count++;
        }
    }
    cout << count << endl;
    max = -1;
    if(count == 0){
        printf("\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] == b[i] && b[i] >= max){
            cout << a[i];
            if(++c < count){
                cout << " ";
            }

        }
    }
    return 0;
}