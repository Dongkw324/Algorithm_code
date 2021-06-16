//프로그래머스 Level2 튜플 문제풀이
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> num;
    string tmp = "";

    for(int i=2;i<=s.length()-2;i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp += s[i];
        } else{
            if(tmp != ""){
                num[stoi(tmp)]++;
                tmp = "";
            }
        }
    }

    answer.resize(num.size());

    for(auto it=num.begin();it!=num.end();it++){
        answer[it->second-1] = it->first;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
