#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "solution.h"
using namespace std;

int main(void)
{
    int n = 10;
    int result;
    Solution s;
    
    result= s.Fibonacci(n);
    cout << result << endl;

    return 0;
}