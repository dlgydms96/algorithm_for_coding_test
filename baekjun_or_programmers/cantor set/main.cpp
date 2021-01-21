#include <iostream>
#include <vector>
using namespace std;
int n=0;
int max_n=0;
vector<string> c;
vector<int> input;
int main(){
	while(1){
		cin>>n;
		if(cin.eof())break;
		input.push_back(n);
		if(max_n<n) max_n=n;
	}
	c=vector<string>(max_n+1,"");
	c[0]="-";
	for(int i=1; i<=max_n; i++){
		c[i]+=c[i-1];
		int len=c[i-1].length();
		while(len--) c[i]+=" ";
		c[i]+=c[i-1];
	}
	for(int i=0; i<input.size(); i++){
		cout << c[input[i]]<<endl;
	}
	return 0;
}