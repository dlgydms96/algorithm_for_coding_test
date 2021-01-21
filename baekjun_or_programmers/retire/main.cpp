#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n;
vector<pair<int,int>> list;
vector<int> check;
int sum=0,pay=0;

int consult(int day, int p){
	if(day>=n) return p;
	for(int i=day; i<n; i++){
		if(check[i]) continue;
		if(i+list[i].first>n) continue;
		auto curr=list[i];

		check[i]=1;
    	day=i+curr.first;
		pay+=curr.second;
		sum=max(sum,consult(day, pay));
		check[i]=0;
		pay-=curr.second;
	}
	return p;
}

int main(){
	ifstream ifs("input.txt");
	int answer=0,t,p;
	ifs>> n;
	check=vector<int>(n,0);
	int s=n;
	while(s--) {
		ifs>>t>>p;
		list.push_back({t,p});
	}
	consult(0,0);
	cout <<sum<<endl;
	return 0;
}