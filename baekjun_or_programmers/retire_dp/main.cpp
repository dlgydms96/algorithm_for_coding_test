#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
vector<int> t;
vector<int> p;
int sum=0;
int main(){
	ifstream ifs("input.txt");
	ifs>>n;
	t=vector<int>(n+2,0);
	p=vector<int>(n+2,0);
	for(int i=1; i<=n; i++)ifs>>t[i]>>p[i];

	for(int i=n; i>=1; i--){
		if(i+t[i]>n+1)p[i]=p[i+1];
		else{
			p[i]=max(p[i+1],p[i]+p[i+t[i]]);
			sum=max(sum,p[i]);
		}
	}
	cout << sum<<endl;
}