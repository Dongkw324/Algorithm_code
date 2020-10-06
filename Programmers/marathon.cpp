//프로그래머스 완주하지 못한 선수
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> marathon;
   
    for(string person:participant){
        marathon[person]++;
    }
    
    for(string person:completion){
        marathon[person]--;
    }
    
    for(auto result:marathon){
        if(result.second>0){
            answer=result.first;
            break;
        }
    }
    return answer;
}
