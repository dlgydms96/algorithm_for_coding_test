#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
vector<vector<int> > conn;
queue<int> q;

int bfs(int com){
	vector<int> check(com+1,0);
	int cnt=0;
	int curr =1;
	q.push(curr);
	while(q.size()){
		check[curr] = 1;
		for(auto &c:conn[curr]) q.push(c);
		while(check[q.front()]) {
			if(q.size()==1)return cnt;
			q.pop();
		}
		curr=q.front();
		cnt++;
		q.pop();
	}
	return cnt;
}

int main() {
    ifstream ifs ("input.txt");

	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int com, pair;
	ifs >> com >> pair;
	conn.resize(com + 1);
	for(int i=0; i<pair; i++) {
		int x, y;
		ifs >> x >> y;
		conn[y].push_back(x);
		conn[x].push_back(y);
	}
	int res = bfs(com);
	cout << res<<endl;
	return 0;
}