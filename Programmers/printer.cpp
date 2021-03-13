//프로그래머스 프린터 문제
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }

    while(!q.empty()){
        int val = q.front().first;
        int idx = q.front().second;
        q.pop();

        if(pq.top() == val){
            pq.pop();
            answer++;

            if(idx == location){
                break;
            }
        } else{
            q.push(make_pair(val, idx));
        }
    }

    return answer;
}
