//프로그래머스 Level2 다리를 지나는 트럭 문제풀이
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;

    queue<int> q;
    while(true){
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }

        answer++;
        int w = truck_weights[idx];

        if(bridge_length == q.size()){
            sum -= q.front();
            q.pop();
        }

        if(sum+w <= weight){
            q.push(w);
            sum += w;
            idx++;
        } else{
            q.push(0);
        }
    }
    return answer;
}
