//프로그래머스 Level1 음양 더하기 문제풀이
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i=0;i<signs.size();i++){
        if(!signs[i]){
            answer += (-absolutes[i]);
        } else{
            answer += absolutes[i];
        }
    }
    return answer;
}
