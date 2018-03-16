#include <stdio.h>

int main(void)
{
   int k,temp,n;
   int num[1000]={0,};

   freopen("test.txt", "r", stdin);

   scanf("%d",&n);
   for(int i=0;i<n;i++)
	   scanf("%d",&num[i]);
   for(int j=n;j>0;j--)
	   for(int i=0;i<j-1;i++)
	   {
		   k=i+1;
		   if(num[i]>num[k])
		   {
			   temp=num[k];
			   num[k]=num[i];
			   num[i]=temp;
		   }
	   }
   for(int i=0;i<n;i++)
	   printf("%d\n",num[i]);
   return 0;
}