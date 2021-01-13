#include <iostream>
#include <vector>
using namespace std;
#define INF 999999

int calc_charge(int n){
	int coin[2]={5,2};
	vector<int> ch(n+1,0);
	ch[1]=INF;
	for(int i=2; i<=n; i++){
		ch[i]=INF;
		for(int k=0; k<2; k++)
			if(i>=coin[k] &&ch[i-coin[k]]+1 < ch[i])
				ch[i]=ch[i-coin[k]]+1;
	}
	if(ch[n]==INF) return -1;
	return ch[n];
}

int main(){
	int n;
	cin >> n;
	cout <<calc_charge(n)<<endl;
}