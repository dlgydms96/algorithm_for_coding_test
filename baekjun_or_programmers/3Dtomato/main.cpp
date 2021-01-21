#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
vector<vector<vector<int>>> boxes;
int nx,ny,nb;
int head[4] = {1,-1,0,0};
queue<pair<int,pair<int, int>>> q;
int cnt = 0;

int bfs(int b, int x, int y){
	for(int i=0; i<4; i++){
		int ax=head[i]+x;
		int ay=head[3-i]+y;
		if(ax>=0 && ay>=0 && ax<nx && ay<ny && boxes[b][ax][ay]==0){
			q.push({b,{ax,ay}});
			boxes[b][ax][ay]=boxes[b][x][y]+1;
			cnt=max(boxes[b][ax][ay],cnt);
		}
	}
	for(int i=0; i<2; i++){
		int ab=head[i]+b;
		if(ab >=0 && ab<nb&& boxes[ab][x][y]==0){
			q.push({ab,{x,y}});
			boxes[ab][x][y]=boxes[b][x][y]+1;
			cnt=max(boxes[ab][x][y],cnt);
		}
	}
	return cnt;
}

int max_day=0;
int main(){
	ifstream ifs("input.txt");
	bool flag_one=false;
	bool flag_zero=false;
	int day=0;
	ifs>> ny>>nx>>nb;
	boxes=vector<vector<vector<int>>>(nb,vector<vector<int>>(nx));
	for(int b=0; b<nb; b++){
		for(int i=0; i<nx; i++){
			for(int j=0; j<ny; j++){
				int k=0;
				ifs >> k;
				boxes[b][i].push_back(k);
				if(k==1){
					q.push({b,{i,j}});
					flag_one=true;}
				if(k==0) flag_zero=true;
				
			}
		}
	}
	//cout << flag_one<<flag_zero<<endl;
	
	if(!flag_zero){cout << 0 <<endl; return 0;}
	else if(!flag_one){cout << -1 << endl; return 0;}
	else{
		while(!q.empty()){
			int bb =q.front().first;
			int bx =q.front().second.first;
			int by =q.front().second.second;
			q.pop();
			day=bfs(bb, bx, by);
			max_day=max(max_day, day);
		}
	}
	for(auto &box:boxes){for(auto &line:box){for(auto &tom:line) cout<<tom<<" "; cout << endl;} cout<<endl;}
	
	for(int b=0; b<nb; b++)
		for(int i=0; i<nx; i++)
			for(int j=0; j<ny; j++)
				if(boxes[b][i][j]==0){
					cout <<-1<<endl;
					return 0;
				}
	
	cout << cnt-1<<endl;
	
	return 0;
}