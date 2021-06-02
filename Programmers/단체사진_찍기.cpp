//프로그래머스 Level2 단체사진 찍기 문제풀이
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A','C','F','J','M','N','R','T'};
    do{
        bool flag = true;
        for(int i=0;i<data.size();i++){
            char firstFriend = data[i][0];
            char secondFriend = data[i][2];
            char opt = data[i][3];
            int wantDist = data[i][4]-'0'+1;
            int idx1, idx2, dist;

            for(int j=0;j<8;j++){
                if(friends[j] == firstFriend)
                    idx1 = j;
                if(friends[j] == secondFriend)
                    idx2 = j;
            }
            dist = abs(idx1-idx2);

            switch(opt){
                case '=':
                    if(dist != wantDist)
                        flag = false;
                    break;
                case '>':
                    if(dist <= wantDist)
                        flag = false;
                    break;
                case '<':
                    if(dist >= wantDist)
                        flag = false;
                    break;
            }
            if(!flag)
                break;
        }
        if(flag)
            answer++;
    }while(next_permutation(friends.begin(), friends.end()));
    return answer;
}
