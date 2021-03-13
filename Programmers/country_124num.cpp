//프로그래머스 125나라의 숫자 문제
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    const string num[3] = {"4", "1", "2"};

    while(n){
        int mod = n%3;
        n = n/3;

        answer.insert(0, num[mod]);
        if(mod == 0){
            n -= 1;
        }
    }
    return answer;
}
