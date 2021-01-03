#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> nara={1,2,4};
    vector<int> list;
    int stand=0;
    int st=0;
    int mul=1;
    int cnt=0;
    while(stand<n){
        mul*=nara.size();
        st=stand;
        stand+=mul;
        cnt++;
    }
    //cout <<"최소 배수"<< st <<" 자리수"<<cnt<< endl;
    int diff=n-(st+1);
    int m=diff;
    int c=0;
    while(!(c==cnt)){    	
        int k=m%nara.size();
        m=m/nara.size();
        //cout << m<<" "<<k<< endl;
        list.push_back(k);
        //answer+=to_string(nara[k]);
        //cout << nara[k];
        c++;
    }
    for(int it=list.size()-1; it>=0; it--){
        answer+=to_string(nara[list[it]]);
    }
    return answer;
}

int main()
{
    string answer=solution(6);
    cout << answer<<endl;
}