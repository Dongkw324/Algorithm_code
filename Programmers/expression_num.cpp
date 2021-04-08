//프로그래머스 Level2 숫자의 표현 문제풀이
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=i;j<=n;j++){
            sum += j;
            if(sum == n){
                answer++;
                break;
            }
            else if(sum > n){
                break;
            }
        }
    }
    return answer;
}
