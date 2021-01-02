#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "solution.h"
using namespace std;

int main(void)
{
    vector<int> list={1,2,3};
    int result;
    Solution s=Solution(list);
    
    result= s.Permutation(0, 4);
    cout << result << endl;

    return 0;
}