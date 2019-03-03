#include <bits/stdc++.h>
using namespace std;
struct node{
	string card;
	int grade;
	int site;
	int Time;
};

struct node2{
	int id;
	int cnt;
};
map<string, vector<node> > T1;
map<int, vector<node> > T2, T3;
bool cmp(node a, node b){
	if(a.grade != b.grade) return a.grade > b.grade;
	else return a.card < b.card;
}
bool cmp1(node2 a, node2 b){
	if(a.cnt != b.cnt) return a.cnt > b.cnt;
	else return a.id < b.id;
}



int main(){
	int n, m;
	cin >> n >> m;
	getchar();
	string tmpCard;
    int grade;
	for(int i = 0; i < n; i++){
		node tmp;
		cin >> tmpCard >> grade;
		getchar();
		tmp.card = tmpCard;
		tmp.grade = grade;
		tmp.site = stoi(tmpCard.substr(1, 3));
		tmp.Time = stoi(tmpCard.substr(4, 6));
		if(tmpCard[0] == 'T'){
			T1["T"].push_back(tmp);
		}else if(tmpCard[0] == 'A'){
			T1["A"].push_back(tmp);
		}else if(tmpCard[0] == 'B'){
			T1["B"].push_back(tmp);
		}
		T2[tmp.site].push_back(tmp);
		T3[tmp.Time].push_back(tmp);
	}
	int ty;
	for(int i = 1; i <= m; i++){
		scanf("%d ", &ty);
		if(ty == 1){
			string query;
			cin >> query;
			printf("Case %d: 1 %s\n", i, query.c_str());
			if(T1[query].size() == 0){
				printf("NA\n");
			}else{
				sort(T1[query].begin(), T1[query].end(), cmp);
				for(int j = 0; j < T1[query].size(); j++){
					printf("%s %d\n", T1[query][j].card.c_str(), T1[query][j].grade);
				}
			}
		}else if(ty == 2){
			string q;
			cin >> q;
			int query = stoi(q);
			printf("Case %d: 2 %s\n", i, q.c_str());
			if(T2[query].size() == 0){
				printf("NA\n");
			}else{
				int sum = 0;
				for(int j = 0; j < T2[query].size(); j++)
					sum += T2[query][j].grade;
				printf("%d %d\n", T2[query].size(), sum);
			}
		}else if(ty == 3){
			string q;
			cin >> q;
			int query = stoi(q);
			printf("Case %d: 3 %s\n", i, q.c_str());
			if(T3[query].size() == 0){
				printf("NA\n");
			}else{
				int idx1 = 1;
				map<int, int> mp;
				vector<node2> v(T3[query].size() + 1);
				for(int j = 0; j < T3[query].size(); j++){
					if(mp[T3[query][j].site] == 0){
						mp[T3[query][j].site] = idx1++;
						v[idx1 - 1].id = T3[query][j].site;
						v[idx1 - 1].cnt = 1;
					}else{
						v[mp[T3[query][j].site]].cnt++;
					}
				}
				sort(v.begin() + 1, v.begin() + idx1 + 1, cmp1);
				for(int j = 1; j < idx1; j++){
					printf("%d %d\n", v[j].id, v[j].cnt);
				}
					
			}
		}
	}
	return 0;
}
