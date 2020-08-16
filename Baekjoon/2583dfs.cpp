#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;

int M,N,K;
int paper[MAX_SIZE][MAX_SIZE]={0,};
bool visited[MAX_SIZE][MAX_SIZE]={false,};
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
vector<int> result;
int cnt=0;

void dfs(int y,int x)
{
	visited[y][x]=true;
	cnt++;
	
	for(int i=0;i<4;i++){
		int ny=y+dirY[i];
		int nx=x+dirX[i];

		if(ny>=0&&ny<M&&nx>=0&&nx<N){
			if(!visited[ny][nx]&&paper[ny][nx]==0){
				dfs(ny,nx);
			}
		}
	}
}
	
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>M>>N>>K;

	while(K--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		for(int i=y1;i<y2;i++){
			for(int j=x1;j<x2;j++){
				paper[i][j]=1;
			}
		}
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]&&paper[i][j]==0){
				cnt=0;
				dfs(i,j);
				result.push_back(cnt);
			}
		}
	}
	
	sort(result.begin(),result.end());

	cout<<result.size()<<'\n';

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<'\n';
	return 0;
}


