#include <iostream>
#include <algorithm>
using namespace std;
bool judge(string a){
    string  b;
    b = a;
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
//      加法版本1， 太繁！
//string Add(string a, string b){
//    string a1, a2;
//    string a3 = a;
//    int carry = 0, Len;
//    a1 = a;
//    a2 = b;
//    reverse(a1.begin(), a1.end());
//    reverse(a2.begin(), a2.end());
//    Len = a1.size() > a2.size() ? a1.size() : a2.size();
//    for (int i = 0; i < Len; ++i) {
//        if (a1[i] - '0' + a2[i] - '0' + carry < 10){
//            a3[i] = a1[i] - '0' + a2[i] - '0' + carry + '0';
//            carry = 0;
//        }else{
//            a3[i] = a1[i] - '0' + a2[i] - '0' + carry  - 10 + '0';
//            carry = 1;
//        }
//    }
//    if(carry == 1){
//        a3 = a3 + "1";
//    }
//    reverse(a3.begin(), a3.end());
//    return a3;
//}

string add(string s1, string s2) {
    string s = s1;
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if(carry == 1){
        s = "1" + s;
    }
    return s;
}
int main() {
    string a, b, c;
    int cnt = 0;
    cin >> a;
    while(judge(a) == false){
        if(cnt == 10){
            break;
        }
        b = a;
        reverse(b.begin(), b.end());
        c = add(a, b);
        cout << a << " + " << b << " = "<< c << endl;
        cnt++;
        a = c;
    }
    if (cnt == 10){
        cout << "Not found in 10 iterations.\n";
    }else{
        cout << a << " is a palindromic number.\n";
    }
    return 0;
}