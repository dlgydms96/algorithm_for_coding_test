#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 1000;
    if(s.length()==1)return 1;
    for(int i=1; i<=s.length()/2; i++){
        int j=0;
        string front=s.substr(j,i);
        j+=i;
        int cnt=0;
        string res="";
        while(j<s.length()){
            string back=s.substr(j,i);
            if(front.compare(back)==0) cnt++;
            else {
                cnt++;
                if(cnt!=1)res+=(to_string(cnt)+front);
                else res+=front;
                front=back;
                cnt=0;
            }
            j+=i;
        }
        cnt++;
        if(cnt!=1)res+=(to_string(cnt)+front);
        else res+=front;
        int len= res.length();
        answer = min(answer, len);
    }
    return answer;
}

int main(){
    int a=solution("aaabbb");
    cout << a<<endl;
    return 0;
}