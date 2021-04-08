//프로그래머스 Level2 H-Index 문제풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    while(answer < citations.size()){
        if(answer >= citations[answer]){
            break;
        }
        answer++;
    }
    
    return answer;
}
