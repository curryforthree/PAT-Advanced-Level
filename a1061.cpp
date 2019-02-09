#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char day[10][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int len = a.size() < b.size() ? a.size() : b.size();
    int Time = 1;
    for(int i = 0; i < len; i++){
        if(a[i] == b[i]){
            if( a[i] >= 'A' && a[i] <= 'G'){
                if(Time == 1){
                    printf("%s ", day[a[i] - 'A']);
                    Time++;
                    continue;
                }
            }
            if((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9')){
                if(Time == 2){
                    if(isalpha(a[i])){
                        printf("%02d:", a[i] - 'A' + 10);
                    } else{
                        printf("%02d:", a[i] - '0');
                    }
                    Time++;
                }
            }
        }
    }
    len = c.size() < d.size() ? c.size() : d.size();
    for (int i = 0; i < len; ++i) {
        if(c[i] == d[i] && isalpha(c[i])){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}