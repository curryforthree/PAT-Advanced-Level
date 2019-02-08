#include <iostream>
using namespace std;
int main() {
    int n, nowG, maxG = -1, minG = 101;     // minG 记录男生， maxG记录女生
    cin >> n;
    string nowName, nowId, ansNmM, ansNmF, ansIdM, ansIdF;
    bool flag = false;        //记录是否有人缺席
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> nowName >> c >> nowId >> nowG;
        if(c == 'M' && nowG < minG){
            minG = nowG;
            ansNmM = nowName;
            ansIdM = nowId;
        }
        if(c == 'F' && nowG > maxG){
            maxG = nowG;
            ansNmF = nowName;
            ansIdF = nowId;
        }
    }
    if(maxG == -1){       // 有女生缺席
        flag = true;
        printf("Absent\n");
    }else{
        printf("%s %s\n", ansNmF.c_str(), ansIdF.c_str());
    }
    if(minG == 101){       // 有男生缺席
        flag = true;
        printf("Absent\n");
    }else{
        printf("%s %s\n", ansNmM.c_str(), ansIdM.c_str());
    }
    if(flag) printf("NA\n");
    else printf("%d\n", maxG - minG);
    return 0;
}