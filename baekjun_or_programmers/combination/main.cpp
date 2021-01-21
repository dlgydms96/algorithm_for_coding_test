#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "solution.h"
using namespace std;

int main(void)
{
    vector<int> list={1,2,3,4};
    int i = 0;
    int n = 0;
    int r = 3;
    vector<vector<int>> result;
    Solution s = Solution(list);
    
    result= s.Combination(i, n, r);

    for(auto &p: s.result)
    {
        for(auto &v:p)
        cout << v<< " ";
        cout << endl;
    }

    return 0;
}