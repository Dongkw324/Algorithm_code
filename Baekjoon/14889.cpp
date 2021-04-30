//백준 14889 스타트와 링크 문제풀이
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX 101
using namespace std;

bool visited[MAX] = {false,};
int S[MAX][MAX];
int n, res = 99999999;

void dfs(int cnt, int cur)
{
        if(cnt == n/2){
                int start = 0;
                int link = 0;

                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                if(visited[i] && visited[j])
                                        start += S[i][j];
                                else if(!visited[i] && !visited[j])
                                        link += S[i][j];
                        }
                }
                int tmp = abs(start-link);
                res = (res<tmp) ? res : tmp;
                return;
        }

        for(int i=cur;i<n-1;i++){
                visited[i] = true;
                dfs(cnt+1, i+1);
                visited[i] = false;
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin>>n;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        cin>>S[i][j];
                }
        }

        dfs(0,0);
        cout<<res<<'\n';
}
