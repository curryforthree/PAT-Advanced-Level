#include <iostream>
#include <vector>
using namespace std;
char mp[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
int main() {
    int a;
    printf("#");
    for (int i = 0; i < 3; ++i) {
        cin >> a;
        vector<char> temp;
        do{
            temp.push_back(mp[a % 13]);
            a /= 13;
        }while(a != 0);
        while(temp.size() < 2) {       // 不足两位的 补0补成两位
            temp.push_back('0');
        }
        printf("%c%c", temp[1], temp[0]);
    }
    return 0;
}