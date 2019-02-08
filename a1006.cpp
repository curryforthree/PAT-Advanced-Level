#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct node{
    char name[20];
    int inTime, outTime;
};


int main() {
    int n, inH, inM, inS, outH, outM, outS;
    cin >> n;
    vector<node> v(n);
    int minTime = INF, maxTime = -1, minIndex, maxIndex;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d %d:%d:%d\n", v[i].name, &inH, &inM, &inS, &outH, &outM, &outS);
        v[i].inTime = 3600 * inH + 60 * inM + inS;
        v[i].outTime = 3600 * outH + 60 * outM + outS;
        if(v[i].inTime < minTime){
            minIndex = i;
            minTime = v[i].inTime;
        }
        if(v[i].outTime > maxTime){
            maxIndex = i;
            maxTime = v[i].outTime;
        }
    }
    cout << v[minIndex].name << " " << v[maxIndex].name << endl;
    return 0;
}