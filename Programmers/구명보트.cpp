//프로그래머스 Level2 구명보트 문제풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, cnt = 0;
    int last = people.size()-1;
    sort(people.begin(), people.end());

    while(cnt<=last){
        if(people[cnt]+people[last] <= limit){
            cnt++;
            last--;
        }
        else{
            last--;
        }
        answer++;
    }
    return answer;
}
