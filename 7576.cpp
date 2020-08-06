#include <iostream>
#include <queue>
#define MAX_SIZE 1005
using namespace std;

int n,m;
int box[MAX_SIZE][MAX_SIZE];
queue<pair<int,int> > q;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};

void bfs()
{
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int ny=y+dirY[i];
			int nx=x+dirX[i];
			if(ny<0||ny>=n||nx<0||nx>=m)
				continue;

			if(box[ny][nx]==0){
				box[ny][nx]=box[y][x]+1;
				q.push({ny,nx});
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin>>m>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>box[i][j];
			if(box[i][j]==1)
				q.push({i,j});
		}
	}

	bfs();

	int days=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(box[i][j]==0){
				cout<<-1<<'\n';
				return 0;
			}
			
			if(days<box[i][j])
				days=box[i][j];
		}
	}

	cout<<days-1<<'\n';
	return 0;
}

			
