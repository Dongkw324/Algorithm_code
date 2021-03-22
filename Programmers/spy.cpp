//프로그래머스 Level2 위장 문제풀이
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> spy;

    for(auto c:clothes){
        spy[c[1]]++;
    }

    map<string, int>::iterator it;

    for(it=spy.begin();it!=spy.end();it++){
        answer *= it->second+1;
    }

    return answer-1;
}
