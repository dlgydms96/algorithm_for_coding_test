#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
vector<vector<int> > tr_map;
vector<vector<int> > check;
queue<pair<int,int>> q;
int x,y,cnt,cx,cy, len_max=0, cnt_max=0;
int head[4]={1,-1, 0, 0};
int bfs(int i, int j){
	for(int k=0; k<4; k++){
		int nx=i+head[k];
		int ny=j+head[3-k];

		if(nx<x && ny<y && nx>=0 && ny>=0 && check[nx][ny]==0 && tr_map[nx][ny]==1){
			check[nx][ny]=check[i][j]+1;
			len_max=max(len_max, check[nx][ny]);
			q.push({nx,ny});
		}
	}
	while(!q.empty()){
		pair<int,int> next=q.front();
		q.pop();
		bfs(next.first, next.second);
	}
	return len_max;
}

int main() {
    ifstream ifs ("input.txt");

	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	ifs >> x >> y;
	tr_map=vector<vector<int>>(x);
	for(int i=0; i<x; i++) {
		string line;
		ifs >> line;
		for(int j=0; j<y; j++){
			int area=0;
			if(line[j]=='L')area=1;
			tr_map[i].push_back(area);
		}
	}
	int path=0;
	for(cx=0; cx<x; cx++){
		for(cy=0; cy<y; cy++){
			cnt=0;
			if(tr_map[cx][cy]){
				check=vector<vector<int>>(x,vector<int>(y,0));
				check[cx][cy]=1;
				q.push({cx,cy});
				int len = bfs(cx,cy);
				path = max(path, len);
			}
		}
	}
	cout<<path-1<<endl;
	return 0;
}