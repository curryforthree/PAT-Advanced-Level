#include <iostream>
using namespace std;

int main() {
    int z[40], num = 0;       //存储进制转换后的结果
    int a, q;
    bool flag = true;        // 是否是回文数
    cin >> a >> q;
    do{
        z[num++] = a % q;
        a /= q;
    }while(a != 0);
    for (int i = 0; i < num / 2; ++i) {
        if(z[i] != z[num - i - 1]) {
            flag = false;
            break;
        }
    }
    if(flag == false) printf("No\n");
    else printf("Yes\n");
    for (int i = num - 1; i >= 0; --i) {
        printf("%d", z[i]);
        if(i != 0) printf(" ");
        else printf("\n");
    }
    return 0;
}