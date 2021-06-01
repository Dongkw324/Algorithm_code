//프로그래머스 Level2 멀쩡한 사각형 문제풀이
using namespace std;

long long gcd(long long w,long long h){
    if(h == 0)
        return w;
    else
        return gcd(h, w%h);
}

long long solution(int w,int h) {
    long long answer = 1;
    long long we = w;
    long long he = h;
    answer = (we*he)-(we+he-gcd(we,he));
    return answer;
}
