//프로그래머스 Level2 가장 큰 수 문제풀이
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    string c = a+b;
    string d = b+a;

    return c.compare(d)>0;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;

    for(int i=0;i<numbers.size();i++){
        string num = to_string(numbers[i]);
        temp.push_back(num);
    }

    sort(temp.begin(), temp.end(), cmp);

    if(temp[0] == "0"){
        return "0";
    }

    for(int i=0;i<temp.size();i++){
        answer += temp[i];
    }

    return answer;
}

