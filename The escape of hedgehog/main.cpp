#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
vector<vector<int>> map;
queue<pair<int,int>> water_q;
queue<pair<int,int>> hedge_q;
int head[4]={1,-1,0,0};
int nx,ny;

int find_water(pair<int,int> p){
	int x=p.first;
	int y=p.second;
	for(int i=0; i<4; i++){
		int wx=x+head[i];
		int wy=y+head[3-i];
		if(wx>=0&& wy>=0 && wx<nx&& wy<ny){
			if(map[wx][wy]!=3 && map[wx][wy]!=4 && map[wx][wy]!=2){
				map[wx][wy]=2;
				water_q.push({wx,wy});
			}
		}
	}
	return 0;
}

int find_hedge(pair<int,int> p){
	int x=p.first;
	int y=p.second;
	for(int i=0; i<4; i++){
		int wx=x+head[i];
		int wy=y+head[3-i];
		if(wx>=0&& wy>=0 && wx<nx&& wy<ny){
			if(map[wx][wy]==3){
				return 1;
			}
			if(map[wx][wy]==0){
				map[wx][wy]=1;
				hedge_q.push({wx,wy});
			}
		}
	}
	return 0;
}

int main(){
	ifstream ifs("input.txt");
	ifs>>nx>>ny;
	map=vector<vector<int>>(nx, vector<int>(0));
	pair<int,int> start;
	for(int i=0; i<nx; i++){
		for(int j=0; j<ny; j++){
			char ch;
			ifs>>ch;
			switch(ch){
				case '.': map[i].push_back(0); break;
				case 'S': 
					map[i].push_back(1); 
					hedge_q.push({i,j});
					break; 
				case 'D': map[i].push_back(3); break;
				case '*': 
					map[i].push_back(2); 
					water_q.push({i,j});
					break;
				case 'X': map[i].push_back(4); break;
				default: exit(0); break;

			}
		}
	}

	int flag=0;
	int fail=0;
	int cnt=0;
	while(1){
		int size=water_q.size();
		while(size--){
			pair<int,int> w=water_q.front();
			water_q.pop();
			find_water(w);
		}
		size=hedge_q.size();
		cnt++;
		while(size--){
			pair<int,int> w=hedge_q.front();
			hedge_q.pop();
			flag=find_hedge(w);
			if(flag){cout <<cnt<<endl; exit(0);}
			for(auto &ma:map){for(auto &m:ma)cout<<m<<" ";cout << endl;} cout << endl;
		}
		if(hedge_q.size()==0){cout <<"KAKTUS"<<endl; break;}
	}
	return 0;
}