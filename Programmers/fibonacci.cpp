//프로그래머스 Level2 피보나치 수 문제풀이
#include <string>
#include <vector>

using namespace std;
const int MAX = 100001;
const int MOD = 1234567;
int F[MAX];

int solution(int n) {
    int answer = 0;
    F[0] = 0;
    F[1] = 1;

    for(int i=2;i<=n;i++){
        F[i] = (F[i-1] + F[i-2]) % MOD;
    }
    answer = F[n];
    return answer;
}
