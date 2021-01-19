#include <iostream>
#include <string>
using namespace std;
int main(){
    int a,sum=0;
    string b;
    cin>>a;
    cin>>b;
    for(int i=0; i<a; i++){
        string n=b.substr(i,1);
        int q=atoi(n.c_str());
		sum+=q;
    }
    cout<<sum;
    return 0;
}