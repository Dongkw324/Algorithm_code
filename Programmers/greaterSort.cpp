#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool com(char ch1,char ch2){
    if(ch1>ch2){
        return true;
    }
    else
        return false;
}
long long solution(long long n) {
    long long answer = 0;
    string temp="";
    temp=to_string(n);
    
    sort(temp.begin(),temp.end(),com);
    
    answer=stoll(temp);
    
    return answer;
}
