#include <iostream>
#include <string>

using namespace std;

int cnt_zero = 0;
int cnt_one = 0;

int fibonacci(int n) {
    if (n == 0) {
        //printf("0");
		cnt_zero++;
        return 0;
    } else if (n == 1) {
        //printf("1");
		cnt_one++;
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void)
{
   int instr_num = 0;
   char instr[6];

   freopen("test.txt", "r", stdin);
   scanf("%d", &instr_num);
   for(int i = 0; i < instr_num; i++)
   {
	   cnt_zero = 0;
	   cnt_one = 0;

	   scanf("%s",&instr);
	   int count = stoi(instr);
	   fibonacci(count);
	   cout<< cnt_zero <<" "<< cnt_one <<endl;
   }
   return 0;
}
