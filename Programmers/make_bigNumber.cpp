//프로그래머스 Level2 큰 수 만들기 문제풀이
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length()-k;
    int cur = 0;

    for(int i=0;i<len;i++){
        char num = number[cur];
        int idx = cur;
        for(int j=idx;j<=k+i;j++){
            if(num < number[j]){
                num = number[j];
                idx = j;
            }
        }
        cur = idx+1;
        answer += num;
    }
    return answer;
}
