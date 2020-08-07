#include <iostream>
#include <stack>
#include <cstring>
#define MAX_SIZE 50
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
const int dirX[4]={-1,1,0,0};
const int dirY[4]={0,0,-1,1};
int m,n,k;

void dfs(int y,int x)
{
	visited[y][x]=true;
	stack<pair<int,int> > st;
	
	st.push(make_pair(y,x));

	while(!st.empty()){
		int curY=st.top().first;
		int curX=st.top().second;
		st.pop();

		for(int i=0;i<4;i++){
			int ny=curY+dirY[i];
			int nx=curX+dirX[i];
			
			if(ny>=0&&ny<n&&nx>=0&&nx<m){
				if(!visited[ny][nx]&&map[ny][nx]==1){
					visited[ny][nx]=true;
					st.push(make_pair(ny,nx));
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

	while(T--)
	{
		cin>>m>>n>>k;
		int result=0;

		for(int i=0;i<k;i++){
			int x,y;
			cin>>x>>y;
			map[y][x]=1;
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==1&&!visited[i][j]){
					dfs(i,j);
					result++;
				}
			}
		}

		cout<<result<<'\n';
		memset(map,0,sizeof(map));
		memset(visited,false,sizeof(visited));
	}

	return 0;
}

