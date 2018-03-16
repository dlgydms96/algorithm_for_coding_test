#include <stdio.h>

int main(void)
{ 
	int cnt=0;
	int a,b,c;
	int arr1[2];
	int arr2[2];

  // freopen("test.txt", "r", stdin);
   scanf("%d", &a);
   c=a;

   while(1)
   {
	   arr1[0]=a/10;
	   arr1[1]=a%10;
	   b=arr1[0]+arr1[1];

	   arr2[0]=b/10;
	   arr2[1]=b%10;
		a=arr1[1]*10+arr2[1];
		cnt++;
		if(a==c) break;
   }
   printf("%d",cnt);

   return 0;
}