#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, t, cnt = 0;
    cin >> n;
    vector<int> pos(n);       // pos[i]记录i的位置
    for(int i = 0; i < n; i++){
        cin >> t;
        pos[t] = i;
    }
    for (int i = 1; i < n; ++i) {      // 0号作为哨兵，从1开始遍历一遍序列，如果pos[i] != i的话说明还没有归位
        if(pos[i] != i){              // i没有回到他应该呆的位置
            while(pos[0] != 0){        //此时就一直把0所在位置应该呆的数 和 0一直的交换下去 直到0归位，这个过程中有可能会使当前的i归位
                swap(pos[0], pos[pos[0]]);         //交换0和该位置上本来应该呆的数字
                cnt++;
            }
            if(pos[i] != i){//如果这个过程没能进行到使i归位，那就把哨兵搬到i这个位置上，那么下一轮哨兵归位的时候就一定会将其归位
                swap(pos[0], pos[i]);
                cnt++;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}