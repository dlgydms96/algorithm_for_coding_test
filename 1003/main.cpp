#include <stdio.h>
#include <string.h>

int q_front=-1;
int q_rear=-1;

int empty_q()
{
		   return (q_front==q_rear);
}

int full_q()
{
	return (q_front & 10000 == (q_rear+1)%10000);
}

int main(void)
{
	int empty;
   int instr_cnt =0, instr_num=0;
   int num;
   int arr[10000]={0,};
   int _true=0;
   char instr[6];
   freopen("test.txt", "r", stdin);
   scanf("%d", &instr_num);
   while(instr_num!=instr_cnt)
   {
	   scanf("%s",&instr);
	   //printf("%s : ",instr);
	   
	   if(!strcmp(instr,"push"))
	   {
		   q_rear++;
		   if(q_rear == 10000) q_rear = 0;
		   scanf("%d\n",&num);
			arr[q_rear]=num;
	   }
	   if(!strcmp(instr,"pop"))
	   {
		   if(empty_q()) printf("%d\n",-empty_q());
		   else 
			   {
				   q_front++;
					if(q_front == 10000) q_front = 0;
				   printf("%d\n",arr[q_front]);
		   }
	   }
	   if(!strcmp(instr,"size"))
	   {
		   printf("%d\n",q_rear-q_front);
	   }
	   if(!strcmp(instr,"empty"))
	   {
		   empty=empty_q();
		  printf("%d\n",empty);
	   }
	   if(!strcmp(instr,"back"))
	   {
		   if(empty_q()) printf("%d\n",-empty_q());
		   else  printf("%d\n",arr[q_rear]);
	   }
	   if(!strcmp(instr,"front"))
	   {
		   if(empty_q()) printf("%d\n",-empty_q());
		   else  {
			   if(q_front+1 == 10000) printf("%d\n",arr[0]);
			   else printf("%d\n",arr[q_front+1]);
		   }
		   
	   }
	   instr_cnt++;
   }
   return 0;
}
