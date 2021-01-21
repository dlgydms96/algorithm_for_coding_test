#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
vector<int> dp;

int main(){
	ifstream ifs("input.txt");
	ifs>>n;
    if(n%2) cout <<"CY";
    else cout <<"SK";
    return 0;
}