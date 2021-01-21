#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
int max_element(queue<int> qu){
    int maxe=0;
    for(int i=0; i<qu.size(); i++){
        int comp=qu.front();
        qu.pop();
        qu.push(comp);
        if(comp>maxe) maxe=comp;
    }
    return maxe;
}

int solution(vector<int> prio, int location) {
    int answer = 0;
    queue<int> q;
    bool flag= true;

    int max = *max_element(prio.begin(), prio.end());
    int my = prio[location];
    for(auto &p:prio) q.push(p);

    int cnt=0;
    int idx=location;
    while(q.size()){
        //cout<<q.front() <<" "<< q.back()<<endl;
        if(max==my){
            int j=idx;
            for(int i=0; i<j; i++){
                int f=q.front();
                q.pop();
                if(f!=my)idx--;
            }
            cnt+=(idx+1);
            break;
        }
        if(max>q.front()){
            int vl=q.front();
            q.pop();
            q.push(vl);
        }
        else{
            q.pop();
            cnt++;
            max = max_element(q);
        }
        idx--;
        if(idx<0)idx=q.size()+idx;
        //cout << idx<<endl;
    }
    //cout <<cnt<<endl;
    return cnt;
}

int main(){
    vector<int> prio={2,1,3,1};
    int cnt = solution(prio,0);
    cout << cnt;
}