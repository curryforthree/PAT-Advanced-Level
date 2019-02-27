#include <bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int Fgrade;
	double grade;
	int num;
};
map<string, int> nametoid;
map<int, string> idtoname;
int idx = 1;
int getId(string name){
	if(nametoid[name] == 0){
		nametoid[name] = idx;
		idtoname[idx] = name;
		idx++;
		return idx - 1;
	}else{
		return nametoid[name];
	}
}

bool cmp(node a, node b){
	if(a.Fgrade != b.Fgrade) return a.Fgrade > b.Fgrade;
	else if(a.num != b.num) return a.num < b.num;
	else return a.name < b.name;
}

int main(){
	int n;
	double tmpG;
	string tmpid, tmpname;
	cin >> n;
	vector<node> v(n + 1);
	for(int i = 0; i < n; i++){
		cin >> tmpid >> tmpG >> tmpname;
		for(int j = 0; j < tmpname.size(); j++){
			if(isupper(tmpname[j]))
				tmpname[j] = tolower(tmpname[j]);
		}
		int nowid = getId(tmpname);
		v[nowid].name = tmpname;
		v[nowid].num++;
		if(tmpid[0] == 'A') v[nowid].grade += tmpG;
		else if(tmpid[0] == 'T') v[nowid].grade += tmpG * 1.5;
		else if(tmpid[0] == 'B') v[nowid].grade += tmpG / 1.5;
	}
	for(int i = 1; i < idx; i++){
		v[i].Fgrade = (int) v[i].grade;
	}
	for(int i= 1; i < idx; i++){
	  v[i - 1] = v[i];
	}
	sort(v.begin(), v.begin() + idx - 1, cmp);
	printf("%d\n", idx - 1);
	int r = 1;
	for(int i = 0; i < idx - 1; i++){
		if(i != 0 && v[i].Fgrade != v[i - 1].Fgrade){
			r = i + 1;
			printf("%d ", r);
		}else{
			printf("%d ", r);
		}
		printf("%s %d %d\n", v[i].name.c_str(), v[i].Fgrade, v[i].num);
	}
	return 0;
}