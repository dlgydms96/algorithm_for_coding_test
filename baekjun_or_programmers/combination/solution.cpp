#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

/* Put your codes */
vector<vector<int>> Solution::Combination(int cnt, int n, int r)
//cnt=start index of loop, n=cnt of recursion, r=item cnt
{
	if(n==r)
	{
		for(int i=0; i<in_list.size(); i++)
			if(check[i]) comb.push_back(in_list[i]);
		result.push_back(comb);
		comb.clear();
	}
	else{
		for(int i=cnt; i<in_list.size(); i++)
		{
			check[i] = true;
			Combination(i+1, n+1, r);
			check[i] = false;
		}
	}
	return result;
}
/*
vector<vector<int>> Solution::Combination(int cnt, int n, int r)
{
	if(n==r)
	{
		for (size_t i = 0; i < in_list.size(); i++)
			if(check[i]) comb.push_back(in_list[i]);
		result.push_back(comb);
		comb.clear();
	}
	else{
		for (size_t i = cnt; i < in_list.size(); i++)
		{
			check[i] = true;
			Combination(i+1, n+1, r);
			check[i] = false;
		}
	}	
	return result;
}
*/