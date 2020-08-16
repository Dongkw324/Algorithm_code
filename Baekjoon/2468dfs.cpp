#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
int N;

void dfs(int col,int row,int height)
{
	visited[col][row]=true;

	for(int i=0;i<4;i++){
		int ny=col+dirY[i];
		int nx=row+dirX[i];

		if(ny>=0&&ny<N&&nx>=0&&nx<N){
			if(!visited[ny][nx]&&map[ny][nx]>height){
				dfs(ny,nx,height);
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

	int max_height=0;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			max_height=max(max_height,map[i][j]);
		}
	}

	int result=0;

	for(int i=0;i<max_height;i++){
		memset(visited,false,sizeof(visited));
		int mCnt=0;
		
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(map[j][k]>i&&!visited[j][k]){
					mCnt++;
					dfs(j,k,i);
				}
			}
			result=max(result,mCnt);
		}
	}

	cout<<result<<'\n';
	return 0;
}
