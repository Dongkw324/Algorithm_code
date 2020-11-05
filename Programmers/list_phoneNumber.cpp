//프로그래머스 전화번호 목록 문제풀이
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> phone_number;

    for(int i=0;i<phone_book.size();i++){
        string num="";
        for(int j=0;j<phone_book[i].size();j++){
            num+=phone_book[i][j];
            phone_number[num]++;
        }
    }

    for(int i=0;i<phone_book.size();i++){
        if(phone_number[phone_book[i]]>1){
            answer=false;
            break;
        }
    }
    return answer;
}
