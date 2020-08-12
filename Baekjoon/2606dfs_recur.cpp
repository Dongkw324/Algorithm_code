#include <iostream>
#include <vector>
#define MAX_SIZE 101
using namespace std;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE]={false,};
int cnt=0;

void dfs(int start)
{
	visited[start]=true;

	for(int i=0;i<graph[start].size();i++){
		int next=graph[start][i];

		if(!visited[next]){
			cnt++;
			dfs(next);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	int p;

	cin>>num;
	cin>>p;

	for(int i=0;i<p;i++){
		int from,to;
		cin>>from>>to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(1);
	
	cout<<cnt<<'\n';
	return 0;
}
