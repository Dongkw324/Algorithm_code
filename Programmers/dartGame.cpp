#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx=0;
    vector<int> score;

    for(int i=0;i<dartResult.length();i++){
        if(dartResult[i]=='S'||dartResult[i]=='D'||dartResult[i]=='T'||dartResult[i]=='*'||dartResult[i]=='#'){
            switch(dartResult[i]){
            case 'S':
                break;
            case 'D':
                score[idx-1]=score[idx-1]*score[idx-1];
                break;
            case 'T':
                score[idx-1]=score[idx-1]*score[idx-1]*score[idx-1];
                break;
            case '*':
                score[idx-1]=score[idx-1]*2;
                if(idx>1){
                    score[idx-2]=score[idx-2]*2;
                }
                break;
            case '#':
                    score[idx-1]=-score[idx-1];
                    break;
        }
        }
        else{
            if(dartResult[i]=='1'&&dartResult[i+1]=='0'){
                score.push_back(10);
                i++;
            }
            else{
                score.push_back(dartResult[i]-'0');
            }
            idx++;
        }
    }

    for(int i=0;i<score.size();i++){
        answer+=score[i];
    }
    return answer;
}

