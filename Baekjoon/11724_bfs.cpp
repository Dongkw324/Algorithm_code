#include <iostream>
#include <vector>
#include <queue>
#define N 1000
using namespace std;

vector<int> map[N];
bool visited[N]={false,};

void bfs(int v)
{
        queue<int> q;

        q.push(v);
        visited[v]=true;

        while(!q.empty()){
                int cur=q.front();
                q.pop();

                for(int i=0;i<map[cur].size();i++){
                        int next=map[cur][i];

                        if(!visited[next]){
                                visited[next]=true;
                                q.push(next);
                        }
                }
        }

}

int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n,m;
        cin>>n>>m;

        int cnt=0;

        for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                map[u].push_back(v);
                map[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
                if(!visited[i]){
                        cnt++;
                        bfs(i);
                }
        }

        cout<<cnt<<'\n';
        return 0;
}

