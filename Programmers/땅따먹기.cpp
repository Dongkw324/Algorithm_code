//프로그래머스 Level2 땅따먹기 문제풀이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    for(int i=0;i<len-1;i++){
        land[i+1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i+1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i+1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i+1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }

    answer = max({land[len-1][0], land[len-1][1], land[len-1][2], land[len-1][3]});
    return answer;
}
