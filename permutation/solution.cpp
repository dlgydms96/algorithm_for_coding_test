#include <iostream>
#include <vector>
#include <algorithm>
#include "solution.h"
using namespace std;

/* Put your codes */
int check[7]={0,};
vector<int> res;
int Solution::Permutation(int n, int r)
{
	if(n==r){
		return n;
	}
	else{
		for(int i=0; i<r; i++){
			if(check[i]) continue;
			check[i]=1;
			res.push_back(i);
			Permutation(n+1, r);
			res.pop_back();
			check[i]=0;
		}
	}
	for(auto &r: res)cout << r ;
	cout << endl;
	return n;
}
