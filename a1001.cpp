#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int res[10];


int main(){
    int a, b;
    cin >> a >> b;
    int sum, count = 0;
    sum = a + b;
    if(sum < 0){
        printf("-");
        sum = -sum;
    }
    if(!sum){
        printf("0");
        return 0;
    }
    while(sum){
        res[count++] = sum % 10;
        sum /= 10;
    }
    for (int i = 0; i < count; ++i) {
        if((count - i) % 3 == 0 && count > 3 && i != 0){
            printf(",");
        }
        printf("%d", res[count - i - 1]);
    }
    return 0;
}