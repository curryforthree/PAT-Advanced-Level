#include <iostream>
#include <vector>
using namespace std;
struct node{
    string name, p;
};
int main() {
    int n;
    cin >> n;
    string N, password;
    vector<node> ans;
    for (int i = 0; i < n; ++i) {
        bool flag = false;        //是否被修改
        cin >> N >> password;
        for (int j = 0; j < password.size(); ++j) {
            if(password[j] == '1'){
                password[j] = '@';
                flag = true;
                continue;
            }
            if(password[j] == '0'){
                password[j] = '%';
                flag = true;
                continue;
            }
            if(password[j] == 'l'){
                password[j] = 'L';
                flag = true;
                continue;
            }
            if(password[j] == 'O'){
                password[j] = 'o';
                flag = true;
                continue;
            }
        }
        if(flag == true) ans.push_back(node{N, password});
    }
    if(ans.size() == 0){
        if(n == 1){
            printf("There is 1 account and no account is modified\n");
        }else{
            printf("There are %d accounts and no account is modified\n", n);
        }
    }else{
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%s %s\n", ans[i].name.c_str(), ans[i].p.c_str());
        }
    }
    return 0;
}