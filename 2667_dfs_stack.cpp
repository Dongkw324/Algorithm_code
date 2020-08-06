#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX_SIZE 25
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]={false,};
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
vector<int> house;

int dfs(int x,int y,int n)
{
	int cnt=1;
	visited[x][y]=true;
	stack<pair<int,int> > st;
	st.push({x,y});

	while(!st.empty())
	{
		int curX=st.top().first;
		int curY=st.top().second;
		st.pop();

		for(int i=0;i<4;i++)
		{
			int nextX=curX+dirX[i];
			int nextY=curY+dirY[i];
			if(nextX>=0&&nextX<n&&nextY>=0&&nextY<n)
			{
				if(!visited[nextX][nextY]&&map[nextX][nextY]==1)
				{
					visited[nextX][nextY]=true;
					cnt++;
					st.push({nextX,nextY});
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
				house.push_back(dfs(row,col,n));
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
