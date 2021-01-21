#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs ("input.txt");

	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	ifs >> n;
	int fm=n/5+1;
	int tm;
	int rem;
	while(fm--){
		rem=n-(fm*5);
		if(rem%2==0){ tm=rem/2; break;}
	}
	if(rem%2!=0) cout<<-1;
	else cout << fm+tm<<endl;
	return 0;
}