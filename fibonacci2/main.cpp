#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs ("input.txt");

	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	ifs >> n;
	vector<long long> fib(n+1,0);
	fib[0]=0;fib[1]=1;
	for(int i=2; i<=n; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<< fib[n];
	return 0;
}