//프로그래머스 Level2 [1차]뉴스 클러스터링 문제풀이
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1, s2;
    
    transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c){return toupper(c);});
    
    transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c){return toupper(c);});
    
    for(int i=0;i<str1.length()-1;i++){
        if((str1[i]>='A'&&str1[i]<='Z') && (str1[i+1]>='A'&&str1[i+1]<='Z')){
            s1.push_back(str1.substr(i, 2));
            continue;
        }
    }
    
    for(int i=0;i<str2.length()-1;i++){
        if((str2[i]>='A'&&str2[i]<='Z') && (str2[i+1]>='A'&&str2[i+1]<='Z')){
            s2.push_back(str2.substr(i,2));
            continue;
        }
    }
    
    if(s1.size()==0 && s2.size()==0){
        answer = 65536;
    } else{
        int maxLen = s1.size()+s2.size();
        int minLen = 0;
        
        for(int i=0;i<s1.size();i++){
            auto it = find(s2.begin(), s2.end(), s1[i]);
            if(it != s2.end()){
                minLen++;
                s2.erase(it);
                continue;
            }
        }
        maxLen -= minLen;
        double n = (double)minLen / (double)maxLen;
        answer = n*65536;
    }
    return answer;
}
