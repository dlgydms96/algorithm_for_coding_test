#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<int> op;
int answer = 0;

bool calc(vector<int> &n, int target){
    int sum=0;
    for(int i=0; i<n.size(); i++){
        if(op[i]) sum+=n[i];
        else sum-=n[i];
    }
    if(sum ==target) return true;
    return false;
}

int dfs(vector<int> &num, int index, int target){
    int cnt=0;
    while(cnt<2){
        if(index< op.size()){   
            op[index]=cnt;
            dfs(num, index+1, target);
        }
        else if(calc(num, target)) {answer++; return 0;}
        cnt++;
    }
    return 0;
}

int solution(vector<int> numbers, int target) {
    op=vector<int>(numbers.size(),0);
    dfs(numbers, 0, target);
    int an=answer;
    return an;
}