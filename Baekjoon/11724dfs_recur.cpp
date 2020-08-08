#include <iostream>
#include <vector>
#define N 1001
using namespace std;

vector<int> map[N];
bool visited[N]={false,};

void dfs(int v)
{
	visited[v]=true;

	for(int i=0;i<map[v].size();i++)
	{
		int next=map[v][i];
		if(!visited[next]){
			dfs(next);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	
	int cnt=0;

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}

	cout<<cnt<<'\n';
	return 0;
}
