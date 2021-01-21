#include <stdio.h>

int main(void)
{
   int n,cnt=0;
   char vps[50]={0.};
   freopen("test.txt", "r", stdin);
   scanf("%d", &n);

   for(int i=0;i<n;i++)
   {
	   scanf("%s",&vps);
	   for(int j =0;j<50;j++)
	   {
		   if(vps[j]=='(')
			   cnt++;
		   else if(vps[j]==')')
			   cnt--;
		   else break;
		   if(cnt<0) break;
	   }
	   if(cnt ==0)
		   printf("YES\n");
	   else
		   printf("NO\n");
	   cnt=0;
   }
}