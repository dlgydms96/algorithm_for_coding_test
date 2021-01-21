#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
vector<int> visited;

bool check(string b, string t){
    int cnt=0;
    for(int i=0; i<b.length(); i++){
        if(b[i]!=t[i]) cnt++;
    }
    if(cnt==1) return true;
    return false;
}

int cnt=1;
bool bfs(string begin, string target, vector<string> &words) {
    cout << begin<<endl;
    for(int i=0; i<words.size(); i++){
        if(check(begin, words[i]) && visited[i]==0){
    		cout << " "<<words[i]<<endl;
    		if(strcmp(words[i].c_str(), target.c_str())==0) return true;
            q.push(i);
        }
    }	
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        if(visited[i]) continue;
        visited[i]=1;
    	cnt++;
        if(bfs(words[i], target, words)) return true;
        else cnt--;
    }
 
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    visited=vector<int>(words.size());
    if(find(words.begin(), words.end(), target)==words.end()) return 0;
    else {
        bfs(begin, target, words);
   }
    cout << cnt<<endl;
    answer=cnt;
    return answer;
}