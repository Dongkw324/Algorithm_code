//프로그래머스 Level2 소수찾기 문제풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i=2;i<=num;i++){
        int res = num%i;
        if(res==0){
            if(num==i)
                return true;
            else
                return false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<int> element;
    
    for(int i=0;i<numbers.length();i++){
        element.push_back(numbers[i]-'0');
    }
    sort(element.begin(), element.end());
    
    vector<int> num;
    
    do{
        int temp = 0;
        for(int i=0;i<element.size();i++){
            temp = temp * 10 + element[i];
            num.push_back(temp);
        }
    }while(next_permutation(element.begin(), element.end()));
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    for(auto i:num){
        if(isPrime(i)){
            answer++;
        }
    }
    
    return answer;
}
