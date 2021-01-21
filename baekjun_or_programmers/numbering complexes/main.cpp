#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int>> conn;
queue<pair<int,int>> q;
vector<vector<int>> check;
int com;
int home;
void bfs(int i, int j, int cnt){
	if(check[i][j]==1) return;
	//cout << i<< " "<<j<<endl;
	//cout <<conn[i][j]<<endl;
	home++;
	check[i][j]=1;
	conn[i][j]=cnt;
	//for(auto &cn:check){for(auto &c:cn)cout<<c<<" "; cout<<endl;} cout<<endl;
	int next=i-1;
	if(next>=0 && conn[next][j]==1) q.push({next,j});
	next=i+1;
	if(next<com && conn[next][j]==1) q.push({next,j});
	next=j-1;
	if(next>=0 && conn[i][next]==1) q.push({i,next});
	next=j+1;
	if(next<com && conn[i][next]==1) q.push({i,next});
	
	while(q.size()){
		int f=q.front().first;
		int s=q.front().second;
		q.pop();
		//cout << f<<s<<endl;
		bfs(f,s, cnt);
	}
	return;
}

int main() {
    ifstream ifs ("input.txt");
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ifs >> com;
	check=vector<vector<int>>(com,vector<int>(com,0));
	vector<int> answer(1,0);
	conn.resize(com + 1);	
	for(int i=0; i<com; i++) {
		string val;
		ifs >> val;
		for(int j=0; j<com; j++) {
			string a=val.substr(j,1);
			int b=stoi(a.c_str());
			conn[i].push_back(b);
		}
	}
	int cnt=0;
	for(int i=0; i<com; i++){
		for(int j=0; j<com; j++){
			if(conn[i][j]==1 && check[i][j]==0){
				home=0;
				bfs(i, j, cnt+2);
				answer.push_back(home);
				cnt++;
			}
		}
	}
	//for(auto &cn:conn){for(auto &c:cn)cout<<c<<" "; cout<<endl;}
	sort(answer.begin(),answer.end());
	answer[0]=cnt;
	for(auto &a:answer)cout <<a<<endl;
	return 0;
}