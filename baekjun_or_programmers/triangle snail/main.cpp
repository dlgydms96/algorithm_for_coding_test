#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n, vector<int>(n,0));
    int max = (n*n+n)/2;
    int num =1;
    int i=0,j;
    
    while(num<=max){
        for(j=i*2; j<n-i; j++){
            snail[j][i] = num;
            num++;
        }
        for(j=i+1; j<n-i*2; j++){
            snail[n-i-1][j] = num;
            num++;
        }
        int k=n-i*2;
        for(int l=n-i-2; l>=i*2+1; l--){
            snail[l][k-2]=num;
            num++;
            k--;
        }
        i++;
    }
    for(auto &sna:snail) for(auto &s:sna) if(s!=0)answer.push_back(s);
    return answer;
}

int main(){
    vector<int> ans;
    ans=solution(4);
    for(auto &a: ans)cout << a<<endl;
    return 0;
}