#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

/* Put your codes */
int Solution::Fibonacci(int n)
{
	if(n<=2) return 1;
	if(memo[n]!=0) return memo[n];
	else
	{
		memo[n]=Fibonacci(n-1)+Fibonacci(n-2);
		return memo[n];
	}	
}
/* Put your codes */
/*
int Solution::Fibonacci(int n)
{
	if(n<=2) return 1;
	if(memo[n]!=0) return memo[n];
	else{
		memo[n] = Fibonacci(n-1) + Fibonacci(n-2);
		return memo[n];
	}
}
*/