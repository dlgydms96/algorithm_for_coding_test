#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> in_list;
    Solution(vector<int> list){
        in_list = list;
    }
    int maxHeap();
	int result;
};