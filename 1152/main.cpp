#include <stdio.h> 

int cnt = 0;
int word_cnt = 0;
char arr[1000000];
int main(void)
{
	//freopen("test.txt", "r", stdin);
	while(1){
		scanf("%c",&arr[cnt]);
		if(arr[cnt] == 0) break;
		cnt++;
	}
	//printf("cnt = %d\n",cnt);
	int flag = 0;
	for(int i = 0 ; i < cnt ; i++){
		if(arr[i] == ' '){ 
			if(flag == 0) { 
				word_cnt++; flag = 1;
			}
		}else flag = 0;
	}
	if(arr[0] == ' ' && cnt == 1) word_cnt--;  
	else if(arr[0] != ' ' && arr[cnt - 1] != ' '){
		if(arr[cnt - 1] != '\n')
			word_cnt++;
	}
	else if(arr[0] == ' ' && arr[cnt - 1] == ' ') word_cnt--;

	if(arr[0] == 0) word_cnt = 0;
	//if(arr[cnt - 1] == '\n') word_cnt--;
	//printf("%d\n",arr[cnt - 1]);
	printf("%d",word_cnt);
	/*
   int i,cnt=1;
   int check=0;
   char arr[1000001]={0,};
   freopen("test.txt", "r", stdin);
   
   scanf("%c",&arr[0]);
   if(arr[0]== ' ')
   {
	   i=0;
	   while(1)
	   {
		   scanf("%c",&arr[cnt]);
		   if(arr[cnt] == ' ') i++;
		   if(arr[cnt] == 0) break;
		   cnt++;
	   }
   }
  printf("%d",i);
   return 0;
   */
}