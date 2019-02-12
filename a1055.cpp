#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int age, money;
};
bool cmp(node a, node b){
    if(a.money != b.money) {
        return a.money > b.money;
    } else if(a.age != b.age) {
        return a.age < b.age;
    }else {
        return a.name < b.name;
    }
}
int main() {
    int n, k, m, La, Ha;
    cin >> n >> k;
    vector<node> v(n), age;
    vector<int> book(205);
    for (int i = 0; i < n; ++i){
        cin >> v[i].name;
        scanf("%d %d", &v[i].age, &v[i].money);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if(book[v[i].age] < 100){
            age.push_back(v[i]);
            book[v[i].age]++;
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("Case #%d:\n", i + 1);
        cin >> m >> La >> Ha;
        vector<node> t;
        for (int j = 0; j < age.size(); ++j) {
            if(age[j].age >= La && age[j].age <= Ha)
                t.push_back(age[j]);
        }
        if(t.size() == 0){
            printf("None\n");
            continue;
        }
        m = m > t.size() ? t.size() : m;
        for (int j = 0; j < m; ++j) {
            printf("%s %d %d\n", t[j].name.c_str(), t[j].age, t[j].money);
        }
    }
    return 0;
}