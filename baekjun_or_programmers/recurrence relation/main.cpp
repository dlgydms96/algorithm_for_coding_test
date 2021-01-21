#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
vector<long long> dp;

int main(){
	ifstream ifs("input.txt");
	ifs>>n;
	dp=vector<long long>(n+1,0);
	dp[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i-1; j++){
			dp[i]+=(dp[j]*dp[i-1-j]);
		}
	}
	cout << dp[n]<<endl;
}