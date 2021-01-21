#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> trip;
vector<int> check;

bool dfs(vector<vector<string>> tickets, int idx){
    if(idx==tickets.size()) return true;
    for(int i=0; i<tickets.size(); i++){
        if(check[i])continue;
        string s=tickets[i][0];
        string e=tickets[i][1];
        if(strcmp(s.c_str(), trip[idx].c_str())==0){
            trip[idx+1]=e;
    		//cout <<" ";for(auto &t: trip) cout << t<<" ";cout<<endl;
            check[i]=1;
            if(dfs(tickets, idx+1)) return true;
            check[i]=0;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    trip=vector<string>(tickets.size()+1);
    check=vector<int>(tickets.size(),0);
    sort(tickets.begin(), tickets.end());
    trip[0]="ICN";
    dfs(tickets,0);
    answer=trip;
    return answer;
}