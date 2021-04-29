//프로그래머스 Level2 N개의 최소공배수 문제풀이
#include <string>
#include <vector>

using namespace std;
int gcd(int p, int q){
    if(q == 0){
        return p;
    } else{
        return gcd(q, p%q);
    }
}

int lcm(int p, int q){
    return p*q / gcd(p,q);
}

int solution(vector<int> arr) {
    int answer = 1;

    for(int i=0;i<arr.size();i++){
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
