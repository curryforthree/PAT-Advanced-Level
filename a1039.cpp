#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 5;

int getId(char name[]){
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id * 26 + name[i] - 'A';
    }
    id = id * 10 + name[3] - '0';
    return id;
}

int main() {
    int n, k, idx = 0;
    cin >> n >> k;
    vector<int> v[maxn];
    for (int i = 0; i < k; ++i) {
        int courseId, stNum;
        char tempName[5];
        cin >> courseId >> stNum;
        for (int j = 0; j < stNum; ++j) {
            cin >> tempName;
            v[getId(tempName)].push_back(courseId);
        }
    }
    char queryName[5];
    for (int i = 0; i < n; ++i) {
        cin >> queryName;
        if(v[getId(queryName)].size() != 0){          // 存在该学生
            printf("%s %d", queryName, v[getId(queryName)].size());
            sort(v[getId(queryName)].begin(), v[getId(queryName)].end());
            for (int j = 0; j < v[getId(queryName)].size(); ++j) {
                printf(" %d", v[getId(queryName)][j]);
            }
            printf("\n");
        }else{
            printf("%s 0\n", queryName);
        }
    }
    return 0;
}