#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> bd;
int n;
int head[4]={1,-1,0,0};

int check_rot(vector<pair<int,int>> cd){
    return 1;
}
void dfs(vector<pair<int,int>> cd){
    cout <<cd[0].first;
    for(int i=0; i<4; i++){
		vector<pair<int,int>> new_cd;        
        for(int c=0; c<2; c++){
            int x=cd[c].first + head[i];
            int y=cd[c].second + head[3-i];
            new_cd.push_back({x,y});
        }
        int rx=new_cd[0].first;
        int ry=new_cd[0].second;
        int lx=new_cd[1].first;
        int ly=new_cd[1].second;
        if((rx>=0 && rx<n && ry>=0 && ry<n && bd[rx][ry]==0) &&
        (lx>=0 && lx<n && ly>=0 && ly<n && bd[lx][ly]==0))
            dfs(new_cd);
        else if((!(rx>=0 && rx<n && ry>=0 && ry<n && bd[rx][ry]==0) &&
                (lx>=0 && lx<n && ly>=0 && ly<n && bd[lx][ly]==0)) ||
                ((rx>=0 && rx<n && ry>=0 && ry<n && bd[rx][ry]==0) &&
                !(lx>=0 && lx<n && ly>=0 && ly<n && bd[lx][ly]==0)))
        {
    		int flag = check_rot(new_cd);
            if(flag) dfs(new_cd);
        }       
    }
    
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    bd=board;
    n=bd.size();
   	vector<pair<int,int>> coord={{1,1},{1,2}}; 
    dfs(coord);
    return answer;
}