//프로그래머스 Level2 n진수 게임 문제풀이
#include <string>
#include <vector>

using namespace std;

string base(int num, int n){
    string baseNum="";
    string nbase[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

    while(num/n != 0){
        baseNum = nbase[num%n] + baseNum;
        num/=n;
    }
    baseNum = nbase[num%n] + baseNum;
    return baseNum;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int cnt = 0;

    for(int i=0;i<t*m;i++){
        temp += base(i,n);
    }

    for(int i=0;i<temp.length();i++){
        if(cnt == t){
            break;
        }

        if(i == p-1){
            answer += temp[i];
            p += m;
            cnt++;
        }

    }
    return answer;
}
