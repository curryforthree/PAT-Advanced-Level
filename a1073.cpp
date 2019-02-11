#include <iostream>
using namespace std;
int main() {
    string a;
    getline(cin, a);
    int posE = 0;      // posE记录E的位置，E之前是底数部分，之后是指数部分
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == 'E') posE = i;
    }
    if(a[0] == '-') printf("-");
    if(a[posE + 1] == '-'){          // 指数部分为负
        string ex = a.substr(posE + 2);
        int e = stoi(ex);
        printf("0.");
        for (int i = 0; i < e - 1; ++i)
            printf("0");
        for (int i = 1; i < posE; ++i) {
            if(a[i] != '.') printf("%c", a[i]);
        }
    }else{
        string ex = a.substr(posE + 2);
        int e = stoi(ex); // 记录指数的大小
        int fraLen = posE - 3;      //记录底数的小数部分长度
        if(e > fraLen){       // 需要补0
            int num0 = e - fraLen;
            for (int i = 1; i < posE; ++i) {
                if(a[i] != '.') printf("%c", a[i]);
            }
            for (int i = 0; i < num0; ++i)
                printf("0");
        }else {          // 只需移动小数点
            printf("%c", a[1]);
            for (int i = 3; i < posE; ++i) {
                printf("%c", a[i]);
                if(i - 2 == e && i != posE - 1) printf(".");
            }
        }
    }
    return 0;
}