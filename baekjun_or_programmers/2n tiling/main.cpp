#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	ifstream ifs("input.txt");
	int n;
	ifs>> n;
	vector<int> cnt = vector<int>(n+2,0);
	cnt[1]=1;
	cnt[2]=2;
	for(int i=3; i<=n; i++)
		cnt[i]=(cnt[i-1]+cnt[i-2])%10007;
	
	cout << cnt[n]<<endl;
	return 0;
}