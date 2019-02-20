#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

string ge[13] = {
        "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
string shi[13] = {
        "###","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int main(){
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        string a;
        getline(cin, a);
        if(!isalpha(a[0])){
            int earthNum = stoi(a);
            if(earthNum / 13) printf("%s", shi[earthNum / 13].c_str());
            if((earthNum/13) && (earthNum %13)) printf(" ");
            if((earthNum % 13) || earthNum == 0) printf("%s", ge[earthNum % 13].c_str());
        }else{
            if(a.size() <= 4){
                for (int j = 0; j < 13; ++j) {
                    if(a == ge[j]){
                        printf("%d", j);
                        break;
                    }
                    if(a == shi[j]){
                        printf("%d", 13 * j);
                        break;
                    }
                }
            }else{
                string tempShi = a.substr(0, 3);
                string tempGe = a.substr(4);
                int ans = 0;
                for (int j = 0; j < 13; ++j)
                    if (tempShi == shi[j]){
                        ans = 13 * j;
                    }
                for (int j = 0; j < 13; ++j)
                    if (tempGe == ge[j]){
                        ans += j;
                    }
                printf("%d", ans);
            }
        }
        printf("\n");

    }

    return 0;
}


