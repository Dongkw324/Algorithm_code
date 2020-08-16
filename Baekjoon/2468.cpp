#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
queue<pair<int,int>> q;
int N;

void bfs(int col,int row,int height)
{
	visited[col][row]=true;
	q.push(make_pair(col,row));
	
	while(!q.empty()){
		int curY=q.front().first;
		int curX=q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int ny=curY+dirY[i];
			int nx=curX+dirX[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N){
				if(!visited[ny][nx]&&map[ny][nx]>height){
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

	cin>>N;
	
	int result=0;
	int max_height=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			max_height=max(max_height,map[i][j]);
		}
	}
	
	for(int i=0;i<max_height;i++){
		memset(visited,false,sizeof(visited));
		int mCnt=0;
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(!visited[j][k]&&map[j][k]>i){
					mCnt++;
					bfs(j,k,i);
				}
			}
		}
		result=max(mCnt,result);	
	}

	cout<<result<<'\n';
	return 0;
}
