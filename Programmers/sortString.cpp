//프로그래머스 문자열 내 마음대로 정렬하기 문제풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int index;

bool comp(string a,string b){
    if(a[index]==b[index]){
        return a<b;
    }else
        return a[index]<b[index];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index=n;
    sort(strings.begin(),strings.end(),comp);
    
    answer=strings;
    return answer;
}
