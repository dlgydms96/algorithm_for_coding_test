#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "solution.h"
using namespace std;

/* Put your codes */
int Solution::maxHeap()
{
	int n = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0; i<in_list.size(); i++){
		q.push(in_list[i]);
	}
	while(q.size()){
		cout<<q.top()<<endl;
		q.pop();
	}
	return n;
}