//프로그래머스 Level1 포켓몬 문제풀이
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size();

    vector<int> temp;
    temp = nums;

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int tmpSize = temp.size();

    answer = (tmpSize > size/2)?size/2:tmpSize;

    return answer;
}
