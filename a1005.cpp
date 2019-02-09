#include <iostream>
using namespace std;
char num[15][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int sum = 0;
    string b, res;
    cin >> b;
    for (int i = 0; i < b.size(); ++i) {
        sum += (b[i] - '0');
    }
    res = to_string(sum);
    for(int i = 0; i < res.size(); i++){
        printf("%s", num[res[i] - '0']);
        if(i != res.size() - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}