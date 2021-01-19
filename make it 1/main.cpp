#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	ifstream ifs("input.txt");
	int answer=0,k,n;
	ifs>> n;
	vector<int> cnt = vector<int>(n+2,0);
	vector<int> cnd = vector<int>(3,0);

	cnt[1]=0;
	for(int i=2; i<=n; i++){
		cnd = vector<int>(0);
		if(i%3==0)cnd.push_back(cnt[i/3]+1);
		if(i%2==0)cnd.push_back(cnt[i/2]+1);
		cnd.push_back(cnt[i-1]+1);
		cnt[i]=*min_element(cnd.begin(), cnd.end());
	}
	cout << cnt[n]<<endl;
	return 0;
}