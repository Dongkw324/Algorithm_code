//프로그래머스 Level1 소수 만들기 문제풀이
#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num){
    for(int i=2;i<=num;i++){
        if(num%i == 0){
            if(num != i){
                return false;
            }
        }
    }
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(isPrime(nums[i]+nums[j]+nums[k])){
                    answer++;
                }
            }
        }
    }

    return answer;
}
