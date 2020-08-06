#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX_SIZE 25
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
vector<int> house;
int cnt;
int n;

void dfs(int x,int y)
{
	visited[x][y]=true;
	cnt++;

	for(int i=0;i<4;i++)
	{
		int nextX=x+dirX[i];
		int nextY=y+dirY[i];

		if(nextX>=0&&nextX<n&&nextY>=0&&nextY<n)
		{
			if(!visited[nextX][nextY]&&map[nextX][nextY]==1)
			{
				dfs(nextX,nextY);
			}
		}
	}
}
				
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

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
				cnt=0;
				dfs(row,col);
				house.push_back(cnt);
			}
		}
	}

	sort(house.begin(),house.end());

	cout<<house.size()<<'\n';

	for(int i=0;i<house.size();i++)
	{
		cout<<house[i]<<'\n';
	}

	return 0;
}

