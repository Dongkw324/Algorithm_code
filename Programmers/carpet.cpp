//프로그래머스 Level2 카펫 문제풀이
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int len = brown + yellow;
    int row, col;
    for(int i=len;i>=1;i--){
        if(len%i == 0){
            row = i;
            col = len/i;
            
            int num = (row-2) * (col-2);
            if(num == yellow){
                break;
            }
        }
    }
    answer.push_back(row);
    answer.push_back(col);
    return answer;
}
