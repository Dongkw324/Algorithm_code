//프로그래머스 Level2 오픈채팅방 문제풀이
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userAccount;
    string command, userId, userName;

    for(int i=0;i<record.size();i++){
        stringstream ss(record[i]);
        ss>>command;

        if(command=="Enter" || command=="Change"){
            ss>>userId;
            ss>>userName;
            userAccount[userId] = userName;
        }

        ss.clear();
    }

    for(int i=0;i<record.size();i++){
        stringstream ss(record[i]);
        ss>>command;
        ss>>userId;
        string name=userAccount[userId];

        if(command == "Enter"){
            answer.push_back(name+"님이 들어왔습니다.");
        } else if(command == "Leave"){
            answer.push_back(name+"님이 나갔습니다.");
        }
    }

    return answer;
}
