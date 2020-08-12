#include <iostream>
#include <queue>
#define MAX_SIZE 101
using namespace std;

int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int dirX[6]={-1,1,0,0,0,0};
int dirY[6]={0,0,-1,1,0,0};
int dirZ[6]={0,0,0,0,-1,1};
queue<pair<pair<int,int>,int> > q;

int m,n,h;

void bfs()
{
	while(!q.empty()){
		int curZ=q.front().first.first;
		int curY=q.front().first.second;
		int curX=q.front().second;
		q.pop();

		for(int i=0;i<6;i++){
			int nz=curZ+dirZ[i];
			int ny=curY+dirY[i];
			int nx=curX+dirX[i];

			if(nz>=0&&nz<h&&ny>=0&&ny<n&&nx>=0&&nx<m){
				if(map[nz][ny][nx]==0){
					map[nz][ny][nx]=map[curZ][curY][curX]+1;
					q.push(make_pair(make_pair(nz,ny),nx));
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

	cin>>m>>n>>h;

	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>map[i][j][k];
				if(map[i][j][k]==1){
					q.push(make_pair(make_pair(i,j),k));
				}
			}
		}
	}

	bfs();
	
	int days=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(map[i][j][k]==0){
					cout<<-1<<'\n';
					return 0;
				}

				if(days<map[i][j][k]){
					days=map[i][j][k];
				}
			}
		}
	}

	cout<<days-1<<'\n';

	return 0;
}
