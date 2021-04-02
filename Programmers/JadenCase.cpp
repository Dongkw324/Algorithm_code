//프로그래머스 Level2 JadenCase 문자열 만들기 문제풀이
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        
        if(i==0 || s[i-1]==' '){
            if(s[i]>='a'&&s[i]<'z'){
                s[i] = toupper(s[i]);
            }
        } else{
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] = tolower(s[i]);
            }
        }
        
    }
    answer = s;
    return answer;
}
