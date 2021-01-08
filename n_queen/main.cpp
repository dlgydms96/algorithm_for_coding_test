#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;
int n,cnt=0;
vector<int> col;

bool check(int k){
	for(int i=0; i<k; i++)
		if(col[k]==col[i] || abs(col[k]-col[i]) == (k-i)) return false;
	return true;
}
void nqueen(int k){
	if(k==n){
		for(auto &c: col) cout <<c<<" "; cout<<endl;
		cnt++;
		return;
	}
	for(int i=0; i<n; i++){
		col[k]=i;
		if(check(k)) nqueen(k+1);
	}
}
int main(){
	ifstream ifs("input.txt");
	int answer=0;
	ifs>> n;
	col=vector<int>(n);
	nqueen(0);
	cout << cnt << endl;
	return 0;
}