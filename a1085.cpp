#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int maxNum = 1;
    for (int i = 0; i < v.size(); ++i) {
//        int j = upper_bound(v.begin() + i, v.end(), p * v[i]) - v.begin();
//        maxNum = max(maxNum, )

        int left = i + 1, right = v.size() - 1;
        while(left < right){
            int mid = (right + left) / 2;
            if(v[mid] > (long long)v[i] * p){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        if(left - i> maxNum){
            maxNum = left - i;
        }
    }
    printf("%d", maxNum);


    return 0;
}