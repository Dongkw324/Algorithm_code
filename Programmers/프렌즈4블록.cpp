//프로그래머스 Level2 [1차] 프렌즈4블록 문제풀이
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    
    while(flag){
        bool temp[30][30] = {false,};
        flag = false;
        
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j]=='0'){
                    continue;
                }
                char word = board[i][j];
                if(board[i+1][j] == word && board[i][j+1] == word && board[i+1][j+1] == word){
                    temp[i][j] = true;
                    temp[i+1][j] = true;
                    temp[i][j+1] = true;
                    temp[i+1][j+1] = true;
                    flag = true;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j] == true){
                    board[i][j]='0';
                    answer++;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='0'){
                    for(int k=i;k>0;k--){
                        if(board[k-1][j]=='0'){
                            break;
                        }
                        board[k][j] = board[k-1][j];
                        board[k-1][j]='0';
                    }
                }
            }
        }
    }
    return answer;
}
