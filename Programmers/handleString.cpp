//프로그래머스 문자열 다루기 기본 문제풀이
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int len=s.length();
    
    if(len==4||len==6){
        for(int i=0;i<len;i++){
            if(s[i]<'0'||s[i]>'9'){
                answer=false;
                break;
            }
        }
    }
    else{
        answer=false;
    }
    return answer;
}
