#include <stdio.h>

char vps[50]={0.};
int arr[50]={0,};

void push(int idx){
	arr[idx]=1;
   }

void pop(int idx){
	arr[idx]=0;
   }

int main(void)
{
   int n,cnt=0;
   char parent;
   int i=0,j=0,k=0;
   int sp=0;

   freopen("test.txt", "r", stdin);
   scanf("%d", &n);
   while (i != n)
   {
		scanf("%s",&vps);
		while(vps[k]!=0) 
		{
			if(vps[k]=='(')
			  push(j++);
			else if(vps[k]==')')
			  pop(--j);
			sp=j;
			if(sp<0) break;
			k++;
	   }
	i++;
	j=0;
	k=0;
	if(sp ==0)
	   printf("YES\n");
	else
		printf("NO\n");
   }
}