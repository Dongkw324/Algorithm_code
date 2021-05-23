//프로그래머스 Level2 영어 끝말잇기 문제풀이
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    map<string, int> member;

    member[words[0]]++;
    char lastword = words[0].back();
    int len = words.size();

    for(int i=1;i<len;i++){
        if(member[words[i]] || lastword != words[i].front()){
            answer[0] = i%n+1;
            answer[1] = i/n+1;
            break;
        }
        lastword = words[i].back();
        member[words[i]]++;
    }
    return answer;
}
