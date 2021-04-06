//프로그래머스 Level2 최솟값 만들기 문제풀이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for(int i=0;i<A.size();i++){
        answer += (A[i]*B[i]);
    }

    return answer;
}
