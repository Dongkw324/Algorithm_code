//프로그래머스 삼각 달팽이 문제풀이
#include <string>
#include <vector>
#define MAX_SIZE 1001
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int triangle[1001][1001] = {0, };
    int x = 0;
    int y = 0;
    int state = 0;
    int num = 1;
    
    for(int i=0;i<n;i++){
        switch(state){
            case 0:
                for(int j=i;j<n;j++){
                    triangle[x++][y]=num++;
                }
                state=1;
                x--;
                y++;
                break;
            case 1:
                for(int k=i;k<n;k++){
                    triangle[x][y++]=num++;
                }
                state=2;
                x--;
                y-=2;
                break;
            case 2:
                for(int l=i;l<n;l++){
                    triangle[x--][y--]=num++;
                }
                state=0;
                x+=2;
                y++;
                break;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(triangle[i][j]);
        }
    }
    return answer;
}
