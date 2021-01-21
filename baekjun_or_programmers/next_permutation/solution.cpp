#include <iostream>
#include <vector>
#include <algorithm>
#include "solution.h"
using namespace std;

/* Put your codes */
int Solution::Permutation()
{
	int cnt = 0;
	do{
		cnt++;
		for(auto &l: in_list) cout <<l;
		cout <<endl;
	} while(next_permutation(in_list.begin(), in_list.end()));
	return cnt;
}
