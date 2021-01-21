#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> in_list;
    Solution(vector<int> list)
    {
        in_list = list;
    }
    vector<vector<int>> Combination(int cnt, int n, int r);
    bool check[100]={false,};
	vector<int> comb;
	vector<vector<int>> result;
};