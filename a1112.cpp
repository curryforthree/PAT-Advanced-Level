#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<char , int> m;            // 用来确定哪些是坏键
unordered_map<char, bool> Hash;         // 标记哪些是坏键
bool isAny = false;          // 是否有坏键
int main() {
    int k;
    scanf("%d\n", &k);
    string a;
    getline(cin, a);
    set<char> printed;
    for (int i = 0; i < a.length(); ++i) {
        m[a[i]] = k;                        // 初值均设为 k，   之后若有连续的m个键出现 且m < k, 则说明不是坏键
    }
    for (int i = 0; i < a.length(); ++i) {        // 循环用来记录连续有几个相同的键出现
        int count = 1;
        char now = a[i];
        char next = a[i + 1];
        while(now == next){
            i++;
            count++;
            next = a[i + 1];
        }
        if (count > k && count % k == 0 && m[now] >= k){
            m[now] = k;
        } else if(count > k && count % k != 0){
            m[now] = count % k;
        } else if(count < m[now]){
            m[now] = count;
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == k){
            Hash[it->first] = true;                // true为坏键 ， false不是坏键
            isAny = true;
        }else {
            Hash[it->first] = false;
        }
    }
    for (int i = 0; i < a.length(); ++i) {
        if (Hash[a[i]] == true && printed.find(a[i]) == printed.end()){
            printf("%c", a[i]);
            printed.insert(a[i]);
        }
    }
    if (isAny){
        printf("\n");       // 如果有坏键才要换行
    }
    for (int i = 0; i < a.length(); ++i) {
        if (Hash[a[i]] == true){
            printf("%c", a[i]);
            i += k - 1;
        }else{
            printf("%c", a[i]);
        }
    }
    return 0;
}