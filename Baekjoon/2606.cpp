#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 101
using namespace std;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE]={false,};
int cnt=0;

void bfs(int start)
{
	queue<int> q;
	visited[start]=true;
	q.push(start);

	while(!q.empty()){
		int cur=q.front();
		q.pop();

		for(int i=0;i<graph[cur].size();i++){
			int next=graph[cur][i];
			
			if(!visited[next]){
				visited[next]=true;
				q.push(next);
				cnt++;
			}
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

	bfs(1);
	
	cout<<cnt<<'\n';
	return 0;
}
