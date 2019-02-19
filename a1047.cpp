#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a < b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> v[k + 1];
    for (int i = 0; i < n; ++i) {
        string a;
        int num, tempCourse;
        cin >> a >> num;
        for (int j = 0; j < num; ++j) {
            scanf("%d", &tempCourse);
            v[tempCourse].push_back(a);
        }
    }
    for(int i = 1; i <= k; i++){
        sort(v[i].begin(), v[i].end(), cmp);
        printf("%d %d\n", i, v[i].size());
        for (int j = 0; j < v[i].size(); ++j) {
            printf("%s\n", v[i][j].c_str());
        }
    }
    return 0;
}