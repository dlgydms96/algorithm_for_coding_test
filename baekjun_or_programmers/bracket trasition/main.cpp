
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string sep_str(string s){
    int cnt=0;
    bool minus=false;
    string u="",v="";
    if(!s.length()) return s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        if(cnt<0) minus=true;
        if(i==s.length()-1 && !minus) return s;
        if(cnt==0){
            u=s.substr(0,i+1);
            v=s.substr(i+1);
            break;
        }
    }
    v=sep_str(v);
    if(minus){
        u.erase(0,1);
        u.erase(u.length()-1);
        for(int i=0; i<u.length(); i++)
        {
            if(u[i]=='(') u[i]=')';
            else u[i]='(';
        }
        return "("+v+")"+u;
    }
    return u+v;
}

string solution(string p) {
    string answer = "";
    answer=sep_str(p);    
    return answer;
}

int main(){
    string result=solution("()))((()");
    cout <<result<<endl;
    return 0;
}