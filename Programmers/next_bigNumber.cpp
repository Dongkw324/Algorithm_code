//프로그래머스 Level2 다음 큰 숫자 문제풀이
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int getNum(int num){
    bitset<32> tmp(num);
    return tmp.count();
}

int solution(int n) {
    int answer = n;
    answer++;

    while(true){
        if(getNum(n) == getNum(answer)){
            break;
        }
        answer++;
    }
    return answer;
}
