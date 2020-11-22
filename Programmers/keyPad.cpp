//프로그래머스 키패드 누르기 문제풀이
#include <string>
#include <vector>
using namespace std;

typedef struct Pos{
    int x,y;
}pos;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pos left,right;
    left.x=0, left.y=3, right.x=2, right.y=3;

    for(int i=0;i<numbers.size();i++){
         if(numbers[i]%3==0&&numbers[i]!=0){
              answer+="R";
              right.x=2;
              if(numbers[i]==3)
                  right.y=0;
              else if(numbers[i]==6)
                  right.y=1;
              else
                  right.y=2;
        }
        else if(numbers[i]%3==1){
              answer+="L";
              left.x=0;
              if(numbers[i]==1)
                  left.y=0;
              else if(numbers[i]==4)
                  left.y=1;
              else
                  left.y=2;
        }
        else{
              pos temp;
              temp.x=1;
              if(numbers[i]==2)
                  temp.y=0;
              else if(numbers[i]==5)
                  temp.y=1;
              else if(numbers[i]==8)
                  temp.y=2;
              else
                  temp.y=3;

              int left_distance=abs(left.x-temp.x)+abs(left.y-temp.y);
              int right_distance=abs(right.x-temp.x)+abs(right.y-temp.y);

              if(left_distance>right_distance){
                  answer+="R";
                  right.x=temp.x;
                  right.y=temp.y;
              }
              else if(left_distance<right_distance){
                  answer+="L";
                  left.x=temp.x;
                  left.y=temp.y;
              }
              else{
                  if(hand=="right"){
                      answer+="R";
                      right.x=temp.x;
                      right.y=temp.y;
                  }
                  else if(hand=="left"){
                      answer+="L";
                      left.x=temp.x;
                      left.y=temp.y;
                 }
             }
         }
     }

     return answer;
}`
