#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int check[100];
map<int, int> m;
int combination(int cnt, int n, int r, vector<int> num){
    if(n==r){
        int sum=0;
        int c=0;
        for(int i=0; i<num.size(); i++){
            if(check[i]){
                sum+=num[i];
                c++;
            }
        }
        if(c==r)m[sum]=0;
    }
    else{
        for(int i=cnt; i<num.size(); i++){
            //if(check[i])continue;
            check[i]=1;
            combination(cnt+1, n+1, r, num);
            check[i]=0;
        }
    }
    return 0;
}

int main(void)
{
    vector<int> answer;
    vector<int> numbers={2,1,3,4,1};
    combination(0,0,2,numbers);
    //for(auto &a:m) cout<<a.first<<endl;
    for(auto &a:m) answer.push_back(a.first);
    for(auto &a:answer) cout << a << endl;
    return 0;
}