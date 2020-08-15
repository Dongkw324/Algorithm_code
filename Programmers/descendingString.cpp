//프로그래머스 문자열 내림차순으로 배치하기 문제풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    answer=s;

    sort(answer.begin(),answer.end(),greater<char>());
    return answer;
}
