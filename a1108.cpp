#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool judge(string a){
    int pos = -1;
    int tot = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == '-' && i == 0){
            continue;
        }
        if (!((a[i] >= '0' && a[i] <= '9') || a[i] == '.') ){
            return false;
        }
    }
    for (int i = 0; i < a.length(); ++i) {
        if(a[i] == '.'){
            tot++;
            if (tot > 1){
                return false;
            }
            pos = i;
        }
    }
    if(tot == 1 && a.length() - pos - 1 > 2){
        return false;
    }
    if(stod(a) < -1000 || stod(a) > 1000){
        return false;
    }
    return true;

}

int main() {
    int n;                 // 输入个数
    int count = 0;         // 有效数字个数
    double sum = 0.0;     // 有效数字的和
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        if(judge(a) == false){
            cout << "ERROR: " << a << " is not a legal number"<< endl;
        }else{
            count++;
            if (a[0] == '-'){
                string b;
                b = a.substr(1);
                sum -= stod(b);
            }else {
                sum += stod(a);
            }
        }
    }
    if(count == 0){
        cout << "The average of 0 numbers is Undefined" << endl;

    }else if(count == 1){
        printf("The average of 1 number is %.2f", sum);
    }else {
        double ave = sum / (1.0 * count);
        printf("The average of %d numbers is %.2f", count, ave);
    }

    return 0;
}