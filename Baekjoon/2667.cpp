#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define MAX_SIZE 25
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
vector<int> house_number;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};

int bfs(int x,int y,int n)
{
	visited[x][y]=true;
	int count=1;

	queue<pair<int,int> > q;
	q.push({x,y});

	while(!q.empty())
	{
		int curX=q.front().first;
		int curY=q.front().second;
		
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nextX=curX+dirX[i];
			int nextY=curY+dirY[i];
			if(nextX>=0&&nextX<n&&nextY>=0&&nextY<n)
			{
				if(!visited[nextX][nextY]&&map[nextX][nextY]==1)
				{
					count++;
					visited[nextX][nextY]=true;
					q.push({nextX,nextY});
				}
			}
		}
	}
	return count;
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	
	for(int row=0;row<n;row++)
	{
		string estate;
		cin>>estate;
		for(int col=0;col<n;col++)
		{
			map[row][col]=estate[col]-'0';
		}
	}

	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			if(!visited[row][col]&&map[row][col]==1)
			{
				house_number.push_back(bfs(row,col,n));
			}
		}
	}

	sort(house_number.begin(),house_number.end());

	cout<<house_number.size()<<'\n';

	for(int i=0;i<house_number.size();i++)
	{
		cout<<house_number[i]<<'\n';
	}

	return 0;
}

	
