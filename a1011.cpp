#include <iostream>
using namespace std;
char c[4] = { 'W', 'T', 'L'};
int main() {
    double a, Max = -1, tempAns = 1;
    int Index;
    for (int i = 0; i < 3; ++i) {
        Max = -1;
        Index = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> a;
            if( a > Max){
                Max = a;
                Index = j;
            }

        }
        tempAns *= Max;
        printf("%c ", c[Index]);
    }
    printf("%.2f", (tempAns * 0.65 - 1) * 2);


    return 0;
}