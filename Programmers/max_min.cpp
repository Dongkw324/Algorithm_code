//프로그래머스 Level2 최대값과 최소값 문제풀이
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp="";
    vector<int> nums;

    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            nums.push_back(stoi(temp));
            temp="";
        } else{
            temp += s[i];
        }
    }
    nums.push_back(stoi(temp));

    sort(nums.begin(), nums.end());

    int minNum = nums[0];
    int maxNum = nums[nums.size()-1];

    answer = to_string(minNum)+" "+to_string(maxNum);
    return answer;
}
