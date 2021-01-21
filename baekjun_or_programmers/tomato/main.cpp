#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
vector<vector<int>> box;
int nx,ny;
int head[4] = {1,-1,0,0};
queue<pair<int, int>> q;
int cnt = 0;

int bfs(int x, int y){
	for(int i=0; i<4; i++){
		int ax=head[i]+x;
		int ay=head[3-i]+y;
		if(ax>=0 && ay>=0 && ax<nx && ay<ny && box[ax][ay]==0){
			q.push({ax,ay});
			box[ax][ay]=box[x][y]+1;
			cnt=max(box[ax][ay],cnt);
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
	ifs>> ny>>nx;
	box=vector<vector<int>>(nx);
	for(int i=0; i<nx; i++){
		for(int j=0; j<ny; j++){
			int k=0;
			ifs >> k;
			box[i].push_back(k);
			if(k==1){
				q.push({i,j});
				flag_one=true;}
			if(k==0) flag_zero=true;
			
		}
	}
			
	if(!flag_zero){cout << 0 <<endl; return 0;}
	else if(!flag_one){cout << -1 << endl; return 0;}
	else{
		while(!q.empty()){
			int bx =q.front().first;
			int by =q.front().second;
			q.pop();
			day=bfs(bx, by);
			max_day=max(max_day, day);
		}
	}
	for(int i=0; i<nx; i++)
		for(int j=0; j<ny; j++)
			if(box[i][j]==0){
				cout <<-1<<endl;
				return 0;
			}
	cout << max_day-1<<endl;
	//for(auto &bo:box){for(auto &b:bo)cout<<b<<" "; cout<<endl;}
	return 0;
}