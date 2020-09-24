//프로그래머스 스티커 모으기 문제풀이 코드
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100001
using namespace std;

int dp[MAX_SIZE];

int solution(vector<int> sticker)
{
    int answer;
    int n=sticker.size();

    if(n==1){
        return sticker[0];
    }

    dp[0]=sticker[0];
    dp[1]=sticker[0];

    for(int i=2;i<n-1;i++){
        dp[i]=max(dp[i-1],sticker[i]+dp[i-2]);
    }
    answer=dp[n-2];

    dp[0]=0;
    dp[1]=sticker[1];

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],sticker[i]+dp[i-2]);
    }

    answer=max(answer,dp[n-1]);
    return answer;
}
