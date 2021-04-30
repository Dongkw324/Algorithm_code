//백준 1182번 부분수열의 합 문제풀이
#include <iostream>
using namespace std;

const int MAX_CNT = 20;

int n, s;
int num[MAX_CNT];
int cnt = 0;

void dfs(int sum, int depth)
{
        if(depth == n){
                return;
        }

        if(sum + num[depth] == s){
                cnt++;
        }

        dfs(sum + num[depth], depth+1);
        dfs(sum, depth+1);
}

int main()
{
        cin>>n>>s;

        for(int i=0;i<n;i++){
                cin>>num[i];
        }

        dfs(0,0);

        cout<<cnt<<'\n';
        return 0;
}
