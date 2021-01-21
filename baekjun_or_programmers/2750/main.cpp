#include <stdio.h>

int main(void)
{
	int num[1001]={0, };
	int n,i,j,idx,min=0;

   freopen("test.txt", "r", stdin);

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	num[n]=1001;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(j==i+1)
				{
					min=num[j];
					idx=j;
			}
			if(num[j]<min)
				{
					min=num[j];
					idx=j;
			}
		}
		if(num[i]>min)
		{
			num[idx]=num[i];
			num[i]=min;
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%d\n",num[i]);
	}
   return 0;
}