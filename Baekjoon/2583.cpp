#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;

vector<int> result;
int paper[MAX_SIZE][MAX_SIZE]={0,};
bool visited[MAX_SIZE][MAX_SIZE]={false,};
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
int M,N,K;

int bfs(int y,int x)
{
	int cnt=1;
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

			if(ny>=0&&ny<M&&nx>=0&&nx<N){
				if(!visited[ny][nx]&&paper[ny][nx]==0){
					cnt++;
					visited[ny][nx]=true;
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
	return cnt;
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
				result.push_back(bfs(i,j));
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


