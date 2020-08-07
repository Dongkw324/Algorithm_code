#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 50
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
const int dirX[4]={-1,1,0,0};
const int dirY[4]={0,0,-1,1};
int m,n,k;

void bfs(int y,int x)
{
        queue<pair<int,int> > q;
        visited[y][x]=true;
        q.push(make_pair(y,x));

        while(!q.empty()){
                int curY=q.front().first;
                int curX=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                        int ny=curY+dirY[i];
                        int nx=curX+dirX[i];

                        if(nx>=0&&nx<m&&ny>=0&&ny<n){
                                if(!visited[ny][nx]&&map[ny][nx]==1){
                                        visited[ny][nx]=true;
                                        q.push(make_pair(ny,nx));
                                }
                        }
                }
        }
}

int main()
{
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int T;
        cin>>T;

        for(int i=0;i<T;i++)
        {
                cin>>m>>n>>k;
                int result=0;

                for(int cnt=0;cnt<k;cnt++){
                        int x,y;
                        cin>>x>>y;
                        map[y][x]=1;
                }

                for(int col=0;col<n;col++){
                        for(int row=0;row<m;row++){
                                if(map[col][row]==1&&!visited[col][row]){
                                        bfs(col,row);
                                        result++;
                                }
                        }
                }

                cout<<result<<'\n';

                //초기화 진행
                memset(visited,false,sizeof(visited));
                memset(map,0,sizeof(map));

        }

        return 0;
}

