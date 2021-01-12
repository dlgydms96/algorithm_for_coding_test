#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
vector<int> check;
void bfs(int idx, vector<vector<int>> &com, int n){
    if(check[idx]) return;
    check[idx]=1;
    for(int i=0; i<n; i++)
    	if(com[idx][i]==1) q.push(i);
    while(!q.empty()){
        int next=q.front();
    	q.pop();
        bfs(next,com, n);
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    check=vector<int>(n,0);
    for(int i=0; i<n; i++)
        if(check[i]==0) {
            bfs(i,computers,n);
            answer++;
    	}
    return answer;
}